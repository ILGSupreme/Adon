#include <adonapp.h>
#include <window.h>
#include <cstdio>
#include <typeinfo>
//testing app

int main(int argc, char **argv)
{
	Adon::Editor::AdonApp app;
	if(app.Open())
	{
			app.Run();
			app.Close();
	}
	app.Exit();
}
