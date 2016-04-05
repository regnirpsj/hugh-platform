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
#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <iomanip>                // std::setfill, std::setw
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

  template <typename T, typename S, std::size_t L>
  inline std::ostream&
  get_enum(std::ostream& os, T const& a, std::array<S, L> const& b)
  {
    std::ostream::sentry const cerberus(os);
    
    if (cerberus) {
      os << '[';

      if ((0 <= unsigned(a)) && (unsigned(a) < b.size())) {
        os << b[a];
      } else {
        os << "INVALID (" << unsigned(a) << ')';
      }

      os << ']';
    }

    return os;
  }

  template <typename T, typename S, std::size_t L>
  inline std::ostream&
  get_flags(std::ostream& os, T const& a, std::array<std::pair<T, S>, L> const& b)
  {
    std::ostream::sentry const cerberus(os);
    
    if (cerberus) {
      os << '[';

      if (a) {
        for (auto f : b) {
          if (a & f.first) {
            os << f.second << '|';
          }
        }
      
        os << hugh::support::ostream::remove(1);
      } else {
        os << "NONE";
      }

      os << ']';
    }

    return os;
  }

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
        static std::array<std::string const, 69> const types = {
          { "NONE/ANY", "PRIMARY", "SECONDARY", "ARC", "ATOM", "BITMAP", "CARDINAL", "COLORMAP",
            "CURSOR", "CUT_BUFFER0", "CUT_BUFFER1", "CUT_BUFFER2", "CUT_BUFFER3", "CUT_BUFFER4",
            "CUT_BUFFER5", "CUT_BUFFER6", "CUT_BUFFER7", "DRAWABLE", "FONT", "INTEGER", "PIXMAP",
            "POINT", "RECTANGLE", "RESOURCE_MANAGER", "RGB_COLOR_MAP", "RGB_BEST_MAP" ,
            "RGB_BLUE_MAP", "RGB_DEFAULT_MAP", "RGB_GRAY_MAP", "RGB_GREEN_MAP", "RGB_RED_MAP",
            "STRING", "VISUALID", "WINDOW", "WM_COMMAND", "WM_HINTS", "WM_CLIENT_MACHINE",
            "WM_ICON_NAME", "WM_ICON_SIZE", "WM_NAME", "WM_NORMAL_HINTS", "WM_SIZE_HINTS",
            "WM_ZOOM_HINTS", "MIN_SPACE", "NORM_SPACE", "MAX_SPACE", "END_SPACE", "SUPERSCRIPT_X",
            "SUPERSCRIPT_Y", "SUBSCRIPT_X", "SUBSCRIPT_Y", "UNDERLINE_POSITION",
            "UNDERLINE_THICKNESS", "STRIKEOUT_ASCENT", "STRIKEOUT_DESCENT", "ITALIC_ANGLE",
            "X_HEIGHT", "QUAD_WIDTH", "WEIGHT", "POINT_SIZE", "RESOLUTION", "COPYRIGHT", "NOTICE",
            "FONT_NAME", "FAMILY_NAME", "FULL_NAME", "CAP_HEIGHT", "WM_CLASS", "WM_TRANSIENT_FOR", }
        };

        return get_enum(os, a, types);
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
        static std::array<std::string const, 8> const types = {
          { "NOTIFY_DETAIL_ANCESTOR",
            "NOTIFY_DETAIL_VIRTUAL",
            "NOTIFY_DETAIL_INFERIOR",
            "NOTIFY_DETAIL_NONLINEAR",
            "NOTIFY_DETAIL_NONLINEAR_VIRTUAL",
            "NOTIFY_DETAIL_POINTER",
            "NOTIFY_DETAIL_POINTER_ROOT",
            "NOTIFY_DETAIL_NONE", }
        };

        return get_enum(os, a, types);
      }
      
      std::ostream&
      operator<<(std::ostream& os, ::xcb_notify_mode_t const& a)
      {
        static std::array<std::string const, 4> const types = {
          { "NOTIFY_MODE_NORMAL",
            "NOTIFY_MODE_GRAB",
            "NOTIFY_MODE_UNGRAB",
            "NOTIFY_MODE_WHILE_GRABBED", }
        };

        return get_enum(os, a, types);
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
        static std::array<std::string const, 2> const types = {
          { "PROPERTY_NEW_VALUE", "PROPERTY_DELETE", }
        };
        
        return get_enum(os, a, types);
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
        static std::array<std::string const, 3> const types = {
          { "VISIBILITY_UNOBSCURED",
            "VISIBILITY_PARTIALLY_OBSCURED",
            "VISIBILITY_FULLY_OBSCURED", }
        };

        return get_enum(os, a, types);
      }
      
    } // namespace xcb {
    
  } // namespace platform {
  
} // namespace hugh {
