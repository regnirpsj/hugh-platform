// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/manager.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/xcb/window/manager.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)

// includes, project

#include <hugh/platform/xcb/window/base.hpp>
#include <hugh/support/thread.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  using lock_type  = hugh::support::simple_lock;
  using lock_guard = hugh::support::simple_lock_guard;
  
  // variables, internal

  bool                                                       ids_changed(false);
  std::vector<hugh::platform::xcb::window::manager::id_type> ids_list;
  lock_type                                                  ids_lock;
  
  // functions, internal

} // namespace {

namespace hugh {

  namespace platform {

    namespace xcb {

      namespace window {
        
        // variables, exported
  
        // functions, exported

        /* static */ unsigned
        manager::count()
        {
          TRACE("hugh::platform::xcb::window::manager::count");

          lock_guard const lg(ids_lock);
          
          return platform::window::manager::count(window_type::xcb);
        }

        /* static */ base*
        manager::get(id_type a)
        {
          TRACE_NEVER("hugh::platform::xcb::window::manager::get");

          lock_guard const lg(ids_lock);
          
          return static_cast<base*>(platform::window::manager::get(window_type::xcb, a));
        }

        /* static */ std::vector<manager::id_type> const&
        manager::all()
        {
          TRACE_NEVER("hugh::platform::xcb::window::manager::all");

          lock_guard const lg(ids_lock);
          
          if (ids_changed) {
            ids_list    = platform::window::manager::all(window_type::xcb);
            ids_changed = false;
          }

          return ids_list;
        }

        /* static */ bool
        manager::add(id_type a, base* b)
        {
          TRACE("hugh::platform::xcb::window::manager::add");

          lock_guard const lg(ids_lock);
          
          ids_changed = true;

          return platform::window::manager::add(window_type::xcb, a, b);
        }

        /* static */ bool
        manager::sub(base* a)
        {
          TRACE("hugh::platform::xcb::window::manager::sub(base*)");

          lock_guard const lg(ids_lock);
          
          ids_changed = true;

          return platform::window::manager::sub(window_type::xcb, a);
        }

        /* static */ bool
        manager::sub(id_type a)
        {
          TRACE("hugh::platform::xcb::window::manager::sub(id_type)");

          lock_guard const lg(ids_lock);
          
          ids_changed = true;

          return platform::window::manager::sub(window_type::xcb, a);
        }
        
      } // namespace window {

    } // namespace xcb {

  } // namespace platform {
  
} // namespace hugh {
