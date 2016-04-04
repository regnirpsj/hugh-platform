// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/simple.inl                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WINDOW_SIMPLE_INL)

#define HUGH_PLATFORM_WINDOW_SIMPLE_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>
#if defined(HUGH_USE_TRACE) || defined(HUGH_ALL_TRACE)
#  include <typeinfo>
#  include <hugh/support/type_info.hpp>
#endif

namespace hugh {

  namespace platform {

    namespace window {

      // functions, inlined (inline)

      template <typename C, typename U>
      inline /* explicit */
      simple<C,U>::simple(std::string const& a, rect const& b, std::string const& c)
        : inherited(a, b, c),
          update_  (inherited::context_)
      {
        TRACE("hugh::platform::window::simple<" + support::demangle(typeid(C)) + ","
              + support::demangle(typeid(U)) + ">::simple");
      }
      
      template <typename C, typename U>
      inline /* virtual */
      simple<C,U>::~simple()
      {
        TRACE("hugh::platform::window::simple<" + support::demangle(typeid(C)) + ","
              + support::demangle(typeid(U)) + ">::~simple");
      }
        
      template <typename C, typename U>
      inline /* virtual */ void
      simple<C,U>::display()
      {
        TRACE_NEVER("hugh::platform::window::simple<" + support::demangle(typeid(C)) + ","
                    + support::demangle(typeid(U)) + ">::display");

        update_();
      }
      
    } // namespace window {
  
  } // namespace platform {
  
} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_PLATFORM_WINDOW_SIMPLE_INL)
