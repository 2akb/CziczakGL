#pragma once
#include <GL\glew.h>
#include <glm.hpp>
#include <vector>

template <typename T>
void glBufferDataV(GLenum target, const std::vector<T>& buffer, GLenum type)
{
	glBufferData(target, sizeof(T)*buffer.size(), &b[0], type);
}

struct Vertex
{
	glm::vec3 position;
};

class VAO
{
public:
	VAO();
	~VAO();

private:

	GLuint m_VAO;
	GLuint m_VBO;
	GLuint m_EBO;

	std::vector<Vertex> * m_vertexBuffer;

	std::vector<GLuint> * m_elementBuffer;

	void Init();
};

