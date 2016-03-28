// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/simple.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WINDOW_SIMPLE_HPP)

#define HUGH_PLATFORM_WINDOW_SIMPLE_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/platform/window/base.hpp>

namespace hugh {
  
  namespace platform {

    namespace window {

      template <typename Context, typename Update>
      class simple : public base<Context> {

      public:

        using inherited   = base<Context>;
        using update_type = Update;

        explicit simple(std::string const& /* title   */,
                        rect const&        /* rect    */ = rect::dflt_rect,
                        std::string const& /* display */ = std::string());
        virtual ~simple();
        
        virtual void display();
        
      protected:

        update_type update_;
        
      };
      
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace window {
  
  } // namespace platform {

} // namespace hugh {

#include <hugh/platform/window/simple.inl>

#endif // #if !defined(HUGH_PLATFORM_WINDOW_SIMPLE_HPP)
