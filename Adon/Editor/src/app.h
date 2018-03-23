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
			bool Open();
			void Close();
			void Run();
			void Exit();
			bool IsOpen();
		private:
			bool isOpen;
		};
	}
}

#endif // !APP_HEADER
