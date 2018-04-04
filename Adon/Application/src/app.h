#ifndef APP_HEADER
#define APP_HEADER

namespace Adon
{
	namespace Application
	{
		class App
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
