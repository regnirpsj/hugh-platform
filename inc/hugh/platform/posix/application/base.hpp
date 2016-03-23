// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/posix/application/base.hpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_POSIX_APPLICATION_BASE_HPP)

#define HUGH_PLATFORM_POSIX_APPLICATION_BASE_HPP

// includes, system

#include <string> // std::string
#include <vector> // std::vector<>

// includes, project

#include <hugh/platform/application/single_instance.hpp>

namespace hugh {
  
  namespace platform {

    namespace posix {

      namespace application {
  
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_PLATFORM_EXPORT base : public platform::application::single_instance {

        public:

          virtual void print_on(std::ostream&) const;
      
        protected:

          using string_list_type = std::vector<std::string>;
      
          string_list_type input_files_;

          explicit base(platform::application::command_line const&);
        
        };
      
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)
  
      } // namespace application {

    } // namespace posix {
  
  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_POSIX_APPLICATION_BASE_HPP)
