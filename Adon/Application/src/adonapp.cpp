#include "adonapp.h"


namespace Adon
{
  namespace Editor
  {
     AdonApp::AdonApp()
    {
    }
     AdonApp::~AdonApp()
    {
    }
     bool AdonApp::Open()
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

     void AdonApp::Close()
    {
      App::Close();
      delete this->window;
    }

     void AdonApp::Exit()
    {
      Adon::Editor::TerminateGLFW();
    }

     void AdonApp::Run()
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
