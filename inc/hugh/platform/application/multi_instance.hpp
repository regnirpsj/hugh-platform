// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/application/multi_instance.hpp                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_APPLICATION_MULTI_INSTANCE_HPP)

#define HUGH_PLATFORM_APPLICATION_MULTI_INSTANCE_HPP

// includes, system

// #include <>

// includes, project

#include <hugh/platform/application/base.hpp>

namespace hugh {
  
  namespace platform {

    namespace application {
  
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_PLATFORM_EXPORT multi_instance : public base {

      protected:

        explicit multi_instance(command_line const&);
        virtual ~multi_instance();
    
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
    } // namespace application {
  
  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_APPLICATION_MULTI_INSTANCE_HPP)
