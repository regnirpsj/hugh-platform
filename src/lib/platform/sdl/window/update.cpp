// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/sdl/window/update.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/sdl/window/update.hpp"

// includes, system

#include <ostream> // std::ostream

// includes, project

#include <hugh/platform/sdl/io.hpp>
#include <hugh/platform/sdl/window/context.hpp>

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

    namespace sdl {

      namespace window {
        
        // variables, exported

        // functions, exported
        
        /* explicit */
        update::update(context& a)
          : support::printable(),
            ctx_              (a)
        {
          TRACE("hugh::platform::sdl::window::update::update");
        }

        /* virtual */
        update::~update()
        {
          TRACE("hugh::platform::sdl::window::update::~update");
        }

        /* virtual */ void
        update::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::sdl::window::update::print_on");
          
          os << '['
             << ctx_
             << ']';
        }
        
        void
        update::operator()()
        {
          TRACE("hugh::platform::sdl::window::update::operator()");
        }
        
      } // namespace window {
      
    } // namespace sdl {
    
  } // namespace platform {

} // namespace hugh {
