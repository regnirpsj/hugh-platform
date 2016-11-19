// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/sdl/application/base.cpp                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/sdl/application/base.hpp"

// includes, system

#include <SDL.h>     // SDL_*
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

    namespace sdl {

      namespace application {
      
        // variables, exported
        
        // functions, exported

        /* virtual */
        base::~base()
        {
          TRACE("hugh::platform::sdl::application::base::~base");
          
          ::SDL_Quit();
        }
        
        /* virtual */ void
        base::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::sdl::application::base::print_on");

          platform::posix::application::base::print_on(os);

          ::SDL_version c, l;

            SDL_VERSION   (&c);
          ::SDL_GetVersion(&l);

          using support::ostream::operator<<;
          
          os << support::ostream::remove(1) << ','
             << "SDL(compiled):"
             << unsigned(c.major) << '.'
             << unsigned(c.minor) << '.'
             << unsigned(c.patch) << ','
             << "SDL(linked):"
             << unsigned(l.major) << '.'
             << unsigned(l.minor) << '.'
             << unsigned(l.patch)
             << ']';
        }
      
        /* explicit */
        base::base(platform::application::command_line const& a, bool b)
          : platform::posix::application::base(a, b)
        {
          TRACE("hugh::platform::sdl::application::base::base");

          if (0 != ::SDL_Init(SDL_INIT_EVERYTHING)) {
            std::ostringstream ostr;

            ostr << "SDL_Init error: " << ::SDL_GetError();

            throw std::runtime_error(ostr.str());
          }
        }

      } // namespace application {

    } // namespace sdl {
  
  } // namespace platform {

} // namespace hugh {
