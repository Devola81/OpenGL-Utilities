#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

class Vertex {
public:
	glm::vec3 Pos;
	glm::vec2 TexCoord;
	Vertex(glm::vec3 Pos, glm::vec2 TexCoord) {
		this->Pos = Pos;
		this->TexCoord = TexCoord;
	}
};

class VBO {
public:
	GLuint ID;

	VBO(GLfloat* vertices, GLsizeiptr size);
	VBO(std::vector<Vertex> vertices);

	void Bind();
	void Unbind();
	void Delete();
};
