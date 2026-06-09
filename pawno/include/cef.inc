#if defined _cef_included
    #endinput
#endif
#define _cef_included

#if !defined _CEF_DEFINES
#define _CEF_DEFINES

#define CEFINT(%0) (%0)
#define CEFFLOAT(%0) (%0)
#define CEFSTR(%0) (%0)

#define CEF_BROWSER_FLAGS_NONE 0
#define CEF_BROWSER_FLAGS_FOCUS 1
#define CEF_BROWSER_FLAGS_DRAG_DROP 2
#define CEF_BROWSER_FLAGS_AUDIO 4
#define CEF_BROWSER_FLAGS_ALL (CEF_BROWSER_FLAGS_FOCUS | CEF_BROWSER_FLAGS_DRAG_DROP | CEF_BROWSER_FLAGS_AUDIO)

#endif

forward OnCefInitialize(playerid, success);
forward OnCefBrowserCreated(playerid, browserid, status);
forward OnCefBrowserClosed(playerid, browserid);
forward OnCefEvent(playerid, browserid, const eventName[], const args[]);

native cef_create_browser(playerid, browserid, const url[], bool:focus = true, bool:transparent = false, flags = CEF_BROWSER_FLAGS_NONE);
native cef_destroy_browser(playerid, browserid);
native cef_set_browser_position(playerid, browserid, x, y, width, height);
native cef_set_browser_visible(playerid, browserid, bool:visible);
native cef_set_browser_focus(playerid, browserid, bool:focus);
native cef_emit_event(playerid, browserid, const eventName[], const format[] = "", {Float, _}:...);
native cef_emit_event_all(browserid, const eventName[], const format[] = "", {Float, _}:...);
native cef_execute_js(playerid, browserid, const script[]);
native cef_append_js(playerid, browserid, const script[]);
native cef_load_url(playerid, browserid, const url[]);
native cef_reload(playerid, browserid);
native cef_go_back(playerid, browserid);
native cef_go_forward(playerid, browserid);
native cef_get_cookies(playerid, const url[], callback[], const format[] = "", {Float, _}:...);
native cef_set_cookie(playerid, const url[], const name[], const value[], const domain[], const path[], expires = 0, bool:secure = false, bool:httponly = false);
native cef_delete_cookies(playerid, const url[], const name[]);
native cef_audio_mute(playerid, browserid, bool:mute);
native cef_audio_set_volume(playerid, browserid, Float:volume);
native cef_find(playerid, browserid, const text[], bool:forward = true, bool:matchCase = false, bool:findNext = false);
native cef_stop_finding(playerid, browserid, clear = 1);
native cef_print(playerid, browserid);
native cef_get_zoom_level(playerid, browserid, &Float:zoom);
native cef_set_zoom_level(playerid, browserid, Float:zoom);
native cef_run_file_dialog(playerid, browserid, mode, const title[], const defaultPath[], const acceptFilters[]);
native cef_drag_target_drop(playerid, browserid, const files[]);
native cef_drag_target_drag_enter(playerid, browserid, const files[], x, y);
native cef_drag_target_drag_over(playerid, browserid, x, y);
native cef_drag_target_drag_leave(playerid, browserid);
native cef_get_user_agent(playerid, browserid, dest[], size = 256);
native cef_set_user_agent(playerid, browserid, const userAgent[]);
native cef_get_browser_count(playerid);
native cef_is_browser_active(playerid, browserid);
native cef_get_browser_url(playerid, browserid, dest[], size = 512);
native cef_get_browser_title(playerid, browserid, dest[], size = 256);
native cef_get_browser_favicon(playerid, browserid, dest[], size = 512);
native cef_send_key_event(playerid, browserid, type, key, modifiers, bool:isSystemKey);
native cef_send_mouse_click_event(playerid, browserid, x, y, type, bool:mouseUp, clickCount = 1);
native cef_send_mouse_move_event(playerid, browserid, x, y, bool:leave);
native cef_send_mouse_wheel_event(playerid, browserid, x, y, deltaX, deltaY);
native cef_send_focus_event(playerid, browserid, bool:setFocus);
native cef_set_browser_opacity(playerid, browserid, alpha);
native cef_get_browser_opacity(playerid, browserid);
native cef_set_browser_cursor(playerid, browserid, cursorType);
native cef_get_browser_cursor(playerid, browserid);
native cef_set_audio_stream_handler(playerid, browserid, const handlerName[]);
native cef_remove_audio_stream_handler(playerid, browserid);

#define CEF_EVENT_INT(%0) "i", %0
#define CEF_EVENT_FLOAT(%0) "f", %0
#define CEF_EVENT_STRING(%0) "s", %0
#define CEF_EVENT_BOOL(%0) "b", %0

#endif