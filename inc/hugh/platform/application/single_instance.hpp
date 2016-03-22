// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/application/single_instance.hpp                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_APPLICATION_SINGLE_INSTANCE_HPP)

#define HUGH_PLATFORM_APPLICATION_SINGLE_INSTANCE_HPP

// includes, system

// #include <>

// includes, project

#include <hugh/platform/application/base.hpp>

namespace hugh {
  
  namespace platform {

    namespace application {
  
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_PLATFORM_EXPORT single_instance : public base {

      public:
      
        static bool initialized();
      
      protected:

        static single_instance* instance_;
      
        explicit single_instance(command_line const&);
        virtual ~single_instance();

        virtual void print_on(std::ostream&) const;
    
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
    
    } // namespace application {
  
  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_APPLICATION_SINGLE_INSTANCE_HPP)
