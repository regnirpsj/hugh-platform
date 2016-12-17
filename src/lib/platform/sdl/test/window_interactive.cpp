// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/sdl/test/window_simple.cpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<  (field::container::print_on)
#include <sstream>        // std::ostringstream

// includes, project

#include <hugh/platform/sdl/window.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class window : public hugh::platform::sdl::window::interactive {

  public:

    using inherited  = hugh::platform::sdl::window::interactive;
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
        
        hugh::support::sleep(std::chrono::milliseconds(100));
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

BOOST_AUTO_TEST_CASE(test_hugh_platform_sdl_window_interactive)
{
  window w("test_platform_sdl_window_interactive",
           std::chrono::milliseconds(900),
           window::rect(50, 50, 800, 600));
  
  w.display();
  
  std::ostringstream ostr;

  ostr << w;

  BOOST_CHECK       (!ostr.str().empty());
  BOOST_TEST_MESSAGE( ostr.str());
}
