// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/manager.inl                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WINDOW_MANAGER_INL)

#define HUGH_PLATFORM_WINDOW_MANAGER_INL

// includes, system

#include <algorithm> // std::find<>
//#include <ostream>   // std::ostream

// includes, project

#include <hugh/support/io_utils.hpp>

#define HUGH_USE_TRACE
//#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>
#if defined(HUGH_USE_TRACE) || defined(HUGH_ALL_TRACE)
#  include <typeinfo>
#  include <hugh/support/type_info.hpp>
#endif

namespace hugh {

  namespace platform {

    namespace window {

      //

      template <typename T>
      /* static */ typename manager<T>::context_list_type manager<T>::context_list_;
      
      // functions, inlined (inline)

      template <typename T>
      inline /* static */ unsigned
      manager<T>::count()
      {
        TRACE("hugh::platform::window::manager<" + support::demangle(typeid(T)) + ">::count");

        return context_list_.size();
      }
      
      template <typename T>
      inline /* static */ bool
      manager<T>::empty()
      {
        TRACE("hugh::platform::window::manager<" + support::demangle(typeid(T)) + ">::empty");

        return context_list_.empty();
      }

      template <typename T>
      inline /* static */ void
      manager<T>::print_on(std::ostream& os)
      {
        TRACE_NEVER("hugh::platform::window::manager<" + support::demangle(typeid(T)) +
                    ">::print_on");

        os << '[';
      
        for (auto const& c : context_list_) {
          using support::ostream::operator<<;
        
          os << c << ',';
        }
      
        if (!context_list_.empty()) {
          os << support::ostream::remove(1);
        }

        os << ']';
      }

      template <typename T>
      inline /* static */ bool
      manager<T>::add(typename base<T>::context_type* a)
      {
        TRACE("hugh::platform::window::manager<" + support::demangle(typeid(T)) + ">::add");

        return context_list_.insert(a).second;
      }

      template <typename T>
      inline /* static */ bool
      manager<T>::sub(typename base<T>::context_type* a)
      {
        TRACE("hugh::platform::window::manager<" + support::demangle(typeid(T)) + ">::sub");

        bool       result(false);
        auto const found(std::find(context_list_.begin(), context_list_.end(), a));

        if (context_list_.end() != found) {
          context_list_.erase(found);
          
          result = true;
        }
        
        return result;
      }
      
    } // namespace window {
  
  } // namespace platform {
  
} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_PLATFORM_WINDOW_MANAGER_INL)
