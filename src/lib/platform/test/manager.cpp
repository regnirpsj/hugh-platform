// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/test/manager.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)
#include <memory>         // std::unique_ptr<>

// includes, project

#include <hugh/platform/window/manager.hpp>
#include <hugh/platform/window/base.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  namespace hpw = hugh::platform::window;
  
  template <hpw::manager::window_type T>
  class window : public hpw::base {

  public:

    class manager : public hpw::manager {

    public:

      static bool add(signed a, base* b)
      {
        return hpw::manager::add(T, a, b);
      }

      static bool sub(base* a)
      {
        return hpw::manager::sub(T, a);
      }
      
    };
    
    explicit window()
      : hpw::base("dummy")
    {
      manager::add(-1, this);
    }

    virtual ~window()
    {
      manager::sub(this);
    }

  protected:

    virtual void reposition() {}
    virtual void resize()     {}
    virtual void retitle()    {}
    
  };

  using window_win32 = window<hpw::manager::window_type::win32>;
  using window_xcb   = window<hpw::manager::window_type::xcb>;

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_platform_window_ctor)
{
  namespace hpw = hugh::platform::window;

  BOOST_CHECK(0 == hpw::manager::count());
  
  {
    std::unique_ptr<hpw::base> const w(new window_win32);

    BOOST_CHECK(nullptr != w);
    BOOST_CHECK(1 == hpw::manager::count());
    BOOST_CHECK(1 == hpw::manager::count(hpw::manager::window_type::win32));
  }
  
  {
    std::unique_ptr<hpw::base> const w(new window_xcb);

    BOOST_CHECK(nullptr != w);
    BOOST_CHECK(1 == hpw::manager::count());
    BOOST_CHECK(1 == hpw::manager::count(hpw::manager::window_type::xcb));
  }

  {
    std::unique_ptr<hpw::base> const w1(new window_win32);

    BOOST_CHECK(nullptr != w1);
    BOOST_CHECK(1 == hpw::manager::count());
    BOOST_CHECK(1 == hpw::manager::count(hpw::manager::window_type::win32));

    {
      std::unique_ptr<hpw::base> const w2(new window_xcb);

      BOOST_CHECK(nullptr != w2);
      BOOST_CHECK(2 == hpw::manager::count());
      BOOST_CHECK(1 == hpw::manager::count(hpw::manager::window_type::win32));
      BOOST_CHECK(1 == hpw::manager::count(hpw::manager::window_type::xcb));
    }

    BOOST_CHECK(1 == hpw::manager::count());
    BOOST_CHECK(1 == hpw::manager::count(hpw::manager::window_type::win32));
  }
  
  BOOST_CHECK(0 == hpw::manager::count());
}
