#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../shader_program/shader_program.h"
#include "../shader_program/LocSet.h"
#include "../include/stb_image/stb_image.h"


class Texture {
public:
	const char* Path;
	int Loc;
	Texture(Shader& shader, const char* Path, const char* LocName, int Loc);
	void BindTexture();
	void ActivateTexture();
private:
	unsigned int ID;
};