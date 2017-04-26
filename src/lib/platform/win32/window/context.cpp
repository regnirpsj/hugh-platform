// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016-2017 University of Hull                                                     */
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

#include <cstdlib>        // ::getenv
#include <glm/gtx/io.hpp> // glm::operator<<  (field::container::print_on)
#include <sstream>        // std::ostringstream
#include <stdexcept>      // std::runtime_error

// includes, project

#include <hugh/platform/win32/io.hpp>
#include <hugh/platform/win32/utilities.hpp>
#include <hugh/support/io.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

#define HUGH_USE_TRACE_INTERNAL
#undef HUGH_USE_TRACE_INTERNAL

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  std::string const display_name           (::getenv("DISPLAY") ? ::getenv("DISPLAY") : ":0");
  unsigned const    window_flags_enable    (WS_CLIPCHILDREN |
                                            WS_CLIPSIBLINGS |
                                            WS_OVERLAPPEDWINDOW |
                                            WS_VISIBLE);
  unsigned const    window_flags_disable   (WS_DLGFRAME);
  unsigned const    window_flags_ex_enable (WS_EX_CLIENTEDGE);
  unsigned const    window_flags_ex_disable(0);

  DWORD    const    window_flags_          (window_flags_enable    & ~window_flags_disable);
  DWORD    const    window_flags_ex_       (window_flags_ex_enable & ~window_flags_ex_disable);
  
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
            position_         (glm::uvec2((0 > b.x) ? 0 : b.x, (0 > b.y) ? 0 : b.y)),
            size_             (glm::uvec2((1 > b.w) ? 1 : b.w, (1 > b.h) ? 1 : b.h)),
            hwnd_             (nullptr),
            register_class_   ()
        {
          TRACE("hugh::platform::win32::window::context::context");
          
          // calculate the size of the client area
          RECT wr = { 0, 0, signed(size_.x), signed(size_.y) };

          ::AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);

          hwnd_ = ::CreateWindowEx(window_flags_ex_,             // window border with a sunken edge
                                   register_class::class_name.c_str(), // window-class name
                                   title_.c_str(),               // caption of window
                                   window_flags_,                // window style
                                   position_.x,                  // x position
                                   position_.y,                  // y position
                                   wr.right - wr.left,           // witdh
                                   wr.bottom - wr.top,           // height
                                   nullptr,                      // handle to parent window
                                   nullptr,                      // handle to menu
                                   ::GetModuleHandle(nullptr),   // application instance
                                   this);                        // window creation data

          if (!hwnd_) {
            std::ostringstream ostr;

            ostr << "Unable to create window '" << title_ << "'";

            throw std::runtime_error(ostr.str().c_str());
          }

          ::ShowWindow  (hwnd_, SW_SHOWDEFAULT);
          ::UpdateWindow(hwnd_);
          ::ShowCursor  (true);
          
#if defined(HUGH_USE_TRACE_INTERNAL)
          {
            std::cout << support::trace::prefix()
                      << "hugh::platform::win32::window::context::context: "
                      << *this
                      << std::endl;
          }
#endif
        }
    
        /* virtual */
        context::~context()
        {
          TRACE("hugh::platform::win32::window::context::~context");

          ::DestroyWindow(hwnd_);
        }

        HWND const&
        context::handle() const
        {
          TRACE("hugh::platform::win32::window::context::handle");

          return hwnd_;
        }
        
        /* virtual */ void
        context::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::platform::win32::window::context::print_on");
          
          // boost::io::ios_all_saver const ias(os);

          os << '['
             << title_    << ','
             << position_ << ','
             << size_     << ','
             << hwnd_
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

        /* virtual */ LRESULT CALLBACK
        context::cb_window_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
        {
          TRACE("hugh::platform::win32::window::context::cb_window_proc");
          
#if defined(HUGH_USE_TRACE_INTERNAL)
          {
            std::cout << support::trace::prefix()
                      << "hugh::platform::win32::window::context::cb_window_proc: "
                      << *this
                      << std::endl;
          }
#endif

          LRESULT result (0);
          bool    handled(false);

          switch (msg) {
          case WM_CLOSE:
            {
              ::DestroyWindow(hwnd_);
            }
            break;
            
          case WM_DESTROY:
            {
              // window::manager::sub(this);
              handled = true;
            }
            break;
            
          case WM_PAINT:
            {
              ::InvalidateRect(hwnd_, nullptr, true);
              
              PAINTSTRUCT ps;
              
              ::BeginPaint(hwnd_, &ps);
              {
                handled = true; // nothing to do
              }
              ::EndPaint(hwnd_, &ps);
            }
            break;
            
          default:
            {
              result  = ::DefWindowProc(hWnd, msg, wParam, lParam);
              handled = true;
            }
            break;
          }
          
          if (!handled) {
            result = ::DefWindowProc(hWnd, msg, wParam, lParam);
          }
          
          return result;
        }
        
      } // namespace window {
      
    } // namespace win32 {
    
  } // namespace platform {

} // namespace hugh {
        
