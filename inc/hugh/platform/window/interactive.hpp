// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/interactive.hpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WINDOW_INTERACTIVE_HPP)

#define HUGH_PLATFORM_WINDOW_INTERACTIVE_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/platform/window/simple.hpp>

namespace hugh {
  
  namespace platform {

    namespace window {

      template <typename Context, typename Update, typename Input>
      class interactive : public simple<Context, Update> {

      public:

        using inherited  = simple<Context, Update>;
        using input_type = Input;

        explicit interactive(std::string const& /* title   */,
                             rect const&        /* rect    */ = rect::dflt_rect,
                             std::string const& /* display */ = std::string());
        virtual ~interactive();
        
        virtual void display();
        
      protected:

        input_type input_;
        
      };
      
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace window {
  
  } // namespace platform {

} // namespace hugh {

#include <hugh/platform/window/interactive.inl>

#endif // #if !defined(HUGH_PLATFORM_WINDOW_INTERACTIVE_HPP)
