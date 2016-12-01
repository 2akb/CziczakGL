#include "ShaderProgram.h"
#include <iostream>


ShaderProgram::ShaderProgram(std::shared_ptr<Shader> vs, std::shared_ptr<Shader> fs)
	:m_vertexShader(vs),m_fragmentShader(fs)
{
	Init();
}


ShaderProgram::~ShaderProgram()
{

}

GLuint ShaderProgram::getProgramID()
{
	return m_program;
}

void ShaderProgram::Init()
{
	m_program = glCreateProgram();
	glAttachShader(m_program, m_vertexShader->getShaderID());
	glAttachShader(m_program, m_fragmentShader->getShaderID());
	glLinkProgram(m_program);

	GLint success;
	GLchar errBuffer[512];
	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(m_program, 512, NULL, errBuffer);
		std::cerr << "Failed to link shader program. " << errBuffer;
	}
}
