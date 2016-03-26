// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/base.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/window/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<  (field::container::print_on)
#include <stdexcept>      // std::logic_error

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace platform {

    namespace window {
  
      // variables, exported
  
      // functions, exported
    
      /* explicit */
      base::base(std::string const& a, rect const& b)
        : boost::noncopyable(),
          field::container  (),
          title             (*this, "title",    a),
          position          (*this, "position", glm::ivec2((0 > b.x) ? 0 : b.x,
                                                           (0 > b.y) ? 0 : b.y)),
          size              (*this, "size",     glm::ivec2((1 > b.w) ? 1 : b.w,
                                                           (1 > b.h) ? 1 : b.h))
      {
        TRACE("hugh::platform::window::base::base");
      }

      /* virtual */ void
      base::do_changed(field::base& f)
      {
        TRACE("hugh::platform::window::base::do_changed");

        if (&f == &position) { reposition(); }
        if (&f == &size)     { resize    (); }
        if (&f == &title)    { retitle   (); }
        
        else {
          field::container::do_changed(f);
        }
      }
      
      /* virtual */ void
      base::reposition()
      {
        TRACE("hugh::platform::window::base::reposition");

        throw std::runtime_error("pure virtual function "
                                 "'hugh::platform::window::base::reposition' called");
      }
      
      /* virtual */ void
      base::resize()
      {
        TRACE("hugh::platform::window::base::resize");

        throw std::runtime_error("pure virtual function "
                                 "'hugh::platform::window::base::resize' called");
      }
      
      /* virtual */ void
      base::retitle()
      {
        TRACE("hugh::platform::window::base::retitle");

        throw std::runtime_error("pure virtual function "
                                 "'hugh::platform::window::base::retitle' called");
      }

    } // namespace window {
  
  } // namespace platform {
  
} // namespace hugh {
