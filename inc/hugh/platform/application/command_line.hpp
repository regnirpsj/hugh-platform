// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/application/command_line.hpp                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_APPLICATION_COMMAND_LINE_HPP)

#define HUGH_PLATFORM_APPLICATION_COMMAND_LINE_HPP

// includes, system

#include <boost/program_options.hpp> // boost::program_options::options_description
#include <string>                    // std::string
#include <vector>                    // std::vector<>

// includes, project

#include <hugh/platform/export.h>
#include <hugh/support/printable.hpp>

namespace hugh {
  
  namespace platform {

    namespace application {
  
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_PLATFORM_EXPORT command_line : public support::printable {

      public:
        
        using options_description            = boost::program_options::options_description;
        using positional_options_description = boost::program_options::positional_options_description;
        using variables_map                  = boost::program_options::variables_map;

        static unsigned const line_length; // 100
        static unsigned const text_length; //  60
      
        std::string const              argv0;
        options_description            descriptions;
        variables_map                  options;
        positional_options_description positionals;
        std::vector<std::string>       unrecognized;
        
        explicit command_line(int /* argc */, char const* /* argv */[]);
      
        virtual void print_on(std::ostream&) const;
      
        void process(bool /* force re-evaluation */ = false);
      
      protected:

        std::vector<std::string> argv_;
        bool                     already_processed_;
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace application {
  
  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_APPLICATION_COMMAND_LINE_HPP)
