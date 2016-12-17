// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/io.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WIN32_IO_HPP)

#define HUGH_PLATFORM_WIN32_IO_HPP

// includes, system

#include <iosfwd>    // std::ostream (fwd decl)
#include <windows.h> // win32 stuff

// includes, project

#include <hugh/platform/export.h>

namespace hugh {

  namespace platform {

    namespace win32 {
      
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
      
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, DEVMODE const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, DISPLAY_DEVICE const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, HWND const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, LUID const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, MONITORINFOEX const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, RECT const&);
      
    } // namespace win32 {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_WIN32_IO_HPP)
