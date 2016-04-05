// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/test/window_simple.cpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<  (field::container::print_on)
#include <sstream>        // std::ostringstream

// includes, project

#include <hugh/platform/xcb/window.hpp>

#define HUGH_USE_TRACE
//#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class window : public hugh::platform::xcb::window::simple {

  public:

    using inherited  = hugh::platform::xcb::window::simple;
    using rect       = hugh::platform::window::rect;
    using duration   = hugh::support::clock::duration;
    using time_point = hugh::support::clock::time_point;
    
    explicit window(std::string const& a,
                    duration const&    b = std::chrono::seconds(1),
                    rect const&        c = rect::dflt_rect,
                    std::string const& d = std::string())
      : inherited(a, c, d),
        duration_(b),
        start_   (hugh::support::clock::now())
    {
      TRACE("<unnamed>::window::window");
    }

    virtual void display()
    {
      TRACE("<unnamed>::window::display");
      
      while (duration_ > (hugh::support::clock::now() - start_)) {
        inherited::display();

        hugh::support::sleep(std::chrono::milliseconds(250));
      }
    }

  private:

    duration const   duration_;
    time_point const start_;
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_platform_xcb_window_simple)
{
  window w("test_platform_xcb_window_simple",
           std::chrono::milliseconds(900),
           window::rect(10, 10, 800, 600));
  
  w.display();

  std::ostringstream ostr;

  ostr << w;

  BOOST_CHECK       (!ostr.str().empty());
  BOOST_TEST_MESSAGE( ostr.str());
}
