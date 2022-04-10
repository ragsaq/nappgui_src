#pragma once

#include "NappLayout.h"

class NappLabel
{
protected:
	Label* handle{ nullptr };

public:
	NappLabel() = default;
	NappLabel(Label* handle_) : handle(handle_) {}
	~NappLabel() = default;

	operator Label*() const { return handle; }

	auto Handle() const { return handle; }

	void create()
	{
		if (handle == nullptr)
			handle = label_create();
	}

	void createMultiline()
	{
		if (handle == nullptr)
			handle = label_multiline();
	}

	static NappLabel make() { return { label_create() }; }
	static NappLabel makeMultiline() { return { label_multiline() }; }

	void OnClick(Listener* listener) const { label_OnClick(handle, listener); }
	void text(const char_t* text) const { label_text(handle, text); }
	void font(const Font* font) const { label_font(handle, font); }
	void style_over(const uint32_t fstyle) const { label_style_over(handle, fstyle); }
	void align(const align_t align) const { label_align(handle, align); }
	void color(const color_t color) const { label_color(handle, color); }
	void color_over(const color_t color) const { label_color_over(handle, color); }
	void bgcolor(const color_t color) const { label_bgcolor(handle, color); }
	void bgcolor_over(const color_t color) const { label_bgcolor_over(handle, color); }
};
