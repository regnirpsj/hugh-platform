// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016-2017 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/posix/application/base.cpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/posix/application/base.hpp"

// includes, system

//#include <>

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

    namespace posix {

      namespace application {
      
        // variables, exported

        /* static */ bool const base::positionals(true);
        
        // functions, exported

        /* virtual */ void
        base::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::posix::application::base::print_on");

          platform::application::single_instance::print_on(os);

          using support::ostream::operator<<;
        
          os << support::ostream::remove(1) << ',' << input_files_ << ']';
        }
      
        /* explicit */
        base::base(platform::application::command_line const& a, bool b)
          : platform::application::single_instance(a),
            input_files_                          ()
        {
          TRACE("hugh::platform::posix::application::base::base");

          if (b) {
            namespace bpo = boost::program_options;
          
            bpo::options_description od("Command-Line Options");

            od.add_options()
              ("file,f",
               bpo::value(&input_files_)->composing(),
               "input file(s)\n"
               "positional arguments are accumulated as input files");

            command_line_.descriptions.add(od);
            command_line_.positionals .add("file", -1);
          }
        }

      } // namespace application {

    } // namespace posix {
  
  } // namespace platform {

} // namespace hugh {
