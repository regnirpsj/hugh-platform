// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/manager.hpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_XCB_WINDOW_MANAGER_HPP)

#define HUGH_PLATFORM_XCB_WINDOW_MANAGER_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/platform/window/manager.hpp>

namespace hugh {

  namespace platform {

    namespace xcb {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        class base;
        
        class HUGH_PLATFORM_EXPORT manager : public platform::window::manager {

        public:

          using id_type = platform::window::manager::id_type;

          static unsigned count();
          static base*    get(id_type);

          static std::vector<id_type> const& all();

        private:

          friend class base;

          static bool  add(id_type, base*);
          static bool  sub(base*);
          static bool  sub(id_type);
          
        };
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {

    } // namespace xcb {

  } // namespace platform {

} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_XCB_WINDOW_MANAGER_HPP)
