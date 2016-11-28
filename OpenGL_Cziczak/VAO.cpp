#include "VAO.h"

VAO::VAO()
{
}


VAO::~VAO()
{
}

void VAO::Init()
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferDataV(GL_ARRAY_BUFFER, *m_vertexBuffer, GL_STATIC_DRAW);




	glBindVertexArray(NULL);
}
