// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/window/update.cpp                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/win32/window/update.hpp"

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
        update::update(context& a)
          : support::printable(),
            ctx_              (a)
        {
          TRACE("hugh::platform::win32::window::update::update");
        }

        /* virtual */
        update::~update()
        {
          TRACE("hugh::platform::win32::window::update::~update");
        }

        /* virtual */ void
        update::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::win32::window::update::print_on");
          
          os << '['
             << ctx_
             << ']';
        }
        
        void
        update::operator()()
        {
          TRACE("hugh::platform::win32::window::update::operator()");
        }
        
      } // namespace window {
      
    } // namespace win32 {
    
  } // namespace platform {

} // namespace hugh {
