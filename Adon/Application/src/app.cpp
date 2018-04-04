#include "app.h"
#include <cstdio>
#include <cassert>

namespace Adon
{
	namespace Application
	{

		 App::App() :
		isOpen(false)
		{
		}

		 App::~App()
		{
			// empty
		}

		 bool App::Open()
		{
			assert(!this->isOpen);
			this->isOpen = true;
			return isOpen;
		}

		 void App::Close()
		{
			assert(this->isOpen);
			this->isOpen = false;
		}

		 void App::Run()
		{
			// override in subclass
		}

		 void App::Exit()
		{
			// override in subclass
		}

		 bool App::IsOpen()
		{
			return this->isOpen;
		}

	}
}
