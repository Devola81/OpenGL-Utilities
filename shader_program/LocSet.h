#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader_program.h"
#include <string>

void SetVec3(Shader shader, const char Name[], glm::vec3 Data);
void SetMat4(Shader shader, const char Name[], glm::mat4 Data);
void SetFloat(Shader shader, const char Name[], float Data);
void SetInt(Shader shader, const char Name[], int Data);