#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class InputHandler
{
public:
	InputHandler();
	
	void Init(GLFWwindow * window);

	~InputHandler();

	static void KeyInputCallback(GLFWwindow * window, int key, int scancode, int state, int mods);
};

