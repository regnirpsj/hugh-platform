// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/test/window.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)
#include <sstream>        // std::ostringstream

// includes, project

#include <hugh/platform/window/rect.hpp>

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

BOOST_AUTO_TEST_CASE(test_hugh_platform_window_rect_ctor)
{
  using namespace hugh::platform::window;

  {
    rect const r;

    BOOST_CHECK(rect::dflt_value_system == r.x);
    BOOST_CHECK(rect::dflt_value_system == r.y);
    BOOST_CHECK(rect::dflt_value_system == r.w);
    BOOST_CHECK(rect::dflt_value_system == r.h);    
  }

  {
    rect const r(1, 2, 3, 4);

    BOOST_CHECK(1 == r.x);
    BOOST_CHECK(2 == r.y);
    BOOST_CHECK(3 == r.w);
    BOOST_CHECK(4 == r.h);    
  }

  {
    rect const r(glm::ivec2(1, 2), glm::ivec2(3, 4));

    BOOST_CHECK(1 == r.x);
    BOOST_CHECK(2 == r.y);
    BOOST_CHECK(3 == r.w);
    BOOST_CHECK(4 == r.h);    
  }
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_window_rect_contains)
{
  using namespace hugh::platform::window;

  rect const r(0, 0, 2, 2);

  for (signed x(r.x); x <= r.w; ++x) {
    for (signed y(r.y); y <= r.h; ++y) {
      BOOST_CHECK(r.contains(glm::ivec2(x, y)));
    }
  }
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_window_rect_op_compare)
{
  using namespace hugh::platform::window;

  rect const r1(0, 0, 2, 2);
  rect const r2(1, 1, 4, 4);
  
  BOOST_CHECK(  r1 == r1);
  BOOST_CHECK(!(r1 == r2));
  BOOST_CHECK(  r1  < r2);
  BOOST_CHECK(!(r2  < r1));
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_window_rect_swap)
{
  using namespace hugh::platform;

  unsigned const     cnt(999); // needs to be 2n+1 for checks to work
  window::rect const r1c(1, 2, 3, 4);
  window::rect const r2c(4, 3, 2, 1);

  {
    window::rect r1(r1c);
    window::rect r2(r2c);

    {
      TRACE_NEVER("std::swap(r1, r2);");

      for (unsigned i(0); i < cnt; ++i) {
        std::swap(r1, r2);
      }
    }
    
    BOOST_CHECK(r1 == r2c);
    BOOST_CHECK(r2 == r1c);
  }  

  {
    window::rect r1(r1c);
    window::rect r2(r2c);

    {
      TRACE_NEVER("swap(r1, r2);");

      for (unsigned i(0); i < cnt; ++i) {
        swap(r1, r2);
      }
    }
    
    BOOST_CHECK(r1 == r2c);
    BOOST_CHECK(r2 == r1c);
  }  

  {
    window::rect r1(r1c);
    window::rect r2(r2c);

    {
      TRACE_NEVER("using std::swap; swap(r1, r2);");

      for (unsigned i(0); i < cnt; ++i) {
        using std::swap; swap(r1, r2);
      }
    }
    
    BOOST_CHECK(r1 == r2c);
    BOOST_CHECK(r2 == r1c);
  }  
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_window_rect_print)
{
  using namespace hugh::platform::window;

  rect const         r;
  std::ostringstream ostr;

  ostr << r;

  BOOST_CHECK       (!ostr.str().empty());
  BOOST_TEST_MESSAGE(ostr.str());
}
