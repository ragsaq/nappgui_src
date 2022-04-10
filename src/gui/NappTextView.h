#pragma once

#include "nappgui.h"

class NappTextView
{
protected:
	TextView* handle{ nullptr };

public:
	NappTextView() = default;
	NappTextView(TextView* handle_) : handle(handle_) {}
	~NappTextView() = default;

	operator TextView*() const { return handle; }

	auto Handle() const { return handle; }

	void create()
	{
		if (handle == nullptr)
			handle = textview_create();
	}

	static NappTextView make() { return { textview_create() }; }

	void size(const S2Df size) const { textview_size(handle, size); }
	void clear() const { textview_clear(handle); }

	template<typename... Args>
	uint32_t printf(const char_t* format, Args... args)
	{
		return textview_printf(handle, format, args...);
	}

	void writef(const char_t* text) const { textview_writef(handle, text); }
	void rtf(Stream* rtf_in) const { textview_rtf(handle, rtf_in); }
	void units(const uint32_t units) const { textview_units(handle, units); }
	void family(const char_t* family) const { textview_family(handle, family); }
	void fsize(const real32_t size) const { textview_fsize(handle, size); }
	void fstyle(const uint32_t fstyle) const { textview_fstyle(handle, fstyle); }
	void color(const color_t color) const { textview_color(handle, color); }
	void bgcolor(const color_t color) const { textview_bgcolor(handle, color); }
	void pgcolor(const color_t color) const { textview_pgcolor(handle, color); }
	void halign(const align_t align) const { textview_halign(handle, align); }
	void lspacing(const real32_t scale) const { textview_lspacing(handle, scale); }
	void bfspace(const real32_t space) const { textview_bfspace(handle, space); }
	void afspace(const real32_t space) const { textview_afspace(handle, space); }
	void scroll_down() const { textview_scroll_down(handle); }
	void editable(const bool_t is_editable) const { textview_editable(handle, is_editable); }
};
