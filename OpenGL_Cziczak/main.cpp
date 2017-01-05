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
		{ glm::vec3(0.5f,-0.5f,1.0f), glm::vec2(1.0f,0.0f) },
		{ glm::vec3(0.0f,0.5f,1.0f), glm::vec2(0.5f,1.0f) }
	};

	GLuint indicies[] = { 0,1,2 };

	VAO vao(new std::vector<Vertex>(vert, std::end(vert)), new std::vector<GLuint>(indicies, std::end(indicies)));

	std::shared_ptr<Shader> vs(new Shader("shaders/vertex.glvs", VERTEX_SHADER));
	std::shared_ptr<Shader> fs(new Shader("shaders/fragment.glfs", FRAGMENT_SHADER));

	ShaderProgram program(vs, fs);

	Texture texture("textures/texture1.png");
	Texture texture1("textures/texture1.jpg");

	//transformacje
	glm::vec3 positions[] = { glm::vec3(0.5f,1.0f,-1.0f),glm::vec3(-0.5f,0.0f,0.0f) };

	glm::mat4 view, projection;

	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	while (window.IsOpen())
	{
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//draw here
		texture.Use(0);
		texture1.Use(1);

		program.Use();

		for(auto pos : positions)
		{
			glm::mat4 model;
			model = glm::translate(model, pos);

			glUniformMatrix4fv(glGetUniformLocation(program.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(glGetUniformLocation(program.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(program.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
			program.setColor(glm::vec4(1.0f, 0.5f, 0.5f, 1.0f));
			vao.Draw();
		}

		//

		glfwSwapBuffers(window.getGLFWWindow());


	}

	return 0;
}