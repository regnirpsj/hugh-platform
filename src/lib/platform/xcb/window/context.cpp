// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/context.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/xcb/window/context.hpp"

// includes, system

#include <array>                  // std::array<>
#include <algorithm>              // std:;find<>
#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <condition_variable>     // std::condition_variable
#include <cstdlib>                // ::getenv
#include <glm/gtx/io.hpp>         // glm::operator<<  (field::container::print_on)
#include <sstream>                // std::ostringstream
#include <stdexcept>              // std::runtime_error
#include <xcb/xcb_event.h>        // XCB_EVENT_RESPONSE_TYPE, ::xcb_event_get_label

// includes, project

#include <hugh/platform/xcb/io.hpp>
#include <hugh/support/io_utils.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  std::string const env_dpy_name (::getenv("DISPLAY"));
  std::string const dflt_dpy_name(":0");
  
  // functions, internal

} // namespace {

namespace hugh {

  namespace platform {

    namespace xcb {

      namespace window {
        
        // variables, exported

        /* static */ std::string const context::dflt_display_name((!env_dpy_name.empty()) ?
                                                                  env_dpy_name :
                                                                  dflt_dpy_name);
        
        // functions, exported

        /* explicit */
        context::context(std::string const& a, rect const& b, std::string const& c)
          : support::printable    (),
            title_                (a),
            position_             (glm::uvec2((0 > b.x) ? 0 : b.x,
                                              (0 > b.y) ? 0 : b.y)),
            size_                 (glm::uvec2((1 > b.w) ? 1 : b.w,
                                              (1 > b.h) ? 1 : b.h)),
            connection_           (nullptr),
            screen_               (nullptr),
            window_               (0),
            gcontext_             (0),
            handler_map_          (),
            handler_map_mutex_    (),
            event_listener_       (nullptr),
            event_listener_active_(false)
        {
          TRACE("hugh::platform::xcb::window::context::context");

          if (!c.empty()) {                                              // try requested display
            connection_ = ::xcb_connect(c.c_str(), nullptr);
          }

          if (!connection_ || ::xcb_connection_has_error(connection_)) { // try default display
            connection_ = ::xcb_connect(nullptr, nullptr);
          }

          if (::xcb_connection_has_error(connection_)) {
            std::ostringstream ostr;

            ostr << "hugh::platform::xcb::window::context: "
                 << "connecting to '"
                 << c
                 << "' failed!";

            throw std::runtime_error(ostr.str());
          }

          event_listener_.reset(new std::thread(std::bind(&context::event_listener_loop, this)));
          event_listener_active_ = true;

          screen_ = ::xcb_setup_roots_iterator(::xcb_get_setup(connection_)).data;
          window_ = ::xcb_generate_id(connection_);

          {
            uint32_t const mask(XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK);
            uint32_t const values[2] = {
              screen_->white_pixel,
              XCB_EVENT_MASK_PROPERTY_CHANGE
            };
            uint32_t const wclass(XCB_WINDOW_CLASS_INPUT_OUTPUT);

            xcb_void_cookie_t const cookie(::xcb_create_window_checked(connection_,
                                                                       XCB_COPY_FROM_PARENT,
                                                                       window_,
                                                                       screen_->root,
                                                                       position_.x, position_.y,
                                                                       size_.x, size_.y,
                                                                       1,
                                                                       wclass,
                                                                       screen_->root_visual,
                                                                       mask, values));
            xcb_generic_error_t*    error (::xcb_request_check(connection_, cookie));

            if (error) {
              std::ostringstream ostr;

              ostr << "hugh::platform::xcb::window::context: "
                   << "creating window on '"
                   << c
                   << "' failed! (error: "
                   << error->error_code
                   << ')';

              ::free(error);
              
              throw std::runtime_error(ostr.str());
            }

            title(title_);
          }

          gcontext_ = ::xcb_generate_id(connection_);

          {
            uint32_t const mask(XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES);
            uint32_t const values[2] = {
              screen_->black_pixel,
              0,
            };

            ::xcb_create_gc(connection_,
                            gcontext_,
                            window_,
                            mask,
                            values);
          }

          {
            xcb_void_cookie_t const cookie(::xcb_map_window_checked(connection_, window_));
            xcb_generic_error_t*    error (::xcb_request_check(connection_, cookie));
            
            if (error) {
              std::ostringstream ostr;

              ostr << "hugh::platform::xcb::window::context: "
                   << "mapping window on '"
                   << c
                   << "' failed! (error: "
                   << error->error_code
                   << ')';

              ::free(error);
              
              throw std::runtime_error(ostr.str());
            }
          }
          
          flush();
        }
    
