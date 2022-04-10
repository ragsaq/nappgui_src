#pragma once

#include "nappgui.h"

class NappWindow
{
protected:
	Window* handle{ nullptr };

public:
	NappWindow() = default;
	~NappWindow()
	{
		if (handle)
			window_destroy(&handle);
	}

	NappWindow(const NappWindow&) = delete;
	NappWindow& operator=(const NappWindow&) = delete;
	NappWindow(NappWindow&&) = default;
	NappWindow& operator=(NappWindow&&) = default;

	operator Window*() const { return handle; }

	auto Handle() const { return handle; }

	void create(const uint32_t flags)
	{
		if (handle == nullptr)
			handle = window_create(flags);
	}

	static NappWindow make(const uint32_t flags)
	{
		NappWindow window;
		window.create(flags);
		return window;
	}

	void panel(NappPanel panel) const { window_panel(handle, panel); }
	void OnClose(Listener* listener) const { window_OnClose(handle, listener); }
	void OnMoved(Listener* listener) const { window_OnMoved(handle, listener); }
	void OnResize(Listener* listener) const { window_OnResize(handle, listener); }
	void title(const char_t* text) const { window_title(handle, text); }
	void show() const { window_show(handle); }
	void hide() const { window_hide(handle); }
	void modal(NappWindow parent) const { window_modal(handle, parent); }
	void stop_modal(const uint32_t return_value) const { window_stop_modal(handle, return_value); }
	void update() const { window_update(handle); }
	void origin(const V2Df origin) const { window_origin(handle, origin); }
	void size(const S2Df size) const { window_size(handle, size); }
	V2Df get_origin() const { return window_get_origin(handle); }
	S2Df get_size() const { return window_get_size(handle); }
	S2Df get_client_size() const { return window_get_client_size(handle); }
	void defbutton(Button* button) const { window_defbutton(handle, button); }
	void cursor(const cursor_t cursor, const Image* image, const real32_t hot_x, const real32_t hot_y) const
	{
		window_cursor(handle, cursor, image, hot_x, hot_y);
	}
};
