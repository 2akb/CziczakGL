#pragma once
#include <GL\glew.h>
#include "Shader.h"
#include <memory>
#include <detail/type_vec4.hpp>

class ShaderProgram
{

public:
	ShaderProgram(std::shared_ptr<Shader> vs, std::shared_ptr<Shader> fs);

	~ShaderProgram();

	GLuint getProgramID();

	void Use();

	void setColor(glm::vec4 color);

	static ShaderProgram * CurrentProgram;

	void Refresh();

private:

	GLuint m_program;

	std::shared_ptr<Shader> m_vertexShader;

	std::shared_ptr<Shader> m_fragmentShader;

	void Init(bool mustCreate = true);
};

