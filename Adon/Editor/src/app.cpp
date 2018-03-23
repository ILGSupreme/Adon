#include "app.h"
#include <cstdio>
#include <cassert>

namespace Adon
{
	namespace Editor
	{

		EDITOR_EXPORT App::App() :
		isOpen(false)
		{
		}

		EDITOR_EXPORT App::~App()
		{
			// empty
		}

		EDITOR_EXPORT bool App::Open()
		{
			assert(!this->isOpen);
			this->isOpen = true;
			return isOpen;
		}

		EDITOR_EXPORT void App::Close()
		{
			assert(this->isOpen);
			this->isOpen = false;
		}

		EDITOR_EXPORT void App::Run()
		{
			// override in subclass
		}

		EDITOR_EXPORT void App::Exit()
		{
			// override in subclass
		}

		EDITOR_EXPORT bool App::IsOpen()
		{
			return this->isOpen;
		}

	}
}
