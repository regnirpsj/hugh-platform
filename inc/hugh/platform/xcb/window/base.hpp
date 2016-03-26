// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/base.hpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_XCB_WINDOW_BASE_HPP)

#define HUGH_PLATFORM_XCB_WINDOW_BASE_HPP

// includes, system

#include <xcb/xcb.h>

// includes, project

#include <hugh/platform/window/base.hpp>

namespace hugh {

  namespace platform {

    namespace xcb {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_PLATFORM_EXPORT base : public platform::window::base {

        public:

          using rect = platform::window::rect;

          static std::string const dflt_display_name; // getenv(DISPLAY) || ":0"
          
          virtual ~base();

          virtual void print_on(std::ostream&) const;
        
        protected:

          xcb_connection_t* connection_;
          xcb_screen_t*     screen_;
          xcb_window_t      window_;
          xcb_gcontext_t    context_;
          
          explicit base(std::string const& /* title   */,
                        rect const&        /* rect    */ = rect::dflt_rect,
                        std::string const& /* display */ = dflt_display_name);

          virtual void reposition();
          virtual void resize();
          virtual void retitle();
        
        };
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {

    } // namespace xcb {

  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_XCB_WINDOW_BASE_HPP)
