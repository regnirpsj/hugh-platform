// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/simple.hpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_XCB_WINDOW_SIMPLE_HPP)

#define HUGH_PLATFORM_XCB_WINDOW_SIMPLE_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/platform/xcb/window/base.hpp>

namespace hugh {

  namespace platform {

    namespace xcb {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_PLATFORM_EXPORT simple : public base {

        public:

          using rect = base::rect;
          
          explicit simple(std::string const& /* title   */,
                          rect const&        /* rect    */ = rect::dflt_rect,
                          std::string const& /* display */ = dflt_display_name);
          virtual ~simple();
          
        private:
          
        };
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {

    } // namespace xcb {

  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_XCB_WINDOW_SIMPLE_HPP)
