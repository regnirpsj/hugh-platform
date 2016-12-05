// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/sdl/io.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/sdl/io.hpp"

// includes, system

#include <array>   // std::array<>
#include <ostream> // std::ostream
#include <string>  // std:string
#include <utility> // std::make_pair<>, std::pair<>

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
      
      // variables, exported
  
      // functions, exported

      std::ostream&
      operator<<(std::ostream& os, ::SDL_WindowEvent const& a)
      {
        std::ostream::sentry const cerberus(os);
        
        if (cerberus) {
          os << '['
             << a.type      << ','
             << a.timestamp << ','
             << a.windowID  << ','
             << a.event     << ','
             << a.data1     << ','
             << a.data2
             << ']';
        }
        
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, ::SDL_WindowEventID const& a)
      {
#if SDL_VERSION_ATLEAST(2, 0, 5)
        static unsigned const size(17);
#else
        static unsigned const size(15);
#endif
                            
        static std::array<std::pair<::SDL_WindowEventID const, std::string const>, size> const
          types = {
          std::make_pair(SDL_WINDOWEVENT_NONE, "WINDOWEVENT_NONE"),
          std::make_pair(SDL_WINDOWEVENT_SHOWN, "WINDOWEVENT_SHOWN"),
          std::make_pair(SDL_WINDOWEVENT_HIDDEN, "WINDOWEVENT_HIDDEN"),
          std::make_pair(SDL_WINDOWEVENT_EXPOSED, "WINDOWEVENT_EXPOSED"),
          std::make_pair(SDL_WINDOWEVENT_MOVED, "WINDOWEVENT_MOVED"),
          std::make_pair(SDL_WINDOWEVENT_RESIZED, "WINDOWEVENT_RESIZED"),
          std::make_pair(SDL_WINDOWEVENT_SIZE_CHANGED, "WINDOWEVENT_SIZE_CHANGED"),
          std::make_pair(SDL_WINDOWEVENT_MINIMIZED, "WINDOWEVENT_MINIMIZED"),
          std::make_pair(SDL_WINDOWEVENT_MAXIMIZED, "WINDOWEVENT_MAXIMIZED"),
          std::make_pair(SDL_WINDOWEVENT_RESTORED, "WINDOWEVENT_RESTORED"),
          std::make_pair(SDL_WINDOWEVENT_ENTER, "WINDOWEVENT_ENTER"),
          std::make_pair(SDL_WINDOWEVENT_LEAVE, "WINDOWEVENT_LEAVE"),
          std::make_pair(SDL_WINDOWEVENT_FOCUS_GAINED, "WINDOWEVENT_FOCUS_GAINED"),
          std::make_pair(SDL_WINDOWEVENT_FOCUS_LOST, "WINDOWEVENT_FOCUS_LOST"),
          std::make_pair(SDL_WINDOWEVENT_CLOSE, "WINDOWEVENT_CLOSE"),
#if SDL_VERSION_ATLEAST(2, 0, 5)
          std::make_pair(SDL_WINDOWEVENT_TAKE_FOCUS, "WINDOWEVENT_TAKE_FOCUS"),
          std::make_pair(SDL_WINDOWEVENT_HIT_TEST, "WINDOWEVENT_HIT_TEST"),
#endif
        };

        return os << support::ostream::enumerate(a, types);
      }      
      
    } // namespace sdl {
    
  } // namespace platform {
  
} // namespace hugh {
