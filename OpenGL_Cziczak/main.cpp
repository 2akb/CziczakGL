#include "Window.h"

int main()
{
	
	Window window(800, 600, "Tutorial");

	while (window.IsOpen())
	{
		glfwPollEvents();
		glfwSwapBuffers(window.getGLFWWindow());
	}
	
	return 0;
}