// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/window/context.hpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_XCB_WINDOW_CONTEXT_HPP)

#define HUGH_PLATFORM_XCB_WINDOW_CONTEXT_HPP

// includes, system

#include <functional>    // std::function<>
#include <glm/glm.hpp>   // glm::*
#include <memory>        // std::unique_ptr<>
#include <mutex>         // std::mutex
#include <string>        // std::string
#include <thread>        // std::thread
#include <unordered_map> // std::unordered_map<>
#include <vector>        // std::vector<>
#include <xcb/xcb.h>     // ::xcb_*

// includes, project

#include <hugh/platform/export.h>
#include <hugh/platform/window/rect.hpp>
#include <hugh/support/printable.hpp>

namespace hugh {

  namespace platform {

    namespace xcb {

      namespace window {
        
        // types, exported (class, enum, struct, union, typedef)

        class input;
        class update;
        
        class HUGH_PLATFORM_EXPORT context : public support::printable {
    
        public:
    
          using rect                  = platform::window::rect;
          using handler_callback_type = std::function<bool (::xcb_generic_event_t const&)>;

          static std::string const dflt_display_name; // getenv(DISPLAY) || ":0"
          
          explicit context(std::string const& /* title   */,
                           rect const&        /* rect    */ = rect::dflt_rect,
                           std::string const& /* display */ = dflt_display_name);
          virtual ~context();

          virtual void print_on(std::ostream&) const;
                  
          glm::uvec2 const&  position() const;
          glm::uvec2         position(glm::uvec2 const& a);
          glm::uvec2 const&  size() const;
          glm::uvec2         size(glm::uvec2 const& a);
          std::string const& title() const;
          std::string        title(std::string const& a);

        protected:

          friend class input;
          friend class update;
          
          std::string       title_;
          glm::uvec2        position_;
          glm::uvec2        size_;
          
          xcb_connection_t* connection_;
          xcb_screen_t*     screen_;
          xcb_window_t      window_;
          xcb_gcontext_t    gcontext_;
          
          void flush() const;
          
        private:

          using handler_list_type = std::vector<handler_callback_type>;
          using handler_map_type  = std::unordered_map<uint8_t, handler_list_type>;

          handler_map_type handler_map_;
          std::mutex       handler_map_mutex_;
          
          bool add(uint8_t /* event type */, handler_callback_type /* handler */);
          bool sub(uint8_t /* event type */, handler_callback_type /* handler */);
          
        private:
          
          std::unique_ptr<std::thread> event_listener_;
          bool                         event_listener_active_;
          
          void event_listener_loop();

        };
        
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace window {
      
    } // namespace xcb {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(HUGH_PLATFORM_XCB_WINDOW_CONTEXT_HPP)
