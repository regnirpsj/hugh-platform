// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/input.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/xcb/window/input.hpp"

// includes, system

#include <ostream> // std::ostream

// includes, project

#include <hugh/platform/xcb/window/context.hpp>

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

    namespace xcb {

      namespace window {
        
        // variables, exported

        // functions, exported

        /* explicit */
        input::input(context& a)
          : support::printable(),
            ctx_              (a)
        {
          TRACE("hugh::platform::xcb::window::input::input");
        }

        /* virtual */
        input::~input()
        {
          TRACE("hugh::platform::xcb::window::input::~input");
        }

        /* virtual */ void
        input::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::xcb::window::input::print_on");

          os << '['
             << ctx_
             << ']';
        }
        
        void
        input::operator()()
        {
          TRACE("hugh::platform::xcb::window::input::operator()");
        }
  
      } // namespace window {
      
    } // namespace xcb {
    
  } // namespace platform {

} // namespace hugh {