        /* virtual */
        context::~context()
        {
          TRACE("hugh::platform::xcb::window::context::~context");

          event_listener_active_ = false;
          
          ::xcb_unmap_window(connection_, window_);
          flush();
          
          event_listener_->join();
          
          ::xcb_disconnect(connection_);
        }

        /* virtual */ void
        context::print_on(std::ostream& os) const
        {
          TRACE("hugh::platform::xcb::window::context::print_on");
          
          // boost::io::ios_all_saver const ias(os);

          os << '['
            //<<             title_              << ','
            //<<             position_           << ','
            //<<             size_               << ','
             << "con:@"  << connection_         << ','
             << "scr:@"  << screen_             << ','
             << "win:"   << window_             << ','
             << "gc:"    << gcontext_           << ','
             << "hndlr:" << handler_map_.size() << ','
             << "thr:[";
          
          if (event_listener_) {
            boost::io::ios_all_saver const ias(os);
            
            os << "0x"
               << std::setfill('0')
               << std::setw(8)
               << std::hex
               << event_listener_->get_id();
          } else {
            os << "not started";
          }
          
          os << ',' << (event_listener_active_ ? "" : "in") << "active]]";
        }
        
        glm::uvec2 const&
        context::position() const
        {
          TRACE("hugh::platform::xcb::window::context::position(get)");

          return position_;
        }

        glm::uvec2
        context::position(glm::uvec2 const& a)
        {
          TRACE("hugh::platform::xcb::window::context::position(set)");

          glm::uvec2 const result(position());

          if (a != result) {
            position_ = a;
            
            {
              static uint32_t const mask(XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y);
              /*  */ uint32_t const values[] = { uint32_t(position_.x), uint32_t(position_.y) };
              
              ::xcb_configure_window(connection_, window_, mask, values);
              
              flush();
            }
          }
          
          return result;
        }
      
        glm::uvec2 const&
        context::size() const
        {
          TRACE("hugh::platform::xcb::window::context::size(get)");

          return size_;
        }

        glm::uvec2
        context::size(glm::uvec2 const& a)
        {
          TRACE("hugh::platform::xcb::window::context::size(set)");

          glm::uvec2 const result(size());

          if (a != result) {
            size_ = a;
            
            {
              static uint32_t const mask(XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT);
              /*  */ uint32_t const values[] = { uint32_t(size_.x), uint32_t(size_.y) };
              
              ::xcb_configure_window(connection_, window_, mask, values);
              
              flush();
            }
          }
          
          return result;
        }

        std::string const&
        context::title() const
        {
          TRACE("hugh::platform::xcb::window::context::title(get)");
          
          return title_;
        }

        std::string
        context::title(std::string const& a)
        {
          TRACE("hugh::platform::xcb::window::context::title(set)");

          std::string const result(title());

          title_ = a;

          {
            static std::array<xcb_atom_enum_t const, 2> const types = {
              XCB_ATOM_WM_NAME, XCB_ATOM_WM_ICON_NAME,
            };

            for (auto const& t : types){
              ::xcb_change_property(connection_,
                                    XCB_PROP_MODE_REPLACE,
                                    window_,
                                    t,
                                    XCB_ATOM_STRING,
                                    8,
                                    title_.size(),
                                    title_.c_str());
            }

            flush();
          }
          
          return result;
        }

