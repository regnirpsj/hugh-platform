// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/update.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/xcb/window/update.hpp"

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
        update::update(context& a)
          : support::printable(),
            ctx_              (a)
        {
          TRACE("hugh::platform::xcb::window::update::update");
        }

        /* virtual */
        update::~update()
        {
          TRACE("hugh::platform::xcb::window::update::~update");
        }

        /* virtual */ void
        update::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::xcb::window::update::print_on");
          
          os << '['
             << ctx_
             << ']';
        }
        
        void
        update::operator()()
        {
          TRACE("hugh::platform::xcb::window::update::operator()");
        }
  
      } // namespace window {
      
    } // namespace xcb {
    
  } // namespace platform {

} // namespace hugh {
