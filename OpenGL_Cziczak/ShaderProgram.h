#pragma once
#include <GL\glew.h>
#include "Shader.h"
#include <memory>

class ShaderProgram
{

public:
	ShaderProgram(std::shared_ptr<Shader> vs, std::shared_ptr<Shader> fs);

	~ShaderProgram();

	GLuint getProgramID();

	void Use();

	static ShaderProgram * CurrentProgram;

	void Refresh();

private:

	GLuint m_program;

	std::shared_ptr<Shader> m_vertexShader;

	std::shared_ptr<Shader> m_fragmentShader;

	void Init(bool mustCreate = true);
};

