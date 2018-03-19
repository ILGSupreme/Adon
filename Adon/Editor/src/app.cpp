#include "adwin.h"
#include <cstdio>
#include <cassert>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Adon
{
	namespace Editor
	{

		ADWIN_EXPORT App::App() :
		isOpen(false)
		{
			// empty
		}

		ADWIN_EXPORT App::~App()
		{
			// empty
		}

		ADWIN_EXPORT bool App::Open()
		{
			assert(!this->isOpen);
			this->isOpen = true;
			return isOpen;
		}

		ADWIN_EXPORT void App::Close()
		{
			assert(this->isOpen);
			this->isOpen = false;
		}

		ADWIN_EXPORT void App::Run()
		{
			// override in subclass
		}

		ADWIN_EXPORT void App::Exit()
		{
			// override in subclass
		}

	}
}
