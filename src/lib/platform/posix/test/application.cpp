// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/posix/test/appication.cpp                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <hugh/platform/posix/application/base.hpp>

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

BOOST_AUTO_TEST_CASE(test_hugh_platform_posix_application_execute)
{
  namespace hpa = hugh::platform::application;
  
  using hpa::command_line;

  class app : public hpa::base {

    using inherited = hpa::base;
    
  public:

    explicit app(command_line const& a)
      : inherited(a) {}

    virtual signed run() { return EXIT_SUCCESS; }

  };

  using hpa::execute;
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}
