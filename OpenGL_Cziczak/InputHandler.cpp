#include "InputHandler.h"


InputHandler::InputHandler()
{

}

void InputHandler::Init(GLFWwindow * window)
{
	glfwSetKeyCallback(window, KeyInputCallback);
}


InputHandler::~InputHandler()
{
}

void InputHandler::KeyInputCallback(GLFWwindow * window, int key, int scancode, int state, int mods)
{
	if (key == GLFW_KEY_ESCAPE && state == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	if(key == GLFW_KEY_R && state == GLFW_PRESS)
	{
		ShaderProgram::CurrentProgram->Refresh();
	}
}
