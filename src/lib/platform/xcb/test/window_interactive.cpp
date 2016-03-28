// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/test/window_simple.cpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<  (field::container::print_on)

// includes, project

#include <hugh/platform/xcb/window.hpp>

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

BOOST_AUTO_TEST_CASE(test_hugh_platform_xcb_window_interactive)
{
  namespace hpw = hugh::platform::window;
  namespace hpx = hugh::platform::xcb;
  
  hpx::window::interactive const w("test_platform_xcb_window_interactive",
                                   hpw::rect(10, 10, 100, 100));
  
  BOOST_CHECK       (true);
  BOOST_TEST_MESSAGE(w);
}
