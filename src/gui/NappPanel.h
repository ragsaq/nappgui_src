#pragma once

#include "NappLayout.h"

class NappPanel
{
protected:
	Panel* handle{ nullptr };

public:
	NappPanel() = default;
	NappPanel(Panel* handle_) : handle(handle_) {}
	~NappPanel() = default;

	operator Panel*() const { return handle; }

	auto Handle() const { return handle; }

	void create()
	{
		if (handle == nullptr)
			handle = panel_create();
	}

	void create(const bool_t hscroll, const bool_t vscroll)
	{
		if (handle == nullptr)
			handle = panel_scroll(hscroll, vscroll);
	}

	static NappPanel make() { return { panel_create() }; }
	static NappPanel make(const bool_t hscroll, const bool_t vscroll) { return { panel_scroll(hscroll, vscroll) }; }

	void data_imp(void** data, FPtr_destroy func_destroy_item) const { panel_data_imp(handle, data, func_destroy_item); }
	void* get_data_imp() const { panel_get_data_imp(handle); }
	void size(const S2Df size) const { panel_size(handle, size); }
	uint32_t layout(NappLayout layout) const { return panel_layout(handle, layout); }
	NappLayout get_layout(const uint32_t index) const { return panel_get_layout(handle, index); }
	void visible_layout(const uint32_t index) const { panel_visible_layout(handle, index); }
	void update() const { panel_update(handle); }
	real32_t scroll_width() const { return panel_scroll_width(handle); }
	real32_t scroll_height() const { return panel_scroll_height(handle); }
};
