// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/window/context.cpp                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/win32/window/context.hpp"

// includes, system

#include <cstdlib>                // ::getenv
#include <glm/gtx/io.hpp>         // glm::operator<<  (field::container::print_on)
#include <sstream>                // std::ostringstream
#include <stdexcept>              // std::runtime_error

// includes, project

#include <hugh/platform/win32/io.hpp>
#include <hugh/support/io_utils.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  std::string const display_name(::getenv("DISPLAY") ? ::getenv("DISPLAY") : ":0");
  
  // functions, internal

} // namespace {

namespace hugh {

  namespace platform {

    namespace win32 {

      namespace window {
        
        // variables, exported

        /* static */ std::string const context::dflt_display_name(display_name);
        
        // functions, exported

        /* explicit */
        context::context(std::string const& a, rect const& b, std::string const& c)
          : support::printable(),
            title_            (a),
            position_         (glm::uvec2((0 > b.x) ? 0 : b.x,
                                          (0 > b.y) ? 0 : b.y)),
            size_             (glm::uvec2((1 > b.w) ? 1 : b.w,
                                          (1 > b.h) ? 1 : b.h)),
            window_           ()
        {
          TRACE("hugh::platform::win32::window::context::context");
        }
    
        /* virtual */
        context::~context()
        {
          TRACE("hugh::platform::win32::window::context::~context");
        }

        /* virtual */ void
        context::print_on(std::ostream& os) const
        {
          TRACE("hugh::platform::win32::window::context::print_on");
          
          // boost::io::ios_all_saver const ias(os);

          os << '['
            //<<             title_              << ','
            //<<             position_           << ','
            //<<             size_               << ','
             << ']';
        }
        
        glm::uvec2 const&
        context::position() const
        {
          TRACE("hugh::platform::win32::window::context::position(get)");

          return position_;
        }

        glm::uvec2
        context::position(glm::uvec2 const& a)
        {
          TRACE("hugh::platform::win32::window::context::position(set)");

          glm::uvec2 const result(position());

          if (a != result) {
            position_ = a;            
          }
          
          return result;
        }
      
        glm::uvec2 const&
        context::size() const
        {
          TRACE("hugh::platform::win32::window::context::size(get)");

          return size_;
        }

        glm::uvec2
        context::size(glm::uvec2 const& a)
        {
          TRACE("hugh::platform::win32::window::context::size(set)");

          glm::uvec2 const result(size());

          if (a != result) {
            size_ = a;
          }
          
          return result;
        }

        std::string const&
        context::title() const
        {
          TRACE("hugh::platform::win32::window::context::title(get)");
          
          return title_;
        }

        std::string
        context::title(std::string const& a)
        {
          TRACE("hugh::platform::win32::window::context::title(set)");

          std::string const result(title());

          title_ = a;
          
          return result;
        }
        
      } // namespace window {
      
    } // namespace win32 {
    
  } // namespace platform {

} // namespace hugh {