        void
        context::flush() const
        {
          TRACE("hugh::platform::xcb::window::context::flush");

          if (!::xcb_connection_has_error(connection_)) {
            ::xcb_flush(connection_);
          }
        }

        namespace {

          // [https://stackoverflow.com/questions/18039723]
          template <typename T, typename... U>
          inline size_t
          target_address(std::function<T(U...)> f)
          {
            typedef T(fnType)(U...);
            
            fnType** fnPointer = f.template target<fnType*>();
            
            return (fnPointer) ? size_t(*fnPointer) : 0;
          }
          
          struct predicate {

          public:

            predicate(context::handler_callback_type a)
              : lhs(target_address(a))
            {}

            bool operator()(context::handler_callback_type rhs) const
            {
              return lhs == target_address(rhs);
            }
            
            size_t const lhs;
            
          };
          
        }
        
        bool
        context::add(uint8_t a, handler_callback_type b)
        {
          TRACE("hugh::platform::xcb::window::context::add");

          bool result(false);

          {
            std::lock_guard<std::mutex> l(handler_map_mutex_);

            auto& hndlr(handler_map_[a]);
            auto  found(std::find_if(std::begin(hndlr), std::end(hndlr), predicate(b)));
            
            if (hndlr.end() == found) {
              hndlr.push_back(b);
              
              result = true;
            }
          }
          
          return result;
        }
        
        bool
        context::sub(uint8_t a, handler_callback_type b)
        {
          TRACE("hugh::platform::xcb::window::context::sub");

          bool result(false);

          {
            std::lock_guard<std::mutex> l(handler_map_mutex_);

            auto& hndlr(handler_map_[a]);
            auto  found(std::find_if(std::begin(hndlr), std::end(hndlr), predicate(b)));
            
            if (hndlr.end() != found) {
              hndlr.erase(found);
              
              result = true;
            }
          }
          
          return result;
        }

        void
        context::event_listener_loop()
        {
          TRACE("hugh::platform::xcb::window::context::event_listener_loop");

          {
            std::mutex                   m;
            std::unique_lock<std::mutex> l(m);
            std::condition_variable      c;
          
            c.wait(l, [&]() { return event_listener_active_; });
          }
          
          while (event_listener_active_) {
            ::xcb_generic_event_t* event(::xcb_wait_for_event(connection_));

            if (nullptr != event) {
              std::ostringstream log;
              
              if (0 == event->response_type) {
                xcb_request_error_t* e(reinterpret_cast<xcb_request_error_t*>(event));
              
                log << *e << '|'
                    << "XCB_REQUEST|received X11 error: "
                    << e->error_code << ','
                    << "b:" << e->bad_value << ','
                    << "o:" << e->major_opcode << ':' << e->minor_opcode;
              } else {
                bool handled(false);

                {
                  std::lock_guard<std::mutex> l(handler_map_mutex_);

                  auto& hndlr(handler_map_[XCB_EVENT_RESPONSE_TYPE(event)]);
                  
                  for (auto h : hndlr) {
                    handled = h(*event);
                  }
                
                  if (!handled && !hndlr.empty()) {
                    log << *event << ": NOT HANDLED";
                  }
                } // ~std::lock_guard<>
              }
              
              ::free(event);

              if (!log.str().empty()) {
                std::cout << hugh::support::trace::prefix()
                          << "hugh::platform::xcb::window::context::event_listener_loop: "
                          << log.str()
                          << '\n';
              }
            } else {
#if defined(HUGH_ALL_TRACE)
              std::cout << hugh::support::trace::prefix()
                        << "hugh::platform::xcb::window::context::event_listener_loop: "
                        << "received nullptr event"
                        << '\n';
#endif
            }
          }
        }
        
      } // namespace window {
      
    } // namespace xcb {
    
  } // namespace platform {

} // namespace hugh {
