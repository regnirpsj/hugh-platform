// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016-2017 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/test/command_line.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <sstream> // std::ostringstream

// includes, project

#include <hugh/platform/application/command_line.hpp>
#include <hugh/support/io.hpp>

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

      descr_.add_options()
        ("argv4,4",
         "arg #4");

      descr_.add_options()
        ("argv5,5",
         "arg #5");
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
  char const* argv[] = { "argv0", "-1", "-argv2 0", "-argv3", "-45" };
  
  // functions, internal
  
} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_command_line_ctor)
{
  using hugh::platform::application::command_line;

  command_line c(argc, argv);

  c.descriptions.add(description());

  BOOST_CHECK       (argv[0] == c.argv0);
  BOOST_TEST_MESSAGE('\n' << c);
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_command_line_process)
{
  using hugh::platform::application::command_line;

  command_line c(argc, argv);

  c.descriptions.add(description());
  c.process         ();
  
  BOOST_CHECK       (argv[0] == c.argv0);
  BOOST_TEST_MESSAGE('\n' << c);
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_command_line_exception)
{
  int const   argc(6);
  char const* argv[] = { "argv0", "-1", "--argv2", "1", "-argv3", "-1" };
  
  using hugh::platform::application::command_line;

  command_line c(argc, argv);

  c.descriptions.add(description());
  
  BOOST_REQUIRE_THROW(c.process(), std::exception);
  
  BOOST_CHECK       (argv[0] == c.argv0);
  BOOST_TEST_MESSAGE('\n' << c);
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_command_line_unrecognized)
{
  int const   argc(8);
  char const* argv[] = { "argv0", "-1", "-argv2", "-x", "-y=x", "--z", "/?", "-x 1,-2" };
  
  using hugh::platform::application::command_line;

  command_line c(argc, argv);

  c.descriptions.add(description());
  c.process         ();
  
  BOOST_CHECK(5 == c.unrecognized.size());
  
  {
    using hugh::support::ostream::operator<<;

    std::ostringstream ostr;

    ostr << '\n' << c << '\n' << "unrecognized:" << c.unrecognized;
    
    BOOST_TEST_MESSAGE(ostr.str());
  }
}
