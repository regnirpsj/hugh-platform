// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/input.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/xcb/window/input.hpp"

// includes, system

#include <ostream>         // std::ostream
#include <xcb/xcb_event.h> // XCB_EVENT_RESPONSE_TYPE, ::xcb_event_get_label

// includes, project

#include <hugh/platform/xcb/io.hpp>
#include <hugh/platform/xcb/window/context.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  uint32_t const event_mask(// context
                              XCB_EVENT_MASK_PROPERTY_CHANGE
                            // update
                            | XCB_EVENT_MASK_ENTER_WINDOW
                            | XCB_EVENT_MASK_LEAVE_WINDOW
                            | XCB_EVENT_MASK_EXPOSURE
                            | XCB_EVENT_MASK_VISIBILITY_CHANGE
                            | XCB_EVENT_MASK_STRUCTURE_NOTIFY
                            | XCB_EVENT_MASK_RESIZE_REDIRECT
                            | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
                            | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT
                            | XCB_EVENT_MASK_FOCUS_CHANGE
                            // input
                            | XCB_EVENT_MASK_KEY_PRESS
                            | XCB_EVENT_MASK_KEY_RELEASE
                            | XCB_EVENT_MASK_BUTTON_PRESS
                            | XCB_EVENT_MASK_BUTTON_RELEASE
                            | XCB_EVENT_MASK_POINTER_MOTION
                            | XCB_EVENT_MASK_POINTER_MOTION_HINT
                            | XCB_EVENT_MASK_BUTTON_1_MOTION
                            | XCB_EVENT_MASK_BUTTON_2_MOTION
                            | XCB_EVENT_MASK_BUTTON_3_MOTION
                            | XCB_EVENT_MASK_BUTTON_4_MOTION
                            | XCB_EVENT_MASK_BUTTON_5_MOTION
                            | XCB_EVENT_MASK_BUTTON_MOTION
                            | XCB_EVENT_MASK_KEYMAP_STATE
                            | XCB_EVENT_MASK_OWNER_GRAB_BUTTON);
  
  std::array<uint8_t, 16> const event_types = {
    XCB_BUTTON_PRESS,
    XCB_BUTTON_RELEASE,
    XCB_CHANGE_ACTIVE_POINTER_GRAB,
    XCB_GRAB_BUTTON,
    XCB_GRAB_KEY,
    XCB_GRAB_KEYBOARD,
    XCB_GRAB_POINTER,
    XCB_KEY_PRESS,
    XCB_KEY_RELEASE,
    XCB_KEYMAP_NOTIFY,
    XCB_MOTION_NOTIFY,
    XCB_SELECTION_NOTIFY,
    XCB_UNGRAB_BUTTON,
    XCB_UNGRAB_KEY,
    XCB_UNGRAB_KEYBOARD,
    XCB_UNGRAB_POINTER,
  };
  
  // functions, internal

} // namespace {

namespace hugh {

  namespace platform {

    namespace xcb {

      namespace window {
        
        // variables, exported

        // functions, exported

        /* explicit */
        input::input(context& a)
          : support::printable(),
            ctx_              (a)
        {
          TRACE("hugh::platform::xcb::window::input::input");

          ::xcb_change_window_attributes(ctx_.connection_,
                                         ctx_.window_,
                                         XCB_CW_EVENT_MASK,
                                         &event_mask);
          ctx_.flush();

          for (auto t : event_types) {
            ctx_.add(t, std::bind(&input::handle_xcb_event, this, std::placeholders::_1));
          }
        }

        /* virtual */
        input::~input()
        {
          TRACE("hugh::platform::xcb::window::input::~input");

          for (auto t : event_types) {
            ctx_.sub(t, std::bind(&input::handle_xcb_event, this, std::placeholders::_1));
          }
        }

        /* virtual */ void
        input::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::xcb::window::input::print_on");

          os << '['
             << ctx_
             << ']';
        }
        
        void
        input::operator()()
        {
          TRACE("hugh::platform::xcb::window::input::operator()");
        }

        bool
        input::handle_xcb_event(::xcb_generic_event_t const& a)
        {
          TRACE("hugh::platform::xcb::window::input::handle_xcb_event");

          bool result(false);

          switch (a.response_type & XCB_EVENT_RESPONSE_TYPE_MASK) {
          default:
            {
              for (auto t : event_types) {
                if (t == (a.response_type & XCB_EVENT_RESPONSE_TYPE_MASK)) {
                  result = true;

                  break;
                }
              }

#if 0	      
              std::cout << hugh::support::trace::prefix()
                        << "hugh::platform::xcb::window::input::handle_xcb_event: "
                        << a
                        << '\n';
#endif

            }

            break;
          }
          
          return result;
        }
        
      } // namespace window {
      
    } // namespace xcb {
    
  } // namespace platform {

} // namespace hugh {
