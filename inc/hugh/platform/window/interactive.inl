// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/interactive.inl                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WINDOW_INTERACTIVE_INL)

#define HUGH_PLATFORM_WINDOW_INTERACTIVE_INL

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

      template <typename C, typename U, typename I>
      inline /* explicit */
      interactive<C,U,I>::interactive(std::string const& a, rect const& b, std::string const& c)
        : inherited(a, b, c),
          input_  (inherited::context_)
      {
        TRACE("hugh::platform::window::interactive<" + support::demangle(typeid(C)) + "," +
              support::demangle(typeid(U)) + "," + support::demangle(typeid(I)) + ">::interactive");
      }
      
      template <typename C, typename U, typename I>
      inline /* virtual */
      interactive<C,U,I>::~interactive()
      {
        TRACE("hugh::platform::window::interactive<" + support::demangle(typeid(C)) + ","
              + support::demangle(typeid(U)) + "," + support::demangle(typeid(I)) +
              ">::~interactive");
      }
        
      template <typename C, typename U, typename I>
      inline /* virtual */ void
      interactive<C,U,I>::display()
      {
        TRACE_NEVER("hugh::platform::window::interactive<" + support::demangle(typeid(C)) + ","
                    + support::demangle(typeid(U)) + "," + support::demangle(typeid(I)) +
                    ">::display");

        input_            ();
        inherited::display();
      }
      
    } // namespace window {
  
  } // namespace platform {
  
} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_PLATFORM_WINDOW_INTERACTIVE_INL)
