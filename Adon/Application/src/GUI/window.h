#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <config.h>

namespace Adon
{
  namespace Application
  {
    class Window
    {
    public:
      Window();
      Window(int32,int32, std::string title);
      ~Window();

      //change size of window
      void SetSize(int32 width, int32 height);
      //change title of window
      void SetTitle(std::string title);
      //Open window
      bool Open();
      //Close window
      void Close();

      void Update();

      void SwapBuffers();

      bool IsOpen();

      void SetKeyPressFunction(const std::function<void(int32, int32,  int32,  int32)>& func);
    private:
      static void StaticErrorCallBack(int32 error, const char* description);
      static void StaticKeyPressCallBack(GLFWwindow*,int32,int32,int32,int32);

      //Make this window the current opengl context
      bool MakeCurrent();
      //resize the window screen
      void Resize();
      void Retitle();

      std::function<void(int32,int32,int32,int32)> keyPressCallback;

      int32 width;
      int32 height;
      std::string title;
      bool isOpen;

      GLFWwindow* _glfwwindow;
    };

    void TerminateGLFW();
  }
}

inline void
Adon::Application::TerminateGLFW()
{
  glfwTerminate();
}

inline void
Adon::Application::Window::SetSize(int32 width,int32 height) {
  this->width = width;
  this->height = height;
  if(nullptr != this->_glfwwindow) this->Resize();
}


inline void
Adon::Application::Window::SetTitle(std::string title) {
  this->title = title;
}

inline bool
Adon::Application::Window::IsOpen() {
  return this->isOpen;
}

inline void
Adon::Application::Window::Update() {
  if(nullptr != this->_glfwwindow) glfwPollEvents();
}

inline void
Adon::Application::Window::SwapBuffers() {
	if(nullptr != this->_glfwwindow) glfwSwapBuffers(this->_glfwwindow);
}


inline void
Adon::Application::Window::SetKeyPressFunction(const std::function<void(int32, int32,  int32,  int32)>& func) {
  this->keyPressCallback = func;
}

inline bool
Adon::Application::Window::MakeCurrent() {
  glfwMakeContextCurrent(this->_glfwwindow);
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    //initializing GLAD produced an error.
    fprintf(stderr, "%s\n", "Could not initilize GLAD");
    return false;
  }
  return true;
}

inline void
Adon::Application::Window::Resize() {
  glfwSetWindowSize(this->_glfwwindow, width, height);
}
inline void
Adon::Application::Window::Retitle(){
  if (nullptr != this->_glfwwindow) glfwSetWindowTitle(this->_glfwwindow, this->title.c_str());
}

#endif //WINDOW_HEADER
