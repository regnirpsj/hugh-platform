// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/test/window_manager.cpp                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <hugh/platform/xcb/window/manager.hpp>
#include <hugh/platform/xcb/window/simple.hpp>

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

BOOST_AUTO_TEST_CASE(test_hugh_platform_xcb_window_manager)
{
  namespace hpw  = hugh::platform::window;
  namespace hpxw = hugh::platform::xcb::window;
  
  BOOST_CHECK(0 == hpw::manager::count());
  
  {
    std::unique_ptr<hpxw::simple> const w(new hpxw::simple(""));

    BOOST_CHECK(nullptr != w);
    BOOST_CHECK(1 == hpw ::manager::count());
    BOOST_CHECK(1 == hpxw::manager::count());
  }
  
  {
    std::unique_ptr<hpxw::simple> const w1(new hpxw::simple(""));

    BOOST_CHECK(nullptr != w1);
    BOOST_CHECK(1 == hpw ::manager::count());
    BOOST_CHECK(1 == hpxw::manager::count());

    {
      std::unique_ptr<hpxw::simple> const w2(new hpxw::simple(""));

      BOOST_CHECK(nullptr != w2);
      BOOST_CHECK(2 == hpw ::manager::count());
      BOOST_CHECK(2 == hpxw::manager::count());
    }

    BOOST_CHECK(1 == hpw ::manager::count());
    BOOST_CHECK(1 == hpxw::manager::count());
  }
  
  BOOST_CHECK(0 == hpw::manager::count());
}
