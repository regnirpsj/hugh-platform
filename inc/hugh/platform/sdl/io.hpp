// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/sdl/io.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_SDL_IO_HPP)

#define HUGH_PLATFORM_SDL_IO_HPP

// includes, system

#include <SDL.h>  // SDL_*
#include <iosfwd> // std::ostream (fwd decl)

// includes, project

#include <hugh/platform/export.h>

namespace hugh {

  namespace platform {

    namespace sdl {
      
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
      
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::SDL_WindowEvent const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::SDL_WindowEventID const&);

    } // namespace sdl {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_SDL_IO_HPP)
