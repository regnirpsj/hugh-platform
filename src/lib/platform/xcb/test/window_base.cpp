// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/test/window_base.cpp                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <cstdlib> // ::putenv
#include <memory>  // std::unique_ptr<>

// includes, project

#include <hugh/platform/xcb/window/base.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class test : public hugh::platform::xcb::window::base {

  public:

    explicit test(std::string const& a = hugh::platform::xcb::window::base::dflt_display_name)
      : hugh::platform::xcb::window::base("test", hugh::platform::window::rect::dflt_rect, a)
    {}
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_platform_xcb_window_base_ctor)
{
  std::unique_ptr<test const> const w(new test);

  BOOST_CHECK       ( w);
  BOOST_TEST_MESSAGE(*w);
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_xcb_window_base_ctor_fail)
{
  char                  d[] = "DISPLAY=dummy:?.?";
  std::unique_ptr<test> w(nullptr);
    
  ::putenv(d);
  
  BOOST_REQUIRE_THROW(w.reset(new test(d)), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_xcb_window_base_position)
{
  glm::ivec2 const      p(42, 42);
  std::unique_ptr<test> w(new test);

  BOOST_CHECK       ( w);

  w->position.set(p);

  BOOST_CHECK       ( p == w->position.get());
  BOOST_TEST_MESSAGE(*w);
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_xcb_window_base_size)
{
  glm::ivec2 const      s(640, 480);
  std::unique_ptr<test> w(new test);

  BOOST_CHECK       ( w);

  w->size.set(s);

  BOOST_CHECK       ( s == w->size.get());
  BOOST_TEST_MESSAGE(*w);
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_xcb_window_base_title)
{
  std::string const     t("test_hugh_platform_xcb_window_base_title");
  std::unique_ptr<test> w(new test);

  BOOST_CHECK       ( w);

  w->title.set(t);

  BOOST_CHECK       ( t == w->title.get());
  BOOST_TEST_MESSAGE(*w);
}
