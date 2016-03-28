// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_XCB_WINDOW_HPP)

#define HUGH_PLATFORM_XCB_WINDOW_HPP

// includes, system

#include <xcb/xcb.h>

// includes, project

#include <hugh/platform/window/interactive.hpp>
#include <hugh/platform/xcb/window/context.hpp>
#include <hugh/platform/xcb/window/input.hpp>
#include <hugh/platform/xcb/window/update.hpp>

namespace hugh {

  namespace platform {

    namespace xcb {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        using simple      = platform::window::simple     <context, update>;
        using interactive = platform::window::interactive<context, update, input>;
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {
      
    } // namespace xcb {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_XCB_WINDOW_HPP)
