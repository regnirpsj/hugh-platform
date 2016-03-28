// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/input.hpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_XCB_WINDOW_INPUT_HPP)

#define HUGH_PLATFORM_XCB_WINDOW_INPUT_HPP

// includes, system

#include <iosfwd> // std::ostream (fwd decl)

// includes, project

#include <hugh/platform/export.h>
#include <hugh/support/printable.hpp>

namespace hugh {

  namespace platform {

    namespace xcb {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        class context;
        
        class HUGH_PLATFORM_EXPORT input : public support::printable {

        public:

          explicit input(context&);
          virtual ~input();

          virtual void print_on(std::ostream&) const;
          
          void operator()();
      
        protected:

          context& ctx_;
      
        };
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {
      
    } // namespace xcb {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_XCB_WINDOW_INPUT_HPP)
