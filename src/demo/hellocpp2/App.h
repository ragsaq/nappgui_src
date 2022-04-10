#pragma once

#include "MainWindow.h"

class App : public IListener
{
public:
	App();
	~App();
	void i_OnClose(Event* e);
	void* operator new(size_t size) { return (void*)heap_malloc((uint32_t)size, "App"); }
	void operator delete(void* ptr, size_t size) { heap_free((byte_t**)&ptr, (uint32_t)size, "App"); }

private:
	MainWindow* main_window;
};
