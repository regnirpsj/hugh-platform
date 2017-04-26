// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016-2017 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/win32/application/base.cpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/platform/win32/application/base.hpp"

// includes, system

#include <sstream>   // std::ostringstream
#include <stdexcept> // std::runtime_error

// includes, project

#include <hugh/platform/window/manager.hpp>
#include <hugh/platform/win32/window.hpp>
#include <hugh/platform/win32/utilities.hpp>
#include <hugh/support/io.hpp>

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

    namespace win32 {

      namespace application {
      
        // variables, exported
        
        // functions, exported

        /* virtual */
        base::~base()
        {
          TRACE("hugh::platform::win32::application::base::~base");
        }
        
        /* virtual */ void
        base::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::win32::application::base::print_on");

          platform::posix::application::base::print_on(os);
        }
      
        /* explicit */
        base::base(platform::application::command_line const& a, bool b)
          : platform::posix::application::base(a, b)
        {
          TRACE("hugh::platform::win32::application::base::base");
        }

        signed
        base::message_loop(message m)
        {
          TRACE("hugh::platform::win32::application::base::message_loop");

          using window_manager = platform::window::manager<win32::window::simple::context_type>;
          
          signed result(EXIT_FAILURE);
          
          if (!window_manager::count()) {
            std::ostringstream ostr;
            
            ostr << "hugh::platform::win32::application::base::message_loop: requires at least one "
                 << "'hugh::platform::win32::window::base'-derived window to be already "
                 << "instantiated!";
            
            throw std::runtime_error(ostr.str());
          } else {
            do {
              switch (m) {
              case message::get:  get_message (); break;
              case message::peek: peek_message(); break;
                
              default:
                {
                  std::ostringstream ostr;
                  
                  ostr << "win32::application::base::message_loop: received an unsupported enum value "
                       << "of " << signed(m) << " specifying the message-lookup strategy!";
                  
                  throw std::logic_error(ostr.str());
                }
                break;
              }
            } while (!terminate && (0 < window_manager::count()));
            
            result = EXIT_SUCCESS;
          }
          
          return result;
        }
        
        /* virtual */ void
        base::update()
        {
          TRACE("hugh::platform::win32::application::base::update");
        }
        
        void
        base::get_message()
        {
          TRACE("hugh::platform::win32::application::base::get_message");
          
          MSG msg;
          
          if (-1 == ::GetMessage(&msg, nullptr, 0, 0)) {
            std::ostringstream ostr;
            
            ostr << "hugh::platform::win32::application::base::get_message: "
                 << "'::GetMessage' failed w/ error: '" << win32::last_error_message() << "'";
            
            throw std::runtime_error(ostr.str());
          } else {
            dispatch_message(msg);
          }
        }
        
        void
        base::peek_message()
        {
          TRACE("hugh::platform::win32::application::base::peek_message");
          
          MSG msg;
          
          if (::PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            dispatch_message(msg);
          } else {
            update();
          }
        }
        
        void
        base::dispatch_message(MSG const& msg)
        {
          TRACE("hugh::platform::win32::application::base::dispatch_message");
          
          ::TranslateMessage(&msg);
          ::DispatchMessage (&msg);
          
          switch (msg.message) {
          case WM_APP:
            {
              if (WM_QUIT == msg.lParam) {
                ::PostQuitMessage(unsigned(msg.lParam));
              }
            }
            break;
            
          case WM_QUIT:
            {
              terminate = true;
            }
            break;
            
          default:
            break;
          }
        }
        
      } // namespace application {

    } // namespace win32 {
  
  } // namespace platform {

} // namespace hugh {
