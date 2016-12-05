// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/io.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/xcb/io.hpp"

// includes, system

#include <array>                  // std::array<>
//#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <ostream>                // std::ostream
#include <sstream>                // std::ostringstream
#include <string>                 // std:string
#include <utility>                // std::make_pair<>, std::pair<>
#include <vector>                 // std::vector<>
#include <xcb/xcb_event.h>        // ::xcb_event_get_label

// includes, project

#include <hugh/support/io_utils.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  inline std::string
  get_response_label(uint8_t a)
  {
    char const*        label(::xcb_event_get_label(a));
    std::ostringstream ostr;
    
    if (label) {
      ostr << label;
    } else {
      ostr << "Unknown (" << unsigned(a) << ")";
    }
    
    return ostr.str();
  }
  
} // namespace {

namespace hugh {

  namespace platform {

    namespace xcb {
      
      // variables, exported
  
      // functions, exported

      std::ostream&
      operator<<(std::ostream& os, uint8_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {          
          os << unsigned(a);
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_atom_enum_t const& a)
      {
        static std::array<std::pair<::xcb_atom_enum_t const, std::string const>, 69> const types = {
          std::make_pair(XCB_ATOM_ANY, "NONE/ANY"),
          std::make_pair(XCB_ATOM_PRIMARY, "PRIMARY"),
          std::make_pair(XCB_ATOM_SECONDARY, "SECONDARY"),
          std::make_pair(XCB_ATOM_ARC, "ARC"),
          std::make_pair(XCB_ATOM_ATOM, "ATOM"),
          std::make_pair(XCB_ATOM_BITMAP, "BITMAP"),
          std::make_pair(XCB_ATOM_CARDINAL, "CARDINAL"),
          std::make_pair(XCB_ATOM_COLORMAP, "COLORMAP"),
          std::make_pair(XCB_ATOM_CURSOR, "CURSOR"),
          std::make_pair(XCB_ATOM_CUT_BUFFER0, "CUT_BUFFER0"),
          std::make_pair(XCB_ATOM_CUT_BUFFER1, "CUT_BUFFER1"),
          std::make_pair(XCB_ATOM_CUT_BUFFER2, "CUT_BUFFER2"),
          std::make_pair(XCB_ATOM_CUT_BUFFER3, "CUT_BUFFER3"),
          std::make_pair(XCB_ATOM_CUT_BUFFER4, "CUT_BUFFER4"),
          std::make_pair(XCB_ATOM_CUT_BUFFER5, "CUT_BUFFER5"),
          std::make_pair(XCB_ATOM_CUT_BUFFER6, "CUT_BUFFER6"),
          std::make_pair(XCB_ATOM_CUT_BUFFER7, "CUT_BUFFER7"),
          std::make_pair(XCB_ATOM_DRAWABLE, "DRAWABLE"),
          std::make_pair(XCB_ATOM_FONT, "FONT"),
          std::make_pair(XCB_ATOM_INTEGER, "INTEGER"),
          std::make_pair(XCB_ATOM_PIXMAP, "PIXMAP"),
          std::make_pair(XCB_ATOM_POINT, "POINT"),
          std::make_pair(XCB_ATOM_RECTANGLE, "RECTANGLE"),
          std::make_pair(XCB_ATOM_RESOURCE_MANAGER, "RESOURCE_MANAGER"),
          std::make_pair(XCB_ATOM_RGB_COLOR_MAP, "RGB_COLOR_MAP"),
          std::make_pair(XCB_ATOM_RGB_BEST_MAP, "RGB_BEST_MAP"),
          std::make_pair(XCB_ATOM_RGB_BLUE_MAP, "RGB_BLUE_MAP"),
          std::make_pair(XCB_ATOM_RGB_DEFAULT_MAP, "RGB_DEFAULT_MAP"),
          std::make_pair(XCB_ATOM_RGB_GRAY_MAP, "RGB_GRAY_MAP"),
          std::make_pair(XCB_ATOM_RGB_GREEN_MAP, "RGB_GREEN_MAP"),
          std::make_pair(XCB_ATOM_RGB_RED_MAP, "RGB_RED_MAP"),
          std::make_pair(XCB_ATOM_STRING, "STRING"),
          std::make_pair(XCB_ATOM_VISUALID, "VISUALID"),
          std::make_pair(XCB_ATOM_WINDOW, "WINDOW"),
          std::make_pair(XCB_ATOM_WM_COMMAND, "WM_COMMAND"),
          std::make_pair(XCB_ATOM_WM_HINTS, "WM_HINTS"),
          std::make_pair(XCB_ATOM_WM_CLIENT_MACHINE, "WM_CLIENT_MACHINE"),
          std::make_pair(XCB_ATOM_WM_ICON_NAME, "WM_ICON_NAME"),
          std::make_pair(XCB_ATOM_WM_ICON_SIZE, "WM_ICON_SIZE"),
          std::make_pair(XCB_ATOM_WM_NAME, "WM_NAME"),
          std::make_pair(XCB_ATOM_WM_NORMAL_HINTS, "WM_NORMAL_HINTS"),
          std::make_pair(XCB_ATOM_WM_SIZE_HINTS, "WM_SIZE_HINTS"),
          std::make_pair(XCB_ATOM_WM_ZOOM_HINTS, "WM_ZOOM_HINTS"),
          std::make_pair(XCB_ATOM_MIN_SPACE, "MIN_SPACE"),
          std::make_pair(XCB_ATOM_NORM_SPACE, "NORM_SPACE"),
          std::make_pair(XCB_ATOM_MAX_SPACE, "MAX_SPACE"),
          std::make_pair(XCB_ATOM_END_SPACE, "END_SPACE"),
          std::make_pair(XCB_ATOM_SUPERSCRIPT_X, "SUPERSCRIPT_X"),
          std::make_pair(XCB_ATOM_SUPERSCRIPT_Y, "SUPERSCRIPT_Y"),
          std::make_pair(XCB_ATOM_SUBSCRIPT_X, "SUBSCRIPT_X"),
          std::make_pair(XCB_ATOM_SUBSCRIPT_Y, "SUBSCRIPT_Y"),
          std::make_pair(XCB_ATOM_UNDERLINE_POSITION, "UNDERLINE_POSITION"),
          std::make_pair(XCB_ATOM_UNDERLINE_THICKNESS, "UNDERLINE_THICKNESS"),
          std::make_pair(XCB_ATOM_STRIKEOUT_ASCENT, "STRIKEOUT_ASCENT"),
          std::make_pair(XCB_ATOM_STRIKEOUT_DESCENT, "STRIKEOUT_DESCENT"),
          std::make_pair(XCB_ATOM_ITALIC_ANGLE, "ITALIC_ANGLE"),
          std::make_pair(XCB_ATOM_X_HEIGHT, "X_HEIGHT"),
          std::make_pair(XCB_ATOM_QUAD_WIDTH, "QUAD_WIDTH"),
          std::make_pair(XCB_ATOM_WEIGHT, "WEIGHT"),
          std::make_pair(XCB_ATOM_POINT_SIZE, "POINT_SIZE"),
          std::make_pair(XCB_ATOM_RESOLUTION, "RESOLUTION"),
          std::make_pair(XCB_ATOM_COPYRIGHT, "COPYRIGHT"),
          std::make_pair(XCB_ATOM_NOTICE, "NOTICE"),
          std::make_pair(XCB_ATOM_FONT_NAME, "FONT_NAME"),
          std::make_pair(XCB_ATOM_FAMILY_NAME, "FAMILY_NAME"),
          std::make_pair(XCB_ATOM_FULL_NAME, "FULL_NAME"),
          std::make_pair(XCB_ATOM_CAP_HEIGHT, "CAP_HEIGHT"),
          std::make_pair(XCB_ATOM_WM_CLASS, "WM_CLASS"),
          std::make_pair(XCB_ATOM_WM_TRANSIENT_FOR, "WM_TRANSIENT_FOR"),
        };

        return os << support::ostream::enumerate(a, types);
      }
      
      std::ostream&
      operator<<(std::ostream& os, ::xcb_button_press_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_button_press_event_t) not implemented]";
        }
      
