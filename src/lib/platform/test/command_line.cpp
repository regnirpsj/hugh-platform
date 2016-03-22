// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/test/command_line.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <hugh/platform/application/command_line.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  namespace bpo = boost::program_options;

  class description {

  public:

    description()
      : descr_("Options"),
        value_(0)
    {
      descr_.add_options()
        ("argv1,1",
         "arg #1");
      
      descr_.add_options()
        ("argv2,2",
         bpo::value<signed>(&value_)
         ->implicit_value(value_ + 1)
         ->default_value (value_),
         "arg #2 /w value");
      
      descr_.add_options()
        ("argv3,3",
         "arg #3");
    }

    operator bpo::options_description const& () const
    {
      return descr_;
    }
    
  private:

    bpo::options_description descr_;
    signed                   value_;
    
  };
  
  // variables, internal
  
  int const   argc(5);
  char const* argv[] = { "argv0", "-1", "--argv2", "1", "--argv3" };
  
  // functions, internal
  
} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_application_command_line_ctor)
{
  using hugh::platform::application::command_line;

  command_line c(argc, argv);

  c.descriptions.add(description());

  BOOST_CHECK       (argv[0] == c.argv0);
  BOOST_TEST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_platform_application_command_line_process)
{
  using hugh::platform::application::command_line;

  command_line c(argc, argv);

  c.descriptions.add(description());
  
#if defined(WIN32)
  BOOST_REQUIRE_THROW(c.process(), std::exception);
#else
  c.process();
#endif
  
  BOOST_CHECK       (argv[0] == c.argv0);
  BOOST_TEST_MESSAGE(c);
}
