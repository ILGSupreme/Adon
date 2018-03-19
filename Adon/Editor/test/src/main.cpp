#include <app.h>

//testing app

int main(int argc, char **argv)
{
	Adon::Editor::App app;
	if(app.Open())
	{
			app.Run();
			app.Close();
	}
	app.Exit();
}
