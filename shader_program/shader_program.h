#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader{
public:

	GLuint vertID;
	GLuint fragID;
	GLuint programID;

	Shader(std::string vertex ,std::string frag);

	void UseShader();
	void DeleteShader();
	void SetVec3(const char Name[], glm::vec3 Data);
	void SetMat4(const char Name[], glm::mat4 Data);
	void SetFloat(const char Name[], float Data);
	void SetInt(const char Name[], int Data);
};