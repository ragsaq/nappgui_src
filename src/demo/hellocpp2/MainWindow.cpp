#include "MainWindow.h"
#include "App.h"
#include "NappButton.h"
#include "NappLabel.h"
#include "NappLayout.h"
#include "NappString.h"

MainWindow::MainWindow(App* app)
{
	auto panel = makePanel();
	window.create(ekWNSRES);
	clicks = 0;
	window.panel(panel);
	window.title("Hello, C++!");
	window.origin(v2df(500, 200));
	window.OnClose(IListen(app, App, App::i_OnClose));
	window.show();
}

void MainWindow::i_OnButton(Event* e)
{
	auto msg = NappString::printf("Button click (%d)\n", clicks);
	text.writef(msg);
	clicks += 1;
	unref(e);
}

NappPanel MainWindow::makePanel()
{
	auto panel = NappPanel::make();
	auto layout = NappLayout::make(1, 3);
	auto label = NappLabel::make();
	auto button = NappButton::makePush();
	text.create();
	label.text("Hello!, I'm a label");
	button.text("Click Me!");
	button.OnClick(IListen(this, MainWindow, i_OnButton));
	layout.label(label, 0, 0);
	layout.button(button, 0, 1);
	layout.textview(text, 0, 2);
	layout.hsize(0, 250);
	layout.vexpand(2);
	layout.margin(5);
	layout.vmargin(0, 5);
	layout.vmargin(1, 5);
	panel.layout(layout);
	return panel;
}
