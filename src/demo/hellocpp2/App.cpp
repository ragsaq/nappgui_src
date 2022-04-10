#include "App.h"

App::App(void)
{
	this->main_window = new MainWindow(this);
}

App::~App()
{
	delete this->main_window;
}

void App::i_OnClose(Event* e)
{
	osapp_finish();
	unref(e);
}