namespace hugh {

  namespace platform {

    namespace win32 {

      namespace window {
        
        // variables, exported

        /* static */ std::string const
        context::register_class::class_name("hugh::platform::win32::window::context");
        /* static */ unsigned
        context::register_class::count_    (0);
        
        // functions, exported

        /* explicit */
        context::register_class::register_class()
        {
          TRACE("hugh::platform::win32::window::context::register_class::register_class:" +
                std::to_string(count_));

          if (0 >= count_) {
            WNDCLASSEX wc = { 0 };

            wc.cbSize        = sizeof(WNDCLASSEX);
            wc.cbClsExtra    = 0;
            wc.cbWndExtra    = 0;
            wc.hInstance     = ::GetModuleHandle(nullptr);
            wc.style         = (CS_HREDRAW | CS_VREDRAW);
            wc.lpfnWndProc   = context::cb_window_proc_default;
            wc.hIcon         = ::LoadIcon  (0, IDI_APPLICATION);
            wc.hIconSm       = ::LoadIcon  (0, IDI_APPLICATION);
            wc.hCursor       = ::LoadCursor(0, IDC_ARROW);
            wc.hbrBackground = static_cast<HBRUSH>(::GetStockObject(WHITE_BRUSH));
            wc.lpszMenuName  = nullptr;
            wc.lpszClassName = class_name.c_str();
            
            if (!::RegisterClassEx(&wc)) {
              std::ostringstream ostr;
              
              ostr << "Unable to register window class '" << class_name << "'";
              
              throw std::runtime_error(ostr.str().c_str());
            }
          }

          ++count_;
        }
        
        context::register_class::~register_class()
        {
          TRACE("hugh::platform::win32::window::context::register_class::~register_class:" +
                 std::to_string(count_-1));

          --count_;

          if (0 >= count_) {
            ::UnregisterClass(class_name.c_str(), ::GetModuleHandle(nullptr));
          }
        }

        /* static */ unsigned
        context::register_class::count()
        {
          TRACE("hugh::platform::win32::window::context::register_class::count");
          
          return count_;
        }
        
      } // namespace window {
      
    } // namespace win32 {
    
  } // namespace platform {

} // namespace hugh {

#define HUGH_USE_TRACE_MSGROUTE
#undef HUGH_USE_TRACE_MSGROUTE

namespace hugh {

  namespace platform {

    namespace win32 {

      namespace window {
        
        // variables, exported
        
        // functions, exported

        namespace {
          
#if defined(_WIN64)
          signed user_data_flag(GWLP_USERDATA);
#else
          signed user_data_flag( GWL_USERDATA);
#endif
          
        }
        
        /* static */ LRESULT CALLBACK
        context::cb_window_proc_default(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
        {
          TRACE("hugh::platform::win32::window::context::cb_window_proc_default");
          
#if defined(HUGH_USE_TRACE_MSGROUTE)
          {
            std::cout << support::trace::prefix()
                      << "hugh::platform::win32::window::context::cb_window_proc_default: "
                      << "hWnd:"   << hWnd                << ','
                      << "msg:"    << message_string(msg) << ','
                      << "wParam:" << wParam              << ','
                      << "lParam:" << lParam
                      << std::endl;
          }
#endif

          LRESULT result(0);
          
          switch (msg) {
          case WM_NCCREATE:
          case WM_NCDESTROY:
            {
              context* ctx(nullptr);
              
              if (WM_NCCREATE == msg) {
                CREATESTRUCT* user_data(reinterpret_cast<CREATESTRUCT*>(lParam));
                
                ctx = static_cast<context*>(user_data->lpCreateParams);
              }
              
              window_long_ptr(hWnd, ctx, user_data_flag);
              
              result = ::DefWindowProc(hWnd, msg, wParam, lParam);
            }
            break;
            
          default:
            {
              context* ctx(window_long_ptr<context>(hWnd, user_data_flag));
              
              if (ctx) {
                result = ctx->cb_window_proc(hWnd, msg, wParam, lParam);
                
#if defined(HUGH_USE_TRACE_MSGROUTE)
                {
                  std::cout << support::trace::prefix()
                            << "hugh::platform::win32::window::context::cb_window_proc_default: "
                            << *ctx
                            << std::endl;
                }
#endif
              } else {
                result = ::DefWindowProc(hWnd, msg, wParam, lParam);
              }
            }
            break;
          }
          
          return result;  
        }
        
      } // namespace window {
      
    } // namespace win32 {
    
  } // namespace platform {

} // namespace hugh {
