#include "adonapp.h"


namespace Adon
{
  namespace Editor
  {
    EDITOR_EXPORT AdonApp::AdonApp()
    {
    }
    EDITOR_EXPORT AdonApp::~AdonApp()
    {
    }
    EDITOR_EXPORT bool AdonApp::Open()
    {
      App::Open();
      this->window = new Adon::Editor::Window;
      window->SetKeyPressFunction([this](int32,int32,int32,int32)
      {
        this->window->Close();
      });
      if(window->Open())
      {
        //setup the graphics..
        return true;
      }
      return false;
    }

    EDITOR_EXPORT void AdonApp::Close()
    {
      App::Close();
      delete this->window;
    }

    EDITOR_EXPORT void AdonApp::Exit()
    {
      Adon::Editor::TerminateGLFW();
    }

    EDITOR_EXPORT void AdonApp::Run()
    {
      while(this->window->IsOpen())
      {
        //run code..
        this->window->Update();
        this->window->SwapBuffers();
      }
    }
  }
}
