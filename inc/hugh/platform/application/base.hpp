// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/application/base.hpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_APPLICATION_BASE_HPP)

#define HUGH_PLATFORM_APPLICATION_BASE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <memory>                // std::unique_ptr<>

// includes, project

#include <hugh/platform/application/command_line.hpp>
#include <hugh/platform/export.h>
#include <hugh/support/printable.hpp>

namespace hugh {
  
  namespace platform {

    namespace application {
    
      // types, exported (class, enum, struct, union, typedef)
    
      class HUGH_PLATFORM_EXPORT base : private boost::noncopyable,
                                        public support::printable {

      public:

        virtual signed run() =0;
        virtual void   process_command_line();
      
        virtual void print_on(std::ostream&) const;
      
      protected:

        static bool terminate;
      
        command_line command_line_;
        unsigned     verbose_level_;
    
        explicit base(command_line const&);
        virtual ~base() =0;
      
      };
  
      template <typename T>
      class executor : private boost::noncopyable {

      public:

        explicit executor(command_line const&);
                ~executor();
      
        signed run();
    
      private:

        std::unique_ptr<T> instance_;
    
      };  
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      template <typename T> signed execute(command_line const&);
      template <typename T> signed execute(command_line const&, std::nothrow_t const&) noexcept;
    
    } // namespace application {
  
  } // namespace platform {

} // namespace hugh {

#include <hugh/platform/application/base.inl>

#endif // #if !defined(HUGH_PLATFORM_APPLICATION_BASE_HPP)
