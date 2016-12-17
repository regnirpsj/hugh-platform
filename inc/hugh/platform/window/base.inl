// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/base.inl                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WINDOW_BASE_INL)

#define HUGH_PLATFORM_WINDOW_BASE_INL

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <stdexcept>      // std::runtime_error

// includes, project

#include <hugh/platform/window/manager.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>
#if defined(HUGH_USE_TRACE) || defined(HUGH_ALL_TRACE)
#  include <typeinfo>
#  include <hugh/support/type_info.hpp>
#endif

namespace hugh {
  
  namespace platform {

    namespace window {

      // functions, inlined (inline)

#if defined(__GNUC__)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wterminate"
#elif defined(_MSC_VER)
#  pragma warning(push)
      // warning C4297: 'd'tor': function assumed not to throw an exception but does
#  pragma warning(disable:4297)
#endif
      
      template <typename C>
      inline /* virtual */
      base<C>::~base()
      {
        TRACE("hugh::platform::window::base<" + support::demangle(typeid(C)) + ">::~base");

        if (!window::manager<C>::sub(&context_)) {
          // only throw if no other exception is being processed
          if (!std::uncaught_exception()) {
            throw std::runtime_error("hugh::platform::window::base<" +
                                     support::demangle(typeid(C)) +
                                     ">::~base: unable to deregister window context");
          }
        }
      }

#if defined(__GNUC__)
#  pragma GCC diagnostic pop
#elif defined(_MSC_VER)
#  pragma warning(pop)
#endif
      
      template <typename C>
      inline /* virtual */ void
      base<C>::print_on(std::ostream& os) const
      {
        TRACE_NEVER("hugh::platform::window::base<" + support::demangle(typeid(C)) + ">::print_on");

        field::container::print_on(os);

        os << hugh::support::ostream::remove(1) << ',' << context_ << ']';
      }
      
      template <typename C>
      inline /* explicit */
      base<C>::base(std::string const& a, rect const& b, std::string const& c)
        : boost::noncopyable(),
          field::container  (),
          title             (*this, "title",
                             std::bind(&base::cb_get_title,    this),
                             std::bind(&base::cb_set_title,    this, std::placeholders::_1)),
          position          (*this, "position",
                             std::bind(&base::cb_get_position, this),
                             std::bind(&base::cb_set_position, this, std::placeholders::_1)),
          size              (*this, "size",
                             std::bind(&base::cb_get_size,     this),
                             std::bind(&base::cb_set_size,     this, std::placeholders::_1)),
          context_          (a, b, c)
      {
        TRACE("hugh::platform::window::base<" + support::demangle(typeid(C)) + ">::base");

        if (!window::manager<C>::add(&context_)) {
          throw std::runtime_error("hugh::platform::window::base<" + support::demangle(typeid(C)) +
                                   ">::base: unable to register window context");
        }
      }
      
      template <typename C>
      inline std::string const&
      base<C>::cb_get_title() const
      {
        TRACE("hugh::platform::window::base<" + support::demangle(typeid(C)) + ">::cb_get_title");

        return context_.title();
      }
    
      template <typename C>
      inline std::string
      base<C>::cb_set_title(std::string const& a)
      {
        TRACE("hugh::platform::window::base<" + support::demangle(typeid(C)) + ">::cb_set_title");

        return context_.title(a);
      }

      template <typename C>
      inline glm::uvec2 const&
      base<C>::cb_get_position() const
      {
        TRACE("hugh::platform::window::base<" + support::demangle(typeid(C)) + ">::cb_get_position");

        return context_.position();
      }

      template <typename C>
      inline glm::uvec2
      base<C>::cb_set_position(glm::uvec2 const& a)
      {
        TRACE("hugh::platform::window::base<" + support::demangle(typeid(C)) + ">::cb_set_position");

        return context_.position(a);
      }

      template <typename C>
      inline glm::uvec2 const&
      base<C>::cb_get_size() const
      {
        TRACE("hugh::platform::window::base<" + support::demangle(typeid(C)) + ">::cb_get_size");

        return context_.size();
      }

      template <typename C>
      inline glm::uvec2
      base<C>::cb_set_size(glm::uvec2 const& a)
      {
        TRACE("hugh::platform::window::base<" + support::demangle(typeid(C)) + ">::cb_get_size");

        return context_.size(a);
      }
      
    } // namespace window {
  
  } // namespace platform {

} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_PLATFORM_WINDOW_BASE_INL)
