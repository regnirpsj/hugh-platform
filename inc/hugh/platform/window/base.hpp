// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/base.hpp                                                   */
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

#include <hugh/field/adapter/single.hpp>
#include <hugh/field/container.hpp>
#include <hugh/platform/window/rect.hpp>

namespace hugh {
  
  namespace platform {

    namespace window {

      template <typename C>
      class base : private boost::noncopyable,
                   public field::container {
        
      public:

        using context_type = C;
        
        field::adapter::single<std::string> title;    //< title
        field::adapter::single<glm::uvec2>  position; //< upper-left corner
        field::adapter::single<glm::uvec2>  size;     //< extent
    
        virtual ~base() noexcept(false);

        virtual void print_on(std::ostream&) const;
        
      protected:

        context_type context_;
        
        explicit base(std::string const& /* title   */,
                      rect const&        /* rect    */ = rect::dflt_rect,
                      std::string const& /* display */ = std::string());
        
      private:

        std::string const& cb_get_title   () const;
        std::string        cb_set_title   (std::string const&);
        glm::uvec2 const&  cb_get_position() const;
        glm::uvec2         cb_set_position(glm::uvec2 const&);
        glm::uvec2 const&  cb_get_size    () const;
        glm::uvec2         cb_set_size    (glm::uvec2 const&);
      
      };
      
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace window {
  
  } // namespace platform {

} // namespace hugh {

#include <hugh/platform/window/base.inl>

#endif // #if !defined(HUGH_PLATFORM_WINDOW_BASE_HPP)
