// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/sdl/window/context.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/sdl/window/context.hpp"

// includes, system

#include <SDL.h>                  // SDL_*
#include <cstdlib>                // ::getenv
#include <glm/gtx/io.hpp>         // glm::operator<<  (field::container::print_on)
#include <sstream>                // std::ostringstream
#include <stdexcept>              // std::runtime_error

// includes, project

#include <hugh/platform/sdl/io.hpp>
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

    namespace sdl {

      namespace window {
        
        // variables, exported

        /* static */ std::string const context::dflt_display_name(display_name);
        
        // functions, exported

        /* explicit */
        context::context(std::string const& a, rect const& b, std::string const&)
          : support::printable(),
            title_            (a),
            position_         (glm::uvec2((0 > b.x) ? 0 : b.x,
                                          (0 > b.y) ? 0 : b.y)),
            size_             (glm::uvec2((1 > b.w) ? 1 : b.w,
                                          (1 > b.h) ? 1 : b.h)),
            window_           (::SDL_CreateWindow(title_.c_str(),
                                                  position_.x, position_.y, size_.x, size_.y,
                                                  SDL_WINDOW_RESIZABLE))
        {
          TRACE("hugh::platform::sdl::window::context::context");

          if (!window_) {
            std::ostringstream ostr;

            ostr << "SDL_CreateWindow error: " << ::SDL_GetError();
            
            throw std::runtime_error(ostr.str());
          }

          ::SDL_Surface* sfc(::SDL_GetWindowSurface(window_));

          if (!sfc) {
            std::ostringstream ostr;

            ostr << "SDL_GetWindowSurface error: " << ::SDL_GetError();

            throw std::runtime_error(ostr.str());
          }

          ::SDL_FillRect           (sfc, nullptr, ::SDL_MapRGB(sfc->format, 0xFF, 0xFF, 0xFF));
          ::SDL_UpdateWindowSurface(window_);
        }
    
        /* virtual */
        context::~context()
        {
          TRACE("hugh::platform::sdl::window::context::~context");

          ::SDL_DestroyWindow(window_);
        }

        /* virtual */ void
        context::print_on(std::ostream& os) const
        {
          TRACE("hugh::platform::sdl::window::context::print_on");
          
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
          TRACE("hugh::platform::sdl::window::context::position(get)");

          return position_;
        }

        glm::uvec2
        context::position(glm::uvec2 const& a)
        {
          TRACE("hugh::platform::sdl::window::context::position(set)");

          glm::uvec2 const result(position());

          if (a != result) {
            position_ = a;            
          }
          
          return result;
        }
      
        glm::uvec2 const&
        context::size() const
        {
          TRACE("hugh::platform::sdl::window::context::size(get)");

          return size_;
        }

        glm::uvec2
        context::size(glm::uvec2 const& a)
        {
          TRACE("hugh::platform::sdl::window::context::size(set)");

          glm::uvec2 const result(size());

          if (a != result) {
            size_ = a;
          }
          
          return result;
        }

        std::string const&
        context::title() const
        {
          TRACE("hugh::platform::sdl::window::context::title(get)");
          
          return title_;
        }

        std::string
        context::title(std::string const& a)
        {
          TRACE("hugh::platform::sdl::window::context::title(set)");

          std::string const result(title());

          title_ = a;
          
          return result;
        }
        
      } // namespace window {
      
    } // namespace sdl {
    
  } // namespace platform {

} // namespace hugh {
