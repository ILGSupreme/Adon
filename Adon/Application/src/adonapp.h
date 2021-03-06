#ifndef ADONAPP_HEADER
#define ADONAPP_HEADER
#include <app.h>
#include <window.h>
#include <entity.h>
#include "entitymanager.h"

namespace Adon
{
  namespace Application
  {
    class AdonApp : public Adon::Application::App
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
      EntityManager entitymanager;
    };
  }
}


#endif //ADONAPP_HEADER
