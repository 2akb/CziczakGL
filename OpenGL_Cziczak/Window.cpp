#include "Window.h"
#include <iostream>

Window::Window(int x, int y, char* name)
{
	Init(x, y, name);
	m_inputHandler.Init(m_window);
}


Window::~Window()
{
	glfwTerminate();
}

bool Window::IsOpen()
{
	return glfwWindowShouldClose(m_window) == false;
}

GLFWwindow * Window::getGLFWWindow()
{
	return m_window;
}

bool Window::Init(int x, int y, char* name)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(x, y, name, nullptr, nullptr);

	if (m_window == nullptr)
	{
		std::cout << "Failed to create glfw window";
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize glew";
		glfwTerminate();
		return false;
	}

	int frameX, frameY;
	glfwGetFramebufferSize(m_window, &frameX, &frameY);

	glViewport(0, 0, frameX, frameY);
	return true;
}
