// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/base.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/window/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<  (field::container::print_on)

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace platform {

    namespace window {
  
      // variables, exported
  
      // functions, exported
    
      /* explicit */
      base::base(std::string const& a, rect const& b)
        : boost::noncopyable(),
          field::container  (),
          title             (*this, "title",    a),
          position          (*this, "position", glm::ivec2((0 > b.x) ? 0 : b.x,
                                                           (0 > b.y) ? 0 : b.y)),
          size              (*this, "size",     glm::ivec2((1 > b.w) ? 1 : b.w,
                                                           (1 > b.h) ? 1 : b.h))
      {
        TRACE("hugh::platform::window::base::base");
      }
    
    } // namespace window {
  
  } // namespace platform {
  
} // namespace hugh {
