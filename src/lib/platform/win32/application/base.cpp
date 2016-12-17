// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/application/base.cpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/win32/application/base.hpp"

// includes, system

#include <sstream>   // std::ostringstream
#include <stdexcept> // std::runtime_error

// includes, project

#include <hugh/support/io_utils.hpp>

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

      namespace application {
      
        // variables, exported
        
        // functions, exported

        /* virtual */
        base::~base()
        {
          TRACE("hugh::platform::win32::application::base::~base");
        }
        
        /* virtual */ void
        base::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::win32::application::base::print_on");

          platform::posix::application::base::print_on(os);
        }
      
        /* explicit */
        base::base(platform::application::command_line const& a, bool b)
          : platform::posix::application::base(a, b)
        {
          TRACE("hugh::platform::win32::application::base::base");
        }

      } // namespace application {

    } // namespace win32 {
  
  } // namespace platform {

} // namespace hugh {
