// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/test/shared.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_TEST_SHARED_HPP)

#define HUGH_PLATFORM_TEST_SHARED_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/platform/window/interactive.hpp>
#include <hugh/support/printable.hpp>

namespace hugh {

  namespace platform {

    namespace window {
      
      namespace test {
      
        // types, exported (class, enum, struct, union, typedef)

        class context : public support::printable {
    
        public:
    
          using rect = platform::window::rect;
      
          explicit context(std::string const& a, rect const& b, std::string const& = std::string())
            : title_   (a),
              position_(glm::uvec2((0 > b.x) ? 0 : b.x,
                                   (0 > b.y) ? 0 : b.y)),
              size_    (glm::uvec2((1 > b.w) ? 1 : b.w,
                                   (1 > b.h) ? 1 : b.h))
          {
            TRACE("hugh::platform::window::test::context::context");
          }
    
          ~context()
          {
            TRACE("hugh::platform::window::test::context::~context");
          }

          virtual void print_on(std::ostream&) const
          {
            TRACE_NEVER("hugh::platform::window::test::context::print_on");
          }
          
          glm::uvec2 const& position() const
          {
            TRACE("hugh::platform::window::test::context::position(get)");

            return position_;
          }

          glm::uvec2 position(glm::uvec2 const& a)
          {
            TRACE("hugh::platform::window::test::context::position(set)");

            glm::uvec2 const result(position_);

            position_ = a;
        
            return result;
          }
      
          glm::uvec2 const& size() const
          {
            TRACE("hugh::platform::window::test::context::size(get)");

            return size_;
          }

          glm::uvec2 size(glm::uvec2 const& a)
          {
            TRACE("hugh::platform::window::test::context::size(set)");

            glm::uvec2 const result(size_);

            size_ = a;
        
            return result;
          }

          std::string const& title() const
          {
            TRACE("hugh::platform::window::test::context::title(get)");

            return title_;
          }

          std::string title(std::string const& a)
          {
            TRACE("hugh::platform::window::test::context::title(set)");

            std::string const result(title_);

            title_ = a;
        
            return result;
          }

        private:

          std::string title_;
          glm::uvec2  position_;
          glm::uvec2  size_;
    
        };

        class input {

        public:

          explicit input(context& a)
            : ctx_(a)
          {
            TRACE("hugh::platform::window::test::input::input");
          }

          ~input()
          {
            TRACE("hugh::platform::window::test::input::~input");
          }

          void operator()()
          {
            TRACE("hugh::platform::window::test::input::operator()");
          }
      
        protected:

          context& ctx_;
      
        };

        class update {

        public:

          explicit update(context& a)
            : ctx_(a)
          {
            TRACE("hugh::platform::window::test::update::update");
          }

          ~update()
          {
            TRACE("hugh::platform::window::test::update::~update");
          }

          void operator()()
          {
            TRACE("hugh::platform::window::test::update::operator()");
          }
      
        protected:

          context& ctx_;
      
        };
  
        using simple      = hugh::platform::window::simple     <context, update>;
        using interactive = hugh::platform::window::interactive<context, update, input>;
  
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace test {

    } // namespace window {
    
  } // namespace platform {
          
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_TEST_SHARED_HPP)
