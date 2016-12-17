// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/utilities.hpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WIN32_UTILITIES_HPP)

#define HUGH_PLATFORM_WIN32_UTILITIES_HPP

// includes, system

#include <string>    // std::string
#include <windows.h> // win32 stuff

// includes, project

#include <hugh/platform/export.h>

namespace hugh {
  
  namespace platform {
    
    namespace win32 {
      
      // types, exported (class, enum, struct, union, typedef)
      
      // variables, exported (extern)
      
      // functions, inlined (inline)
      
      template <class T> T  window_long (HWND, signed);
      template <class T> T  window_long (HWND, T, signed);
      
      template <class T> T* window_long_ptr(HWND, signed);
      template <class T> T* window_long_ptr(HWND, T*, signed);
      
      template <class T> T  class_long (HWND, signed);
      template <class T> T  class_long (HWND, T, signed);
      
      template <class T> T* class_long_ptr(HWND, signed);
      template <class T> T* class_long_ptr(HWND, T*, signed);
      
      // functions, exported (extern)
      
      HUGH_PLATFORM_EXPORT std::string basename(std::string const&);
      HUGH_PLATFORM_EXPORT std::string message_string(unsigned);
      HUGH_PLATFORM_EXPORT std::string module_path(HMODULE);
      HUGH_PLATFORM_EXPORT std::string last_error_message();
      
    } // namespace win32 {
    
  } // namespace platform {
  
} // namespace hugh {

#include <hugh/platform/win32/utilities.inl>

#endif // #if !defined(HUGH_PLATFORM_WIN32_UTILITIES_HPP)
