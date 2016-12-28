#pragma once
#include <GL/glew.h>

class Texture
{
public:
	Texture(const char * filename);

	GLuint getTextureID();

	void Use(int id);
	
	~Texture();

private:

	bool Load(const char* filename);

	GLuint m_texture;
};

