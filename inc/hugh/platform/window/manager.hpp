// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/window/manager.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_WINDOW_MANAGER_HPP)

#define HUGH_PLATFORM_WINDOW_MANAGER_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <iosfwd>                // std::ostream (fwd decl)
#include <unordered_set>         // std::unordered_set<>
#include <vector>                // std::vector<>

// includes, project

#include <hugh/platform/export.h>

namespace hugh {
  
  namespace platform {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      template <typename C> class base;
      
      template <typename T>
      class manager : private boost::noncopyable {
      
      public:
      
        static unsigned count();
        static bool     empty();
        
        static void print_on(std::ostream&);
      
      protected:

        template <typename C> friend class base;
        
        static bool add(typename base<T>::context_type*);
        static bool sub(typename base<T>::context_type*);
      
      private:

        using context_list_type = std::unordered_set<typename base<T>::context_type*>;

        static context_list_type context_list_;
      
      };
        
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
    
    } // namespace window {
  
  } // namespace platform {

} // namespace hugh {

#include <hugh/platform/window/manager.inl>

#endif // #if !defined(HUGH_PLATFORM_WINDOW_MANAGER_HPP)
