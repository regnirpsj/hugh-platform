// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/sdl/window.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_SDL_WINDOW_HPP)

#define HUGH_PLATFORM_SDL_WINDOW_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/platform/window/interactive.hpp>
#include <hugh/platform/sdl/window/context.hpp>
#include <hugh/platform/sdl/window/input.hpp>
#include <hugh/platform/sdl/window/update.hpp>

namespace hugh {

  namespace platform {

    namespace sdl {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        using simple      = platform::window::simple     <context, update>;
        using interactive = platform::window::interactive<context, update, input>;
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {
      
    } // namespace sdl {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_SDL_WINDOW_HPP)
