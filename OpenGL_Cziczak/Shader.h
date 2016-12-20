#pragma once
#include <gl\glew.h>
#include <string>

enum  ShaderType
{
	VERTEX_SHADER = GL_VERTEX_SHADER,
	FRAGMENT_SHADER = GL_FRAGMENT_SHADER
};

class Shader
{
public:

	Shader(const char * filename, ShaderType sType);

	~Shader();

	GLuint getShaderID();

	void Refresh();

private:

	void LoadFromFile(const char* filename, ShaderType shaderType);

	std::string m_filename;

	ShaderType m_shaderType;

	GLuint m_shaderID;
};

