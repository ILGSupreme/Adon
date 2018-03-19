#ifndef ADWIN_HEADER
#define ADWIN_HEADER
#include <adwin_export.h>

namespace Adon
{
	namespace Editor
	{
		class ADWIN_EXPORT App
		{
		public:
			App();
			~App();
			ADWIN_EXPORT bool Open();
			ADWIN_EXPORT void Close();
			ADWIN_EXPORT void Run();
			ADWIN_EXPORT void Exit();
		private:
			bool isOpen;
		};
	}
}

#endif // !ADWIN_HEADER
