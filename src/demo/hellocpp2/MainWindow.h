#pragma once

#include "nappgui.h"
#include "NappPanel.h"
#include "NappTextView.h"
#include "NappWindow.h"

class App;

class MainWindow : public IListener
{
public:
	MainWindow(App* app);

	void* operator new(size_t size) { return (void*)heap_malloc((uint32_t)size, "MainWindow"); }
	void operator delete(void* ptr, size_t size) { heap_free((byte_t**)&ptr, (uint32_t)size, "MainWindow"); }

private:
	void i_OnButton(Event* e);
	NappPanel makePanel();

	NappTextView text;
	NappWindow window;
	uint32_t clicks;
};
