#include "ShaderProgram.h"
#include <iostream>

ShaderProgram * ShaderProgram::CurrentProgram = nullptr;

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

void ShaderProgram::Use()
{
	glUseProgram(m_program);
	CurrentProgram = this;
}

void ShaderProgram::setColor(glm::vec4 color)
{
	GLuint location = glGetUniformLocation(m_program, "uniformColor");
	glUniform4fv(location, 1, (GLfloat*)&color);
}

void ShaderProgram::Refresh()
{
	m_fragmentShader->Refresh();
	m_vertexShader->Refresh();
	Init();
}

void ShaderProgram::Init(bool mustCreate)
{
	if(mustCreate)
	{
		m_program = glCreateProgram();
	}
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
	glUseProgram(m_program);
	glUniform1i(glGetUniformLocation(m_program, "ourTexture"), 0);
	glUniform1i(glGetUniformLocation(m_program, "ourTexture1"), 1);
	glUseProgram(0);
}
