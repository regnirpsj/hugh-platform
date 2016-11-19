// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/update.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/xcb/window/update.hpp"

// includes, system

//#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <ostream>                // std::ostream
#include <xcb/xcb_event.h>        // XCB_EVENT_RESPONSE_TYPE, ::xcb_event_get_label

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
                            | XCB_EVENT_MASK_FOCUS_CHANGE);
  
  std::array<uint8_t, 14> const event_types = {
    XCB_CONFIGURE_NOTIFY,
    XCB_DESTROY_NOTIFY,
    XCB_EXPOSE,
    XCB_ENTER_NOTIFY,
    XCB_LEAVE_NOTIFY,
    XCB_FOCUS_IN,
    XCB_FOCUS_OUT,
    XCB_MAP_NOTIFY,
    XCB_MAP_REQUEST,
    XCB_PROPERTY_NOTIFY,
    XCB_REPARENT_NOTIFY,
    XCB_RESIZE_REQUEST,
    XCB_UNMAP_NOTIFY,
    XCB_VISIBILITY_NOTIFY,
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
        update::update(context& a)
          : support::printable(),
            ctx_              (a)
        {
          TRACE("hugh::platform::xcb::window::update::update");

          ::xcb_change_window_attributes(ctx_.connection_,
                                         ctx_.window_,
                                         XCB_CW_EVENT_MASK,
                                         &event_mask);
          ctx_.flush();

          for (auto t : event_types) {
            ctx_.add(t, std::bind(&update::handle_xcb_event, this, std::placeholders::_1));
          }
        }

        /* virtual */
        update::~update()
        {
          TRACE("hugh::platform::xcb::window::update::~update");

          for (auto t : event_types) {
            ctx_.sub(t, std::bind(&update::handle_xcb_event, this, std::placeholders::_1));
          }
        }

        /* virtual */ void
        update::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::xcb::window::update::print_on");
          
          os << '['
             << ctx_
             << ']';
        }
        
        void
        update::operator()()
        {
          TRACE("hugh::platform::xcb::window::update::operator()");
        }

        bool
        update::handle_xcb_event(::xcb_generic_event_t const& a)
        {
          TRACE("hugh::platform::xcb::window::update::handle_xcb_event");

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
              
              std::cout << hugh::support::trace::prefix()
                        << "hugh::platform::xcb::window::update::handle_xcb_event: "
                        << a
                        << '\n';
            }
            break;
          }
          
          return result;
        }
        
      } // namespace window {
      
    } // namespace xcb {
    
  } // namespace platform {

} // namespace hugh {
