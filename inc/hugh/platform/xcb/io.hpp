// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/platform/xcb/io.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_PLATFORM_XCB_IO_HPP)

#define HUGH_PLATFORM_XCB_IO_HPP

// includes, system

#include <iosfwd>    // std::ostream (fwd decl)
#include <xcb/xcb.h> // xcb_*

// includes, project

#include <hugh/platform/export.h>

namespace hugh {

  namespace platform {

    namespace xcb {
      
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, uint8_t const&);
      
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_access_control_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_color_cells_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_color_cells_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_color_cells_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_color_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_color_planes_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_color_planes_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_color_planes_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_color_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_color_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_named_color_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_named_color_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_alloc_named_color_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_allow_events_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_allow_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_arc_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_arc_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_arc_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_atom_enum_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_atom_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_auto_repeat_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_back_pixmap_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_backing_store_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_bell_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_blanking_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_button_index_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_button_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_button_mask_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_button_press_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_cap_style_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_change_active_pointer_grab_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_change_gc_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_change_hosts_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_change_keyboard_control_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_change_keyboard_mapping_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_change_pointer_control_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_change_property_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_change_save_set_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_change_window_attributes_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_char2b_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_char2b_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_charinfo_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_charinfo_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_circulate_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_circulate_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_circulate_window_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_clear_area_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_client_message_data_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_client_message_data_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_client_message_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_clip_ordering_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_close_down_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_close_font_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_color_flag_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_coloritem_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_coloritem_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_colormap_alloc_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_colormap_enum_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_colormap_iterator_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_colormap_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_colormap_state_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_config_window_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_configure_notify_event_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_configure_request_event_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_configure_window_request_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_convert_selection_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_coord_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_copy_area_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_copy_colormap_and_free_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_copy_gc_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_copy_plane_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_create_colormap_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_create_cursor_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_create_gc_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_create_glyph_cursor_request_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_create_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_create_pixmap_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_create_window_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_cursor_enum_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_cursor_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_cw_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_delete_property_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_depth_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_depth_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_destroy_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_destroy_subwindows_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_destroy_window_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_drawable_iterator_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_enter_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_event_mask_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_expose_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_exposures_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_family_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_fill_poly_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_fill_rule_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_fill_style_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_focus_in_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_font_draw_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_font_enum_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_font_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_fontable_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_fontprop_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_fontprop_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_force_screen_saver_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_format_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_format_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_free_colormap_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_free_colors_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_free_cursor_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_free_gc_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_free_pixmap_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_gc_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_gcontext_iterator_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_ge_generic_event_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_generic_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_atom_name_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_atom_name_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_atom_name_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_font_path_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_font_path_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_font_path_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_geometry_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_geometry_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_geometry_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_image_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_image_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_image_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_input_focus_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_input_focus_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_input_focus_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_keyboard_control_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_keyboard_control_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_keyboard_control_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_keyboard_mapping_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_keyboard_mapping_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_keyboard_mapping_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_modifier_mapping_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_modifier_mapping_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_modifier_mapping_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_motion_events_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_motion_events_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_motion_events_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_pointer_control_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_pointer_control_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_pointer_control_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_pointer_mapping_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_pointer_mapping_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_pointer_mapping_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_property_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_property_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_property_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_property_type_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_screen_saver_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_screen_saver_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_screen_saver_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_selection_owner_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_selection_owner_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_selection_owner_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_window_attributes_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_window_attributes_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_get_window_attributes_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_button_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_key_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_keyboard_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_keyboard_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_keyboard_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_pointer_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_pointer_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_pointer_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_server_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_status_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_grab_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_graphics_exposure_event_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_gravity_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_gravity_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_gx_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_host_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_host_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_host_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_image_format_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_image_order_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_image_text_16_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_image_text_8_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_input_focus_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_install_colormap_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_intern_atom_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_intern_atom_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_intern_atom_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_join_style_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_kb_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_key_but_mask_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_key_press_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_keycode_iterator_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_keymap_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_keysym_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_kill_client_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_kill_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_led_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_line_style_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_extensions_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_extensions_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_extensions_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_fonts_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_fonts_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_fonts_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_fonts_with_info_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_fonts_with_info_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_fonts_with_info_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_hosts_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_hosts_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_hosts_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_installed_colormaps_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_installed_colormaps_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_installed_colormaps_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_properties_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_properties_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_list_properties_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_lookup_color_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_lookup_color_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_lookup_color_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_map_index_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_map_notify_event_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_map_request_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_map_state_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_map_subwindows_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_map_window_request_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_mapping_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_mapping_status_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_mapping_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_mod_mask_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_motion_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_motion_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_no_exposure_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_no_operation_request_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_notify_detail_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_notify_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_open_font_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_pixmap_enum_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_pixmap_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_place_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_point_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_point_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_arc_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_fill_arc_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_fill_rectangle_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_line_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_point_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_rectangle_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_segment_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_shape_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_text_16_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_poly_text_8_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_prop_mode_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_property_notify_event_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_property_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_put_image_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_best_size_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_best_size_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_best_size_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_colors_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_colors_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_colors_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_extension_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_extension_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_extension_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_font_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_font_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_font_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_keymap_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_keymap_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_keymap_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_pointer_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_pointer_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_pointer_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_shape_of_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_text_extents_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_text_extents_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_text_extents_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_tree_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_tree_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_query_tree_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_recolor_cursor_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_rectangle_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_rectangle_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_reparent_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_reparent_window_request_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_request_error_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_resize_request_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_rgb_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_rgb_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_rotate_properties_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_screen_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_screen_saver_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_screen_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_segment_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_segment_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_selection_clear_event_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_selection_notify_event_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_selection_request_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_send_event_dest_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_send_event_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_access_control_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_clip_rectangles_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_close_down_mode_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_dashes_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_font_path_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_input_focus_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_modifier_mapping_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_modifier_mapping_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_modifier_mapping_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_pointer_mapping_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_pointer_mapping_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_pointer_mapping_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_screen_saver_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_set_selection_owner_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_setup_authenticate_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_setup_authenticate_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_setup_failed_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_setup_failed_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_setup_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_setup_request_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_setup_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_setup_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_stack_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_store_colors_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_store_named_color_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_str_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_str_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_subwindow_mode_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_time_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_timecoord_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_timecoord_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_timestamp_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_translate_coordinates_cookie_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_translate_coordinates_reply_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_translate_coordinates_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_ungrab_button_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_ungrab_key_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_ungrab_keyboard_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_ungrab_pointer_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_ungrab_server_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_uninstall_colormap_request_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_unmap_notify_event_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_unmap_subwindows_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_unmap_window_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_value_error_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_visibility_notify_event_t const&);
      HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_visibility_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_visual_class_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_visualid_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_visualtype_iterator_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_visualtype_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_warp_pointer_request_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_window_class_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_window_enum_t const&);
      // HUGH_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, ::xcb_window_iterator_t const&);

    } // namespace xcb {
    
  } // namespace platform {
  
} // namespace hugh {

#endif // #if !defined(// HUGH_PLATFORM_// HUGH_PLATFORM_::XCB_IO_HPP)
