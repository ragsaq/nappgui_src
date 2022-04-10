#include "App.h"

static App* i_create(void)
{
	return new App();
}

static void i_destroy(App** app)
{
	delete* app;
	*app = nullptr;
}

#include "osmain.h"
osmain(i_create, i_destroy, "", App)
