#include "Shader.h"
#include <fstream>
#include <iostream>
#include <sstream>

Shader::Shader(const char * filename, ShaderType sType)
	:m_shaderType(sType)
{
	LoadFromFile(filename, sType);
}


Shader::~Shader()
{
}

GLuint Shader::getShaderID()
{
	return m_shaderID;
}

void Shader::LoadFromFile(const char * filename, ShaderType shaderType)
{
	std::fstream file;
	file.open(filename, std::ios::in);

	if (!file.good())
	{
		std::cerr << "Failed to open shader file";
		return;
	}

	std::stringstream sstream;

	sstream << file.rdbuf();

	file.close();

	std::string str = sstream.str();

	const GLchar * const shaderText = str.c_str();

	GLint success;
	GLchar errBuffer[512];

	m_shaderID = glCreateShader(shaderType);
	glShaderSource(m_shaderID, 1, &shaderText, NULL);
	glCompileShader(m_shaderID);
	glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(m_shaderID, 512, NULL, errBuffer);
		std::cerr << "Failed to compile shader from file: " << filename << " "<< errBuffer;
	}

}
