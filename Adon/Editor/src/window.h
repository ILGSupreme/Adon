#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include <editor_export.h>
#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <config.h>

namespace Adon
{
  namespace Editor
  {
    class EDITOR_EXPORT Window
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

    EDITOR_EXPORT void TerminateGLFW();
  }
}

inline void
Adon::Editor::TerminateGLFW()
{
  glfwTerminate();
}

inline void
Adon::Editor::Window::SetSize(int32 width,int32 height) {
  this->width = width;
  this->height = height;
  if(nullptr != this->_glfwwindow) this->Resize();
}


inline void
Adon::Editor::Window::SetTitle(std::string title) {
  this->title = title;
}

inline bool
Adon::Editor::Window::IsOpen() {
  return this->isOpen;
}

inline void
Adon::Editor::Window::Update() {
  if(nullptr != this->_glfwwindow) glfwPollEvents();
}

inline void
Adon::Editor::Window::SwapBuffers() {
	if(nullptr != this->_glfwwindow) glfwSwapBuffers(this->_glfwwindow);
}


inline void
Adon::Editor::Window::SetKeyPressFunction(const std::function<void(int32, int32,  int32,  int32)>& func) {
  this->keyPressCallback = func;
}

inline bool
Adon::Editor::Window::MakeCurrent() {
  glfwMakeContextCurrent(this->_glfwwindow);
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    //initializing GLAD produced an error.
    fprintf(stderr, "%s\n", "Could not initilize GLAD");
    return false;
  }
  return true;
}

inline void
Adon::Editor::Window::Resize() {
  glfwSetWindowSize(this->_glfwwindow, width, height);
}
inline void
Adon::Editor::Window::Retitle(){
  if (nullptr != this->_glfwwindow) glfwSetWindowTitle(this->_glfwwindow, this->title.c_str());
}

#endif //WINDOW_HEADER
