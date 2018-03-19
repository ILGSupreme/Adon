#ifndef APP_HEADER
#define APP_HEADER
#include <editor_export.h>

namespace Adon
{
	namespace Editor
	{
		class EDITOR_EXPORT App
		{
		public:
			App();
			~App();
			EDITOR_EXPORT bool Open();
			EDITOR_EXPORT void Close();
			EDITOR_EXPORT void Run();
			EDITOR_EXPORT void Exit();
		private:
			bool isOpen;
		};
	}
}

#endif // !APP_HEADER
