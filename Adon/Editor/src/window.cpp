#include "window.h"
#include <cstdio>

namespace Adon
{
  namespace Editor
  {
    EDITOR_EXPORT
    Window::Window()
                    :
                    width(640),
                    height(480),
                    title("Adon Default Screen")

    {
      //empty code
    }

    EDITOR_EXPORT
    Window::Window (int32 width,
                    int32 height,
                    std::string title)
                    :
                    width(width),
                    height(height),
                    title(title)

    {
      //empty code
    }

    EDITOR_EXPORT
    Window::~Window()
    {
      //empty code
    }

    EDITOR_EXPORT
    void Window::StaticErrorCallBack(
                                int error,
                                const char* description)

    {
      fprintf(stderr, "Error %s\n", description);
    }

    EDITOR_EXPORT
    void Window::StaticKeyPressCallBack(GLFWwindow* win,
                                   int32 key,
                                   int32 scancode,
                                   int32 action,
                                   int32 mods)

    {
      fprintf(stderr, "%s\n", "HAHAHAHA");
      Window* window = (Window*) glfwGetWindowUserPointer(win);
      if (nullptr != window->keyPressCallback) {
        fprintf(stderr, "%s\n", "HAHAHA");
        window->keyPressCallback(key,scancode,action,mods);
      }
    }

    EDITOR_EXPORT
    bool Window::Open()
    {
      glfwSetErrorCallback(StaticErrorCallBack);
      if(!glfwInit())
      {
        //error in trying to initilize GLFW.
        fprintf(stderr, "%s\n", "Error in trying to initialize GLFW");
        return false;
      }
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,  2);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,  0);
      this->window = glfwCreateWindow(width,height,title.c_str(), NULL, NULL);
      if (!window)
      {
        glfwTerminate();
        return false;
      }
      glfwSetWindowUserPointer(this->window, this);
      glfwSetKeyCallback(window, Adon::Editor::Window::StaticKeyPressCallBack);
      if(!MakeCurrent())
      {
        return false;
      }
      return true;
    }

    EDITOR_EXPORT
    void Window::Close() {
      if(nullptr != window ) glfwDestroyWindow(this->window);
      this->window = nullptr;
      glfwTerminate();
      fprintf(stderr, "%s\n", "TERMINATION COMPLETE");
    }
  } //namespace Editor
} //namespace Adon
