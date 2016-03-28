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

#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <cstdlib>                // ::getenv
#include <glm/gtx/io.hpp>         // glm::operator<<  (field::container::print_on)
#include <sstream>                // std::ostringstream
#include <stdexcept>              // std::runtime_error

// includes, project

//#include <>

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
          : support::printable(),
            title_            (a),
            position_         (glm::uvec2((0 > b.x) ? 0 : b.x,
                                          (0 > b.y) ? 0 : b.y)),
            size_             (glm::uvec2((1 > b.w) ? 1 : b.w,
                                          (1 > b.h) ? 1 : b.h)),
            connection_       (nullptr),
            screen_           (nullptr),
            window_           (0),
            gcontext_         (0)
        {
          TRACE("hugh::platform::xcb::window::context::context");

          if (!c.empty()) {                              // try requested display
            connection_ = ::xcb_connect(c.c_str(), nullptr);
          } else {
            connection_ = ::xcb_connect(nullptr, nullptr);
          }

          if (::xcb_connection_has_error(connection_)) { // try default display
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

          screen_ = ::xcb_setup_roots_iterator(xcb_get_setup(connection_)).data;
          window_ = ::xcb_generate_id(connection_);

          {
            uint32_t const mask(XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK);
            uint32_t const values[2] = {
              screen_->white_pixel,
              XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS,
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

            xcb_generic_error_t const* error(::xcb_request_check(connection_, cookie));

            if (error) {
              std::ostringstream ostr;

              ostr << "hugh::platform::xcb::window::context: "
                   << "creating window on '"
                   << c
                   << "' failed! (error: "
                   << error->error_code
                   << ')';

              throw std::runtime_error(ostr.str());
            }
          }

          gcontext_ = xcb_generate_id(connection_);

          {
            uint32_t const mask(XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES);
            uint32_t const values[2] = {
              screen_->black_pixel,
              0,
            };

            ::xcb_create_gc(connection_, gcontext_, window_, mask, values);
          }

          ::xcb_map_window   (connection_, window_);
          ::xcb_flush        (connection_);
        }
    
        /* virtual */
        context::~context()
        {
          TRACE("hugh::platform::xcb::window::context::~context");

          ::xcb_unmap_window(connection_, window_);
          ::xcb_disconnect  (connection_);
        }

        /* virtual */ void
        context::print_on(std::ostream& os) const
        {
          TRACE("hugh::platform::xcb::window::context::print_on");
          
          boost::io::ios_all_saver const ias(os);

          os << '['
             <<             title_      << ','
             <<             position_   << ','
             <<             size_       << ','
             << "con:@"  << connection_ << ','
             << "scr:@"  << screen_     << ','
             << std::hex << std::showbase
             << "win:"   << window_     << ','
             << "ctx:"   << gcontext_
             << ']';
        }
        
        glm::uvec2 const&
        context::position() const
        {
          TRACE("hugh::platform::xcb::window::context:::position(get)");

          return position_;
        }

        glm::uvec2
        context::position(glm::uvec2 const& a)
        {
          TRACE("hugh::platform::xcb::window::context:::position(set)");

          glm::uvec2 const result(position());

          position_ = a;

          {
            static uint32_t const mask(XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y);
            /*  */ uint32_t const values[] = { uint32_t(position_.x), uint32_t(position_.y) };

            ::xcb_configure_window(connection_, window_, mask, values);
          }
          
          return result;
        }
      
        glm::uvec2 const&
        context::size() const
        {
          TRACE("hugh::platform::xcb::window::context:::size(get)");

          return size_;
        }

        glm::uvec2
        context::size(glm::uvec2 const& a)
        {
          TRACE("hugh::platform::xcb::window::context:::size(set)");

          glm::uvec2 const result(size());

          size_ = a;

          {
            static uint32_t const mask(XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT);
            /*  */ uint32_t const values[] = { uint32_t(size_.x), uint32_t(size_.y) };
            
            ::xcb_configure_window(connection_, window_, mask, values);
          }
          
          return result;
        }

        std::string const&
        context::title() const
        {
          TRACE("hugh::platform::xcb::window::context:::title(get)");

          return title_;
        }

        std::string
        context::title(std::string const& a)
        {
          TRACE("hugh::platform::xcb::window::context:::title(set)");

          std::string const result(title());

          title_ = a;

          {
            static std::array<xcb_atom_enum_t const, 2> const types = {
              {
                XCB_ATOM_WM_NAME, XCB_ATOM_WM_ICON_NAME,
              }
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
          }
          
          return result;
        }
  
      } // namespace window {
      
    } // namespace xcb {
    
  } // namespace platform {

} // namespace hugh {
