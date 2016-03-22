// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/rect.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WINDOW_RECT_HPP)

#define HUGH_PLATFORM_WINDOW_RECT_HPP

// includes, system

#include <glm/glm.hpp> // glm::ivec2
#include <iosfwd>      // std::ostream (fwd)

// includes, project

#include <hugh/platform/export.h>

namespace hugh {
  
  namespace platform {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_PLATFORM_EXPORT rect {

      public:

        static signed const dflt_value_system; // -1
        static rect const   dflt_rect;

        signed x;
        signed y;
        signed w;
        signed h;

                 rect(signed /* x */ = dflt_value_system,
                      signed /* y */ = dflt_value_system,
                      signed /* w */ = dflt_value_system,
                      signed /* h */ = dflt_value_system);

        explicit rect(glm::ivec2 const& /* (x,y) */, glm::ivec2 const& /* (w,h) */);

        void swap(rect&);

        bool contains(glm::ivec2 const&) const;
      
      };
        
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      HUGH_PLATFORM_EXPORT bool operator==(rect const&, rect const&);
      HUGH_PLATFORM_EXPORT bool operator< (rect const&, rect const&);

      HUGH_PLATFORM_EXPORT void swap(rect&, rect&);
    
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, rect const&);

    } // namespace window {
  
  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_WINDOW_RECT_HPP)
