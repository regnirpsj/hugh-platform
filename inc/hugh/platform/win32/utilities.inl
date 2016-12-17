// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/utilities.inl                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WIN32_UTILITIES_INL)

#define HUGH_PLATFORM_WIN32_UTILITIES_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>
//#if defined(HUGH_USE_TRACE) || defined(HUGH_ALL_TRACE)
//#  include <typeinfo>
//#  include <hugh/support/type_info.hpp>
//#endif

namespace hugh {
  
  namespace platform {
    
    namespace win32 {
      
      // functions, inlined (inline)
      
      template <typename T>
      inline T
      window_long(HWND a, signed b)
      {
        return reinterpret_cast<T>(::GetWindowLong(a, b));
      }

      template <typename T>
      inline T
      window_long(HWND a, T b, signed c)
      {
        return reinterpret_cast<T>(::SetWindowLong(a, c, reinterpret_cast<LONG>(b)));
      }

      template <typename T>
      inline T*
      window_long_ptr(HWND a, signed b)
      {
        return reinterpret_cast<T*>(::GetWindowLongPtr(a, b));
      }

      template <typename T>
      inline T*
      window_long_ptr(HWND a, T* b, signed c)
      {
        return reinterpret_cast<T*>(::SetWindowLongPtr(a, c, reinterpret_cast<LONG_PTR>(b)));
      }

      template <>
      inline DWORD
      window_long<DWORD>(HWND a, signed b)
      {
        return static_cast<DWORD>(::GetWindowLong(a, b));
      }

      template <>
      inline DWORD
      window_long<DWORD>(HWND a, DWORD b, signed c)
      {
        return static_cast<DWORD>(::SetWindowLong(a, c, static_cast<LONG>(b)));
      }

      template <typename T>
      inline T
      class_long(HWND a, signed b)
      {
        return reinterpret_cast<T>(::GetClassLong(a, b));
      }

      template <typename T>
      inline T
      class_long(HWND a, T b, signed c)
      {
        return reinterpret_cast<T>(::SetClassLong(a, c, reinterpret_cast<LONG>(b)));
      }

      template <typename T>
      inline T*
      class_long_ptr(HWND a, signed b)
      {
        return reinterpret_cast<T*>(::GetClassLongPtr(a, b));
      }

      template <typename T>
      inline T*
      class_long_ptr(HWND a, T* b, signed c)
      {
        return reinterpret_cast<T*>(::SetClassLongPtr(a, c, reinterpret_cast<LONG_PTR>(b)));
      }

      template <>
      inline DWORD
      class_long<DWORD>(HWND a, signed b)
      {
        return static_cast<DWORD>(::GetClassLong(a, b));
      }

      template <>
      inline DWORD
      class_long<DWORD>(HWND a, DWORD b, signed c)
      {
        return static_cast<DWORD>(::SetClassLong(a, c, static_cast<LONG>(b)));
      }

    } // namespace win32 {

  } // namespace platform {
  
} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_PLATFORM_WIN32_UTILITIES_INL)
