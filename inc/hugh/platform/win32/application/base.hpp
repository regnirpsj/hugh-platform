// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/application/base.hpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WIN32_APPLICATION_BASE_HPP)

#define HUGH_PLATFORM_WIN32_APPLICATION_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/platform/posix/application/base.hpp>

namespace hugh {
  
  namespace platform {

    namespace win32 {

      namespace application {
  
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_PLATFORM_EXPORT base : public platform::posix::application::base {

        public:

          using command_line = platform::application::command_line;

          virtual ~base();
          
          virtual void print_on(std::ostream&) const;
      
        protected:

          explicit base(command_line const& /* argc/argv            */,
                        bool                /* positionals as files */ = positionals);
        
        };
      
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)
  
      } // namespace application {

    } // namespace win32 {
  
  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_WIN32_APPLICATION_BASE_HPP)
