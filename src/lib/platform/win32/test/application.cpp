// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/test/appication.cpp                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <sstream> // std::ostringstream

// includes, project

#include <hugh/platform/win32/application/base.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  int const   argc(1);
  char const* argv[] = { "dummy" };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_platform_win32_application_execute)
{
  namespace hpa = hugh::platform::application;
  namespace hppa = hugh::platform::win32::application;
  
  using hpa::command_line;

  class app : public hppa::base {

    using inherited = hppa::base;
    
  public:

    explicit app(command_line const& a)
      : inherited(a) {}

    virtual signed run() { return EXIT_SUCCESS; }

  };

  using hpa::execute;
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_print)
{
  namespace hpa = hugh::platform::application;
  namespace hppa = hugh::platform::win32::application;
  
  using hpa::command_line;

  class app : public hppa::base {

    using inherited = hppa::base;
    
  public:

    explicit app(command_line const& a)
      : inherited(a) {}

    virtual signed run() { return EXIT_SUCCESS; }

  } instance(command_line(argc, argv));

  std::ostringstream ostr;

  ostr << instance;

  BOOST_CHECK       (!ostr.str().empty());
  BOOST_TEST_MESSAGE(ostr.str());
}
