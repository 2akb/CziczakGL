#include "Texture.h"
#include "FreeImage.h"
#include <iostream>

Texture::Texture(const char * filename)
{
	Load(filename);
}

GLuint Texture::getTextureID()
{
	return m_texture;
}

Texture::~Texture()
{
}



bool Texture::Load(const char* filename)
{
	FreeImage_Initialise();

	FIBITMAP * data = FreeImage_Load(FreeImage_GetFIFFromFilename(filename), filename);
	FIBITMAP * bitmap = FreeImage_ConvertTo32Bits(data);
	int width = FreeImage_GetWidth(bitmap);
	int height = FreeImage_GetHeight(bitmap);

	glCreateTextures(GL_TEXTURE_2D,1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, (GLvoid*)FreeImage_GetBits(bitmap));
	glGenerateMipmap(GL_TEXTURE_2D);

	GLuint error = glGetError();
	if(error!=0)
	{
		std::cerr << "Error creating texture";
		return false;
	}

	FreeImage_Unload(bitmap);
	FreeImage_Unload(data);

	glBindTexture(GL_TEXTURE_2D, 0);

	FreeImage_DeInitialise();

	return true;

}
