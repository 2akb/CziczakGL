#pragma once
#include <GL/glew.h>

class Texture
{
public:
	Texture();
	~Texture();

private:

	bool Load(const char* filename);

	GLuint m_texture;
};

