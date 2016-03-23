// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/simple.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/xcb/window/simple.hpp"

// includes, system

//#include <>

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

    namespace xcb {

      namespace window {
        
        // variables, exported
  
        // functions, exported

        /* explicit */
        simple::simple(std::string const& a, rect const& b, std::string const& c)
          : base(a, b, c)
        {
          TRACE("hugh::platform::xcb::window::simple::simple");
        }
        
        /* virtual */
        simple::~simple()
        {
          TRACE("hugh::platform::xcb::window::simple::~simple");
        }
        
      } // namespace window {

    } // namespace xcb {

  } // namespace platform {
  
} // namespace hugh {
