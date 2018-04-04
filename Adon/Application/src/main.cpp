#include <adonapp.h>
#include <window.h>
#include <cstdio>
#include <typeinfo>
//testing app

int main(int argc, char **argv)
{
	Adon::Application::AdonApp app;
	if(app.Open())
	{
			app.Run();
			app.Close();
	}
	app.Exit();
}
