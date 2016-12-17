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

#include <memory>  // std::unique_ptr<>
#include <sstream> // std::ostringstream

// includes, project

#include <hugh/platform/win32/application/base.hpp>
#include <hugh/platform/win32/window.hpp>

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
  namespace hpa  = hugh::platform::application;
  namespace hpw  = hugh::platform::window;
  namespace hpwa = hugh::platform::win32::application;
  namespace hpww = hugh::platform::win32::window;
    
  using hpa::command_line;

  class app : public hpwa::base {

    using inherited = hpwa::base;
    
  public:

    using time_point = hugh::support::clock::time_point;

    explicit app(command_line const& a)
      : inherited(a),
        window_  (nullptr),
        start_   (hugh::support::clock::now())
    {
      TRACE("app::app");
    }

    virtual signed run()
    {
      TRACE("app::run");
      
      window_.reset(new hpww::simple("", hpw::rect::dflt_rect, ""));

      return message_loop(message::peek);
    }

    virtual void update()
    {
      TRACE("app::update");
      
      if (std::chrono::milliseconds(10) < (hugh::support::clock::now() - start_)) {
        terminate = true;
      }

      window_->display();
    }
    
  private:

    std::unique_ptr<hpww::simple> window_;
    time_point const              start_;
    
  };

  using hpa::execute;
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}

BOOST_AUTO_TEST_CASE(test_hugh_platform_application_print)
{
  namespace hpa = hugh::platform::application;
  namespace hpwa = hugh::platform::win32::application;
  
  using hpa::command_line;

  class app : public hpwa::base {

    using inherited = hpwa::base;
    
  public:

    explicit app(command_line const& a)
      : inherited(a) { TRACE("app::app"); }

    virtual signed run() { TRACE("app::run"); return EXIT_SUCCESS; }

  } instance(command_line(argc, argv));

  std::ostringstream ostr;

  ostr << instance;

  BOOST_CHECK       (!ostr.str().empty());
  BOOST_TEST_MESSAGE(ostr.str());
}
