#pragma once

#include "NappLayout.h"

class NappButton
{
protected:
	Button* handle{ nullptr };

public:
	NappButton() = default;
	NappButton(Button* handle_) : handle(handle_) {}
	~NappButton() = default;

	operator Button*() const { return handle; }

	auto Handle() const { return handle; }

	void createPush()
	{
		if (handle == nullptr)
			handle = button_push();
	}

	void createCheck()
	{
		if (handle == nullptr)
			handle = button_check();
	}

	void createCheck3()
	{
		if (handle == nullptr)
			handle = button_check3();
	}

	void createRadio()
	{
		if (handle == nullptr)
			handle = button_radio();
	}

	void createFlat()
	{
		if (handle == nullptr)
			handle = button_flat();
	}

	void createFlatgle()
	{
		if (handle == nullptr)
			handle = button_flatgle();
	}

	static NappButton makePush() { return { button_push() }; }
	static NappButton makeCheck() { return { button_check() }; }
	static NappButton makeCheck3() { return { button_check3() }; }
	static NappButton makeRadio() { return { button_radio() }; }
	static NappButton makeFlat() { return { button_flat() }; }
	static NappButton makeFlatgle() { return { button_flatgle() }; }

	void OnClick(Listener* listener) const { button_OnClick(handle, listener); }
	void text(const char_t* text) const { button_text(handle, text); }
	void text_alt(const char_t* text) const { button_text_alt(handle, text); }
	void tooltip(const char_t* text) const { button_tooltip(handle, text); }
	void font(const Font* font) const { button_font(handle, font); }
	void image(const Image* image) const { button_image(handle, image); }
	void image_alt(const Image* image) const { button_image_alt(handle, image); }
	void state(const state_t state) const { button_state(handle, state); }
	state_t get_state() const { return button_get_state(handle); }
};
