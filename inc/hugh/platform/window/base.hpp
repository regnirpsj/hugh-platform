// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform_window_base.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WINDOW_BASE_HPP)

#define HUGH_PLATFORM_WINDOW_BASE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <glm/glm.hpp>           // glm::ivec2
#include <string>                // std::string

// includes, project

#include <hugh/field/container.hpp>
#include <hugh/field/value/single.hpp>
#include <hugh/platform/export.h>
#include <hugh/platform/window/rect.hpp>
#include <hugh/support/printable.hpp>

namespace hugh {
  
  namespace platform {

    namespace window {

      class HUGH_PLATFORM_EXPORT base : private boost::noncopyable,
                                        public field::container {

      public:

        field::value::single<std::string> title;    //< title
        field::value::single<glm::ivec2>  position; //< upper-left corner
        field::value::single<glm::ivec2>  size;     //< extent
      
      protected:
      
        explicit base(std::string const& /* title */,
                      rect const&        /* rect  */ = rect::dflt_rect);

        virtual void do_changed(field::base&);
        
        virtual void reposition() =0;
        virtual void resize() =0;
        virtual void retitle() =0;
        
      };
      
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace window {
  
  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_WINDOW_BASE_HPP)
