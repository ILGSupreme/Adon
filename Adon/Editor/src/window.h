#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include <editor_export.h>
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
    private:
      int32* test;
      GLFWwindow* window;
    };
  }
}
#endif //WINDOW_HEADER
