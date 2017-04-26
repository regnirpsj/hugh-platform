// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016-2017 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/application/single_instance.cpp                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/application/single_instance.hpp"

// includes, system

#include <ostream> // std::ostream

// includes, project

#include <hugh/support/io.hpp>

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

      /* static */ single_instance* single_instance::instance_(nullptr);
    
      // functions, exported

      /* static */ bool
      single_instance::initialized()
      {
        TRACE("hugh::platform::application::single_instance::initialized");
      
        return nullptr != instance_;
      }
    
      /* explicit */
      single_instance::single_instance(command_line const& a)
        : base(a)
      {
        TRACE("hugh::platform::application::single_instance::single_instance");

        if (!instance_) {
          instance_ = this;
        } else {
          throw std::logic_error("'hugh::platform::application::single_instance' "
                                 "already initialized");
        }
      }

      /* virtual */
      single_instance::~single_instance()
      {
        TRACE("hugh::platform::application::single_instance::~single_instance");

        if (this == instance_) {
          instance_ = nullptr;
        }
      }

      /* virtual */ void
      single_instance::print_on(std::ostream& os) const
      {
        TRACE_NEVER("hugh::platform::application::single_instance::print_on");

        base::print_on(os);

        os << support::ostream::remove(1) << ",@" << instance_ << ']';
      }
    
    } // namespace application {
  
  } // namespace platform {

} // namespace hugh {
