// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/window/context.hpp                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WIN32_WINDOW_CONTEXT_HPP)

#define HUGH_PLATFORM_WIN32_WINDOW_CONTEXT_HPP

// includes, system

#include <glm/glm.hpp> // glm::*
#include <string>      // std::string
#include <windows.h>   // win32 stuff

// includes, project

#include <hugh/platform/export.h>
#include <hugh/platform/window/rect.hpp>
#include <hugh/support/printable.hpp>

namespace hugh {

  namespace platform {

    namespace win32 {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        class input;
        class update;
        
        class HUGH_PLATFORM_EXPORT context : public support::printable {
    
        public:
    
          using rect = platform::window::rect;

          static std::string const dflt_display_name; // ???
          
          explicit context(std::string const& /* title   */,
                           rect const&        /* rect    */ = rect::dflt_rect,
                           std::string const& /* display */ = dflt_display_name);
          virtual ~context();

          virtual void print_on(std::ostream&) const;
                  
          glm::uvec2 const&  position() const;
          glm::uvec2         position(glm::uvec2 const& a);
          glm::uvec2 const&  size() const;
          glm::uvec2         size(glm::uvec2 const& a);
          std::string const& title() const;
          std::string        title(std::string const& a);

        protected:

          friend class input;
          friend class update;
          
          std::string title_;
          glm::uvec2  position_;
          glm::uvec2  size_;
          HWND        window_;
          
        };
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {
      
    } // namespace win32 {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_WIN32_WINDOW_CONTEXT_HPP)
