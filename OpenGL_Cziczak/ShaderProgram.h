#pragma once
#include <GL\glew.h>
#include "Shader.h"

class ShaderProgram
{
public:
	ShaderProgram();

	~ShaderProgram();

private:

	GLuint m_program;

	Shader * m_vertexShader;

	Shader * m_fragmentShader;

	void Init();
};

