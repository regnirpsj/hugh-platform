// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/base.cpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/xcb/window/base.hpp"

// includes, system

#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <cstdlib>                // ::getenv
#include <glm/gtx/io.hpp>         // glm::operator<<  (field::container::print_on)
#include <sstream>                // std::ostringstream
#include <stdexcept>              // std::runtime_error

// includes, project

#include <hugh/platform/xcb/window/manager.hpp>

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

        /* static */ std::string const base::dflt_display_name((!env_dpy_name.empty()) ?
                                                               env_dpy_name :
                                                               dflt_dpy_name);
        
        // functions, exported
          
        /* virtual */
        base::~base()
        {
          TRACE("hugh::platform::xcb::window::base::~base");

          window::manager::sub(this);
          
          ::xcb_unmap_window(connection_, window_);
          ::xcb_disconnect  (connection_);
        }
        

        /* virtual */ void
        base::print_on(std::ostream& os) const
        {
          TRACE("hugh::platform::xcb::window::base::print_on");

          platform::window::base::print_on(os);

          boost::io::ios_all_saver const ias(os);
          
          os << "\b,"
             << "con:@"  << connection_ << ','
             << "scr:@"  << screen_     << ','
             << std::hex
             << "win:0x" << window_     << ','
             << "ctx:0x" << context_
             << ']';
        }

        /* explicit */
        base::base(std::string const& a, rect const& b, std::string const& c)
          : platform::window::base(a, b),
            connection_           (nullptr),
            screen_               (nullptr),
            window_               (0),
            context_              (0)
        {
          TRACE("hugh::platform::xcb::window::base::base");

          if (!c.empty()) {                              // try requested display
            connection_ = ::xcb_connect(c.c_str(), nullptr);
          }
          
          if (::xcb_connection_has_error(connection_)) { // try default display
            connection_ = ::xcb_connect(nullptr, nullptr);
          }
          
          if (::xcb_connection_has_error(connection_)) {
            std::ostringstream ostr;

            ostr << "hugh::platform::xcb::window::base: "
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
                                                                       position->x, position->y,
                                                                       size->x, size->y,
                                                                       1,
                                                                       wclass,
                                                                       screen_->root_visual,
                                                                       mask, values));

            xcb_generic_error_t const* error(::xcb_request_check(connection_, cookie));

            if (error) {
              std::ostringstream ostr;

              ostr << "hugh::platform::xcb::window::base: "
                   << "creating window on '"
                   << c
                   << "' failed! (error: "
                   << error->error_code
                   << ')';
              
              throw std::runtime_error(ostr.str());
            }
          }

          context_ = xcb_generate_id(connection_);
          
          {
            uint32_t const mask(XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES);
            uint32_t const values[2] = {
              screen_->black_pixel,
              0,
            };

            ::xcb_create_gc(connection_, context_, window_, mask, values);
          }
          
          ::xcb_map_window   (connection_, window_);
          ::xcb_flush        (connection_);

          window::manager::add(window_, this);
        }

        /* virtual */ void
        base::reposition()
        {
          TRACE("hugh::platform::window::xcb::base::reposition");
          
          static uint32_t const mask(XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y);
          /*  */ uint32_t const values[] = { uint32_t(position->x), uint32_t(position->y) };
          
          ::xcb_configure_window(connection_, window_, mask, values);
        }
        
        /* virtual */ void
        base::resize()
        {
          TRACE("hugh::platform::window::xcb::base::resize");
          
          static uint32_t const mask(XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT);
          /*  */ uint32_t const values[] = { uint32_t(size->x), uint32_t(size->y) };
          
          ::xcb_configure_window(connection_, window_, mask, values);
        }
        
        /* virtual */ void
        base::retitle()
        {
          TRACE("hugh::platform::window::xcb::base::retitle");

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
                                  title->size(),
                                  title->c_str());
          }
        }

      } // namespace window {

    } // namespace xcb {

  } // namespace platform {
  
} // namespace hugh {
