#include <adonapp.h>
#include <window.h>
#include <cstdio>
#include <typeinfo>
//testing app

int main(int argc, char **argv)
{
	fprintf(stderr, "%s\n", "google");
	Adon::Editor::AdonApp app;
	if(app.Open())
	{
			app.Run();
			fprintf(stderr, "%s\n", "google");
			app.Close();
	}
	app.Exit();
}
