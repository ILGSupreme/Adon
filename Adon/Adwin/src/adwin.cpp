#include "adwin.h"
#include <iostream>
#include <glad\glad.h>
#include <GLFW\glfw3.h>

ADWIN_EXPORT void Adon::AdWin::testfunction()
{

	if (!glfwInit())
	{
		printf("GLFW FAILED TO INIT");
		return void();
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* window = glfwCreateWindow(640, 480, "MyWindow", NULL, NULL);

	glfwMakeContextCurrent(window);

	glGetString = (PFNGLGETSTRINGPROC)glfwGetProcAddress("glGetString");

	printf("Opengl supported by this system %s",glGetString(GL_VERSION));

	if (gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)==0)
	{
		printf("something went wrong");
		glfwTerminate();
		return;
	}

	return void();
}