        return os;
      }
      
      std::ostream&
      operator<<(std::ostream& os, ::xcb_circulate_notify_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_circulate_notify_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_client_message_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_client_message_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_colormap_notify_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_colormap_notify_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_configure_notify_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.event                             << ','
             << a.window                            << ','
             << a.above_sibling                     << ','
             << a.x                                 << ','
             << a.y                                 << ','
             << a.width                             << ','
             << a.height                            << ','
             << a.border_width                      << ','
             << a.override_redirect
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_request_error_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_configure_request_error_t) not implemented]";
        }
      
        return os;
      }
      
      std::ostream&
      operator<<(std::ostream& os, ::xcb_configure_request_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_configure_request_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_configure_window_request_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_configure_window_request_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_convert_selection_request_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_convert_selection_request_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_create_notify_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_create_notify_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_destroy_notify_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_destroy_notify_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_enter_notify_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);

          os << '['
             << get_response_label(a.response_type) << ','
             << ::xcb_notify_detail_t(a.detail)     << ','
             << a.sequence                          << ','
             << a.time                              << ','
             << a.root                              << ','
             << a.event                             << ','
             << a.child                             << ','
             << a.root_x                            << ','
             << a.root_y                            << ','
             << a.event_x                           << ','
             << a.event_y                           << ','
             << a.state                             << ','
             << ::xcb_notify_mode_t(a.mode)         << ','
             << a.same_screen_focus
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_expose_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.window                            << ','
             << a.x                                 << ','
             << a.y                                 << ','
             << a.width                             << ','
             << a.height                            << ','
             << a.count
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_focus_in_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);

          os << '['
             << get_response_label(a.response_type) << ','
             << ::xcb_notify_detail_t(a.detail)     << ','
             << a.sequence                          << ','
             << a.event                             << ','
             << ::xcb_notify_mode_t(a.mode)
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_ge_generic_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);

          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.length                            << ','
             << a.event_type                        << ','
             << a.full_sequence
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_generic_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);

          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.full_sequence
             << ']';
        }
      
        return os;
      }
      
      std::ostream&
      operator<<(std::ostream& os, ::xcb_graphics_exposure_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_graphics_exposure_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_gravity_notify_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_gravity_notify_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_key_press_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_key_press_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_keymap_notify_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          using hugh::support::ostream::operator<<;
          
          // boost::io::ios_all_saver const ias(os);
          
          os << '['
             << get_response_label(a.response_type) << ','
             << std::vector<uint8_t>(a.keys, a.keys+30)
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_map_notify_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);

          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.event                             << ','
             << a.window                            << ','
             << a.override_redirect
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_map_request_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.parent                            << ','
             << a.window
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_mapping_notify_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_mapping_notify_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_motion_notify_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_motion_notify_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_no_exposure_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_no_exposure_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_notify_detail_t const& a)
      {
        static std::array<std::pair<::xcb_notify_detail_t const, std::string const>, 8> const
          types = {
          std::make_pair(XCB_NOTIFY_DETAIL_ANCESTOR, "NOTIFY_DETAIL_ANCESTOR"),
          std::make_pair(XCB_NOTIFY_DETAIL_VIRTUAL, "NOTIFY_DETAIL_VIRTUAL"),
          std::make_pair(XCB_NOTIFY_DETAIL_INFERIOR, "NOTIFY_DETAIL_INFERIOR"),
          std::make_pair(XCB_NOTIFY_DETAIL_NONLINEAR, "NOTIFY_DETAIL_NONLINEAR"),
          std::make_pair(XCB_NOTIFY_DETAIL_NONLINEAR_VIRTUAL, "NOTIFY_DETAIL_NONLINEAR_VIRTUAL"),
          std::make_pair(XCB_NOTIFY_DETAIL_POINTER, "NOTIFY_DETAIL_POINTER"),
          std::make_pair(XCB_NOTIFY_DETAIL_POINTER_ROOT, "NOTIFY_DETAIL_POINTER_ROOT"),
          std::make_pair(XCB_NOTIFY_DETAIL_NONE, "NOTIFY_DETAIL_NONE"),
        };

        return os << support::ostream::enumerate(a, types);
      }
      
      std::ostream&
      operator<<(std::ostream& os, ::xcb_notify_mode_t const& a)
      {
        static std::array<std::pair<::xcb_notify_mode_t const, std::string const>, 4> const
          types = {
          std::make_pair(XCB_NOTIFY_MODE_NORMAL, "NOTIFY_MODE_NORMAL"),
          std::make_pair(XCB_NOTIFY_MODE_GRAB, "NOTIFY_MODE_GRAB"),
          std::make_pair(XCB_NOTIFY_MODE_UNGRAB, "NOTIFY_MODE_UNGRAB"),
          std::make_pair(XCB_NOTIFY_MODE_WHILE_GRABBED, "NOTIFY_MODE_WHILE_GRABBED"),
        };

        return os << support::ostream::enumerate(a, types);
      }
      
      std::ostream&
      operator<<(std::ostream& os, ::xcb_property_notify_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);

          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.window                            << ','
             << ::xcb_atom_enum_t(a.atom)           << ','
             << a.time                              << ','
             << ::xcb_property_t(a.state)
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_property_t const& a)
      {
        static std::array<std::pair<::xcb_property_t const, std::string const>, 2> const types = {
          std::make_pair(XCB_PROPERTY_NEW_VALUE, "PROPERTY_NEW_VALUE"),
          std::make_pair(XCB_PROPERTY_DELETE, "PROPERTY_DELETE"),
        };
        
        return os << support::ostream::enumerate(a, types);
      }
      
      std::ostream&
      operator<<(std::ostream& os, ::xcb_reparent_notify_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);

          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.event                             << ','
             << a.window                            << ','
             << a.parent                            << ','
             << a.x                                 << ','
             << a.y                                 << ','
             << a.override_redirect
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_resize_request_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_resize_request_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_selection_clear_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_selection_clear_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_selection_notify_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_selection_notify_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_selection_request_event_t const&)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << "[operator<<(::xcb_selection_request_event_t) not implemented]";
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_unmap_notify_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.event                             << ','
             << a.window                            << ','
             << a.from_configure
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_visibility_notify_event_t const& a)
      {
        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          // boost::io::ios_all_saver const ias(os);
          
          os << '['
             << get_response_label(a.response_type) << ','
             << a.sequence                          << ','
             << a.window                            << ','
             << ::xcb_visibility_t(a.state)
             << ']';
        }
      
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::xcb_visibility_t const& a)
      {
        static std::array<std::pair<::xcb_visibility_t const, std::string const>, 3> const types = {
          std::make_pair(XCB_VISIBILITY_UNOBSCURED,         "VISIBILITY_UNOBSCURED"),
          std::make_pair(XCB_VISIBILITY_PARTIALLY_OBSCURED, "VISIBILITY_PARTIALLY_OBSCURED"),
          std::make_pair(XCB_VISIBILITY_FULLY_OBSCURED,     "VISIBILITY_FULLY_OBSCURED"),
        };

        return os << support::ostream::enumerate(a, types);
      }
      
    } // namespace xcb {
    
  } // namespace platform {
  
} // namespace hugh {
