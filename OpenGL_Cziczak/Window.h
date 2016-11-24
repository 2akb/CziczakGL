#pragma once
#include "InputHandler.h"

class Window
{
public:

	Window(int x, int y, char* name);

	~Window();

	bool IsOpen();

	GLFWwindow * getGLFWWindow();

private:

	bool Init(int x, int y, char* name);

	GLFWwindow * m_window;

	InputHandler m_inputHandler;
};

