#pragma once

#include "nappgui.h"

class NappLayout
{
protected:
	Layout* handle{ nullptr };

public:
	NappLayout() = default;
	NappLayout(Layout* handle_) : handle(handle_) {}
	~NappLayout() = default;

	operator Layout*() const { return handle; }

	auto Handle() const { return handle; }

	void create(const uint32_t ncols, const uint32_t nrows)
	{
		if (handle == nullptr)
			handle = layout_create(ncols, nrows);
	}

	static NappLayout make(const uint32_t ncols, const uint32_t nrows) { return { layout_create(ncols, nrows) }; }

	Cell* cell(const uint32_t col, const uint32_t row) const { return layout_cell(handle, col, row); }
	void label(Label* label, const uint32_t col, const uint32_t row) const { layout_label(handle, label, col, row); }
	void button(Button* button, const uint32_t col, const uint32_t row) const { layout_button(handle, button, col, row); }
	void popup(PopUp* popup, const uint32_t col, const uint32_t row) const { layout_popup(handle, popup, col, row); }
	void edit(Edit* edit, const uint32_t col, const uint32_t row) const { layout_edit(handle, edit, col, row); }
	void combo(Combo* combo, const uint32_t col, const uint32_t row) const { layout_combo(handle, combo, col, row); }
	void listbox(ListBox* list, const uint32_t col, const uint32_t row) const { layout_listbox(handle, list, col, row); }
	void updown(UpDown* updown, const uint32_t col, const uint32_t row) const { layout_updown(handle, updown, col, row); }
	void slider(Slider* slider, const uint32_t col, const uint32_t row) const { layout_slider(handle, slider, col, row); }
	void progress(Progress* progress, const uint32_t col, const uint32_t row) const { layout_progress(handle, progress, col, row); }
	void view(View* view, const uint32_t col, const uint32_t row) const { layout_view(handle, view, col, row); }
	void textview(TextView* view, const uint32_t col, const uint32_t row) const { layout_textview(handle, view, col, row); }
	void imageview(ImageView* view, const uint32_t col, const uint32_t row) const { layout_imageview(handle, view, col, row); }
	void tableview(TableView* view, const uint32_t col, const uint32_t row) const { layout_tableview(handle, view, col, row); }
	void splitview(SplitView* view, const uint32_t col, const uint32_t row) const { layout_splitview(handle, view, col, row); }
	void panel(Panel* panel, const uint32_t col, const uint32_t row) const { layout_panel(handle, panel, col, row); }
	void layout(Layout* sublayout, const uint32_t col, const uint32_t row) const { layout_layout(handle, sublayout, col, row); }
	void* control_imp(const uint32_t col, const uint32_t row, const char_t* type) const { return layout_control_imp(handle, col, row, type); }
	void taborder(const orient_t order) const { layout_taborder(handle, order); }
	void tabstop(const uint32_t col, const uint32_t row, const bool_t tabstop) const { layout_tabstop(handle, col, row, tabstop); }
	void content_size(const S2Df size) const { layout_content_size(handle, size); }
	void hsize(const uint32_t col, const real32_t width) const { layout_hsize(handle, col, width); }
	void vsize(const uint32_t row, const real32_t height) const { layout_vsize(handle, row, height); }
	void hmargin(const uint32_t col, const real32_t margin) const { layout_hmargin(handle, col, margin); }
	void vmargin(const uint32_t row, const real32_t margin) const { layout_vmargin(handle, row, margin); }
	void hexpand(const uint32_t col) const { layout_hexpand(handle, col); }
	void hexpand2(const uint32_t col1, const uint32_t col2, const real32_t exp) const { layout_hexpand2(handle, col1, col2, exp); }
	void hexpand3(const uint32_t col1, const uint32_t col2, const uint32_t col3, const real32_t exp1, const real32_t hexpand3exp2) const
	{
		layout_hexpand3(handle, col1, col2, col3, exp1, hexpand3exp2);
	}
	void vexpand(const uint32_t row) const { layout_vexpand(handle, row); }
	void vexpand2(const uint32_t row1, const uint32_t row2, const real32_t exp) const { layout_vexpand2(handle, row1, row2, exp); }
	void vexpand3(const uint32_t row1, const uint32_t row2, const uint32_t row3, const real32_t exp1, const real32_t vexpand3exp2) const
	{
		layout_vexpand3(handle, row1, row2, row3, exp1, vexpand3exp2);
	}
	void halign(const uint32_t col, const uint32_t row, const align_t align) const { layout_halign(handle, col, row, align); }
	void valign(const uint32_t col, const uint32_t row, const align_t align) const { layout_valign(handle, col, row, align); }
	void show_col(const uint32_t col, const bool_t visible) const { layout_show_col(handle, col, visible); }
	void show_row(const uint32_t row, const bool_t visible) const { layout_show_row(handle, row, visible); }
	void margin(const real32_t mall) const { layout_margin(handle, mall); }
	void margin2(const real32_t mtb, const real32_t mlr) const { layout_margin2(handle, mtb, mlr); }
	void margin4(const real32_t mt, const real32_t mr, const real32_t mb, const real32_t ml) const { layout_margin4(handle, mt, mr, mb, ml); }
	void bgcolor(const color_t color) const { layout_bgcolor(handle, color); }
	void skcolor(const color_t color) const { layout_skcolor(handle, color); }
	void update() const { layout_update(handle); }
	void dbind_imp(Listener* listener, const char_t* type, const uint16_t size) const { layout_dbind_imp(handle, listener, type, size); }
	void dbind_obj_imp(void* obj, const char_t* type) const { layout_dbind_obj_imp(handle, obj, type); }
	void dbind_update_imp(const char_t* type, const uint16_t size, const char_t* mname, const char_t* mtype, const uint16_t moffset, const uint16_t msize) const
	{
		layout_dbind_update_imp(handle, type, size, mname, mtype, moffset, msize);
	}
};
