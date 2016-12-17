// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/window/input.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/win32/window/input.hpp"

// includes, system

#include <ostream> // std::ostream

// includes, project

#include <hugh/platform/win32/io.hpp>
#include <hugh/platform/win32/window/context.hpp>

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

    namespace win32 {

      namespace window {
        
        // variables, exported

        // functions, exported

        /* explicit */
        input::input(context& a)
          : support::printable(),
            ctx_              (a)
        {
          TRACE("hugh::platform::win32::window::input::input");
        }

        /* virtual */
        input::~input()
        {
          TRACE("hugh::platform::win32::window::input::~input");
        }

        /* virtual */ void
        input::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::win32::window::input::print_on");

          os << '['
             << ctx_
             << ']';
        }
        
        void
        input::operator()()
        {
          TRACE("hugh::platform::win32::window::input::operator()");
        }
        
      } // namespace window {
      
    } // namespace win32 {
    
  } // namespace platform {

} // namespace hugh {
