// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/application/multi_instance.cpp                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/application/multi_instance.hpp"

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

    namespace application {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      multi_instance::multi_instance(command_line const& a)
        : base(a)
      {
        TRACE("hugh::platform::application::multi_instance::multi_instance");
      }

      /* virtual */
      multi_instance::~multi_instance()
      {
        TRACE("hugh::platform::application::multi_instance::~multi_instance");
      }

    } // namespace application {
  
  } // namespace platform {

} // namespace hugh {
