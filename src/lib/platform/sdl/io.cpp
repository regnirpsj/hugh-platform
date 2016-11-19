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

  template <typename T, typename S, std::size_t L>
  inline std::ostream&
  get_enum(std::ostream& os, T const& a, std::array<S, L> const& b)
  {
    std::ostream::sentry const cerberus(os);

    if (cerberus) {
      os << '[';

      if ((0 <= unsigned(a)) && (unsigned(a) < b.size())) {
        os << b[a];
      } else {
        os << "INVALID (" << unsigned(a) << ')';
      }

      os << ']';
    }

    return os;
  }
  
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
          static std::array<std::string const, 17> const events = {
            { "WINDOWEVENT_NONE",
              "WINDOWEVENT_SHOWN",
              "WINDOWEVENT_HIDDEN",
              "WINDOWEVENT_EXPOSED",
              "WINDOWEVENT_MOVED",
              "WINDOWEVENT_RESIZED",
              "WINDOWEVENT_SIZE_CHANGED",
              "WINDOWEVENT_MINIMIZED",
              "WINDOWEVENT_MAXIMIZED",
              "WINDOWEVENT_RESTORED",
              "WINDOWEVENT_ENTER",
              "WINDOWEVENT_LEAVE",
              "WINDOWEVENT_FOCUS_GAINED",
              "WINDOWEVENT_FOCUS_LOST",
              "WINDOWEVENT_CLOSE",
              "WINDOWEVENT_TAKE_FOCUS",
              "WINDOWEVENT_HIT_TEST", }
          };
          
          os << '['
             << a.type      << ','
             << a.timestamp << ','
             << a.windowID  << ',';
          
          get_enum(os, a.event, events);
          
          os << ','
             << a.data1 << ','
             << a.data2
             << ']';
        }
      
        return os;
      }
      
    } // namespace sdl {
    
  } // namespace platform {
  
} // namespace hugh {
