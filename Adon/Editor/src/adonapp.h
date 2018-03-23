#ifndef ADONAPP_HEADER
#define ADONAPP_HEADER
#include <editor_export.h>
#include <app.h>
#include <window.h>

namespace Adon
{
  namespace Editor
  {
    class EDITOR_EXPORT AdonApp : public Adon::Editor::App
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
