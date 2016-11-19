// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/sdl/window/update.hpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_SDL_WINDOW_UPDATE_HPP)

#define HUGH_PLATFORM_SDL_WINDOW_UPDATE_HPP

// includes, system

#include <iosfwd> // std::ostream (fwd decl)

// includes, project

#include <hugh/platform/export.h>
#include <hugh/support/printable.hpp>

namespace hugh {

  namespace platform {

    namespace sdl {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        class context;
        
        class HUGH_PLATFORM_EXPORT update : public support::printable {

        public:

          explicit update(context&);
          virtual ~update();

          virtual void print_on(std::ostream&) const;
          
          void operator()();
      
        protected:

          context& ctx_;
          
        };
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {
      
    } // namespace sdl {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_SDL_WINDOW_UPDATE_HPP)
