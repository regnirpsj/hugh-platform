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
#include <memory>         // std::unique_ptr<>

// includes, project

// #include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

#include <shared.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal

  hugh::platform::window::rect const dflt_rect(10, 10, 640, 480);
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

using window_types = boost::mpl::list<hugh::platform::window::test::simple,
                                      hugh::platform::window::test::interactive>;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_hugh_platform_window_ctor, W, window_types)
{
  TRACE_FUNC;
  
  std::string const  t("ws<" + hugh::support::demangle(typeid(W)) + ">");
  std::unique_ptr<W> w(new W(t, dflt_rect));
  
  BOOST_CHECK(w);

  w->display();
  
  BOOST_CHECK(t                     == *w->title);
  BOOST_CHECK(unsigned(dflt_rect.x) ==  w->position->x);
  BOOST_CHECK(unsigned(dflt_rect.y) ==  w->position->y);
  BOOST_CHECK(unsigned(dflt_rect.w) ==  w->size->x);
  BOOST_CHECK(unsigned(dflt_rect.h) ==  w->size->y);
  
  BOOST_TEST_MESSAGE(*w);
}

using window_types = boost::mpl::list<hugh::platform::window::test::simple,
                                      hugh::platform::window::test::interactive>;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_hugh_platform_window_fields, W, window_types)
{
  TRACE_FUNC;
  
  std::string const  t("ws<" + hugh::support::demangle(typeid(W)) + ">");
  std::unique_ptr<W> w(new W(t, dflt_rect));
  
  BOOST_CHECK(w);

  {
    std::string const t(hugh::support::demangle(typeid(W)));
    
    w->title.set(t);
    
    BOOST_CHECK(t == *w->title);
  }

  {
    hugh::platform::window::rect const r(0, 0, 1600, 900);
    
    w->position.set(glm::uvec2(r.x, r.y));
    w->size    .set(glm::uvec2(r.w, r.h));
  
    BOOST_CHECK(unsigned(r.x) ==  w->position->x);
    BOOST_CHECK(unsigned(r.y) ==  w->position->y);
    BOOST_CHECK(unsigned(r.w) ==  w->size->x);
    BOOST_CHECK(unsigned(r.h) ==  w->size->y);
  }
  
  BOOST_TEST_MESSAGE(*w);
}
