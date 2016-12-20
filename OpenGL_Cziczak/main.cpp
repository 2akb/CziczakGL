#include "Window.h"
#include "VAO.h"
#include "ShaderProgram.h"
#include "glm-0.9.8.2\glm\glm\glm.hpp"
int main()
{
	
	Window window(800, 600, "Tutorial");

	Vertex vert[] = {
		{ glm::vec3(-0.5f,-0.5f,1.0f), glm::vec4(1.0f,0.0f,1.0f,1.0f) },
		{ glm::vec3( 0.5f,-0.5f,1.0f), glm::vec4(0.0f,1.0f,1.0f,1.0f) },
		{ glm::vec3(0.0f,0.5f,1.0f), glm::vec4(1.0f,1.0f,0.0f,1.0f) }
	};

	GLuint indicies[] = { 0,1,2 };

	VAO vao(new std::vector<Vertex>(vert, std::end(vert)), new std::vector<GLuint>(indicies, std::end(indicies)));

	std::shared_ptr<Shader> vs(new Shader("shaders/vertex.glvs", VERTEX_SHADER));
	std::shared_ptr<Shader> fs(new Shader("shaders/fragment.glfs", FRAGMENT_SHADER));

	ShaderProgram program(vs, fs);

	while (window.IsOpen())
	{
		glfwPollEvents();
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//draw here
		
		program.Use();
		vao.Draw();

		//
		
		glfwSwapBuffers(window.getGLFWWindow());


	}
	
	return 0;
}