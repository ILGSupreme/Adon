#ifndef ADONAPP_HEADER
#define ADONAPP_HEADER
#include <app.h>
#include <window.h>

namespace Adon
{
  namespace Editor
  {
    class AdonApp : public Adon::Editor::App
    {
    public:
      AdonApp();
      ~AdonApp();
      bool Open();
      void Close();
      void Exit();
      void Run();
    private:
      Window* window;
    };
  }
}


#endif //ADONAPP_HEADER
