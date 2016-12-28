#include "Window.h"
#include "VAO.h"
#include "ShaderProgram.h"
#include "glm-0.9.8.2\glm\glm\glm.hpp"
#include "Texture.h"
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

int main()
{
	
	Window window(800, 600, "Tutorial");

	Vertex vert[] = {
		{ glm::vec3(-0.5f,-0.5f,1.0f), glm::vec2(0.0f,0.0f) },
		{ glm::vec3( 0.5f,-0.5f,1.0f), glm::vec2(1.0f,0.0f) },
		{ glm::vec3(0.0f,0.5f,1.0f), glm::vec2(0.5f,1.0f) }
	};

	GLuint indicies[] = { 0,1,2 };

	VAO vao(new std::vector<Vertex>(vert, std::end(vert)), new std::vector<GLuint>(indicies, std::end(indicies)));

	std::shared_ptr<Shader> vs(new Shader("shaders/vertex.glvs", VERTEX_SHADER));
	std::shared_ptr<Shader> fs(new Shader("shaders/fragment.glfs", FRAGMENT_SHADER));

	ShaderProgram program(vs, fs);

	Texture texture("textures/texture1.png");
	Texture texture1("textures/texture1.jpg");

	glm::mat4 transform;
	transform = glm::rotate(transform, 3.14f, glm::vec3(0.0f, 0.0f, 1.0f));

	while (window.IsOpen())
	{
		glfwPollEvents();
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//draw here
		texture.Use(0);
		texture1.Use(1);

		program.Use();

		glUniformMatrix4fv(glGetUniformLocation(program.getProgramID(), "transform"), 1, GL_FALSE, glm::value_ptr(transform));
		program.setColor(glm::vec4(1.0f, 0.5f, 0.5f, 1.0f));
		vao.Draw();

		//
		
		glfwSwapBuffers(window.getGLFWWindow());


	}
	
	return 0;
}