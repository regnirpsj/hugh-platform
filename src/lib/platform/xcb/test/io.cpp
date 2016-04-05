// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/test/io.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <sstream> // std::ostringstream

// includes, project

#include <hugh/platform/xcb/io.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 40
#include <boost/mpl/list.hpp>

using xcb_types = boost::mpl::list<uint8_t
                                   ,::xcb_atom_enum_t
                                   ,::xcb_button_press_event_t
                                   ,::xcb_circulate_notify_event_t
                                   ,::xcb_client_message_event_t
                                   ,::xcb_colormap_notify_event_t
                                   ,::xcb_configure_notify_event_t
                                   ,::xcb_request_error_t
                                   ,::xcb_configure_request_event_t
                                   ,::xcb_configure_window_request_t
                                   ,::xcb_convert_selection_request_t
                                   ,::xcb_create_notify_event_t
                                   ,::xcb_destroy_notify_event_t
                                   ,::xcb_enter_notify_event_t
                                   ,::xcb_expose_event_t
                                   ,::xcb_focus_in_event_t
                                   ,::xcb_ge_generic_event_t
                                   ,::xcb_generic_event_t
                                   ,::xcb_graphics_exposure_event_t
                                   ,::xcb_gravity_notify_event_t
                                   ,::xcb_key_press_event_t
                                   ,::xcb_keymap_notify_event_t
                                   ,::xcb_map_notify_event_t
                                   ,::xcb_map_request_event_t
                                   ,::xcb_mapping_notify_event_t
                                   ,::xcb_motion_notify_event_t
                                   ,::xcb_no_exposure_event_t
                                   ,::xcb_notify_detail_t
                                   ,::xcb_notify_mode_t
                                   ,::xcb_property_notify_event_t
                                   ,::xcb_property_t
                                   ,::xcb_reparent_notify_event_t
                                   ,::xcb_resize_request_event_t
                                   ,::xcb_selection_clear_event_t
                                   ,::xcb_selection_notify_event_t
                                   ,::xcb_selection_request_event_t
                                   ,::xcb_unmap_notify_event_t
                                   ,::xcb_visibility_notify_event_t
                                   ,::xcb_visibility_t
                                   >;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_hugh_platform_xcb_io, T, xcb_types)
{
  using hugh::platform::xcb::operator<<;
  
  std::ostringstream ostr;

  ostr << T();
  
  BOOST_CHECK       (!ostr.str().empty());
  BOOST_TEST_MESSAGE( ostr.str());
}
