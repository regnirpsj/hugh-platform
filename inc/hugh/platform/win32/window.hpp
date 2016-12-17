// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/window.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WIN32_WINDOW_HPP)

#define HUGH_PLATFORM_WIN32_WINDOW_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/platform/window/interactive.hpp>
#include <hugh/platform/win32/window/context.hpp>
#include <hugh/platform/win32/window/input.hpp>
#include <hugh/platform/win32/window/update.hpp>

namespace hugh {

  namespace platform {

    namespace win32 {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        using simple      = platform::window::simple     <context, update>;
        using interactive = platform::window::interactive<context, update, input>;
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {
      
    } // namespace win32 {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_WIN32_WINDOW_HPP)
