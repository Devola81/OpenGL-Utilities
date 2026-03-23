#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VAO {
public:
	unsigned int ID;

	VAO();

	void Bind();
	void Unbind();
	void Delete();
};