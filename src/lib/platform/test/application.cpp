// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/test/application.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <hugh/platform/application/multi_instance.hpp>
#include <hugh/platform/application/single_instance.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

#if defined(_MSC_VER)
#  pragma warning(push)
    // warning C4127: conditional expression is constant
#  pragma warning(disable:4127) 
#endif

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  template <typename T, bool B>
  class app_skeleton : public T {

  public:

    using command_line = hugh::platform::application::command_line;
    
    explicit app_skeleton(command_line const& a)
      : T(a)
    {}

    virtual signed run()
    {
      if (B) {
        throw std::runtime_error("run-time error");
      }

      return EXIT_SUCCESS;
    }
    
  };

  using appmin = app_skeleton<hugh::platform::application::multi_instance,  false>;
  using appmit = app_skeleton<hugh::platform::application::multi_instance,  true>;
  using appsin = app_skeleton<hugh::platform::application::single_instance, false>;
  using appsit = app_skeleton<hugh::platform::application::single_instance, true>;  

  // variables, internal

  int const   argc(1);
  char const* argv[] = { "dummy" };

  // functions, internal

} // namespace {

#if defined(_MSC_VER)
#  pragma warning(pop)
#endif

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_execute)
{
  namespace hpa = hugh::platform::application;
  
  using hpa::command_line;
  using hpa::execute;

  BOOST_CHECK(EXIT_SUCCESS == execute<appmin>(command_line(argc, argv)));
  BOOST_CHECK(EXIT_SUCCESS == execute<appsin>(command_line(argc, argv)));
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_execute_nothrow)
{
  namespace hpa = hugh::platform::application;
  
  using hpa::command_line;
  using hpa::execute;

  BOOST_CHECK(EXIT_SUCCESS != execute<appmit>(command_line(argc, argv), std::nothrow));
  BOOST_CHECK(EXIT_SUCCESS != execute<appsit>(command_line(argc, argv), std::nothrow));
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_execute_single_instance_fail)
{
  namespace hpa = hugh::platform::application;
  
  using hpa::command_line;
  using hpa::single_instance;

  class single_inst_fail : public single_instance {

  public:

    explicit single_inst_fail(command_line const& a)
      : single_instance(a) {}

    virtual signed run() { return EXIT_SUCCESS; }

  } instance(command_line(argc, argv));

  using hpa::execute;

  BOOST_CHECK_THROW(execute<single_inst_fail>(command_line(argc, argv)), std::exception);
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_execute_single_instance_fail_nothrow)
{
  namespace hpa = hugh::platform::application;
  
  using hpa::command_line;
  using hpa::single_instance;

  class single_inst_fail : public single_instance {

  public:

    explicit single_inst_fail(command_line const& a)
      : single_instance(a) {}

    virtual signed run() { return EXIT_SUCCESS; }

  } instance(command_line(argc, argv));

  using hpa::execute;

  BOOST_CHECK(EXIT_SUCCESS != execute<single_inst_fail>(command_line(argc, argv), std::nothrow));
}
