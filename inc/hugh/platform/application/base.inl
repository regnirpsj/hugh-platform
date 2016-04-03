// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/application/base.inl                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_APPLICATION_BASE_INL)

#define HUGH_PLATFORM_APPLICATION_BASE_INL

// includes, system

#include <boost/exception/diagnostic_information.hpp> // 
#include <cstdlib>                                    // EXIT_FAILURE

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

    namespace application {
  
      // functions, inlined (inline)

      template <typename T>
      inline /* explicit */
      executor<T>::executor(command_line const& a)
        : boost::noncopyable(),
          instance_         (new T(a))
      {
        TRACE("hugh::platform::application::executor<" +
              support::demangle(typeid(T)) + ">::executor");

        instance_->process_command_line();
      }

      template <typename T>
      inline /* explicit */
      executor<T>::~executor()
      {
        TRACE("hugh::platform::application::executor<" +
              support::demangle(typeid(T)) + ">::~executor");
      }
    
      template <typename T>
      inline signed
      executor<T>::run()
      {
        TRACE("hugh::platform::application::executor<" +
              support::demangle(typeid(T)) + ">::run");
      
        return instance_->run();
      }

      template <typename T>
      inline signed
      execute(command_line const& a)
      {
        TRACE("hugh::platform::application::execute<" +
              support::demangle(typeid(T)) + ">");
      
        return executor<T>(a).run();
      }

      template <typename T>
      inline signed
      execute(command_line const& a, std::nothrow_t const&) noexcept
      {
        TRACE("hugh::platform::application::execute<" +
              support::demangle(typeid(T)) + ">(std::nothrow_t)");
      
        signed result(EXIT_FAILURE);
      
        try {
          result = execute<T>(a);
        }

        catch (std::system_error const& ex) {
          if (!ex.code()) {
            throw;
          }
        }
        
        catch (...) {
          std::cerr << "Unhandled exception!" << std::endl
                    << boost::current_exception_diagnostic_information();
        }
      
        return result;
      }
    
    } // namespace application {
  
  } // namespace platform {

} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_PLATFORM_APPLICATION_BASE_INL)
