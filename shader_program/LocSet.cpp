#include "LocSet.h"


void SetVec3(Shader shader, const char Name[], glm::vec3 Data) {

	int VarLoc = glGetUniformLocation(shader.programID, Name);
	glUniform3fv(VarLoc, 1, glm::value_ptr(Data));

};

void SetMat4(Shader shader, const char Name[], glm::mat4 Data) {

	int VarLoc = glGetUniformLocation(shader.programID, Name);
	glUniformMatrix4fv(VarLoc, 1, GL_FALSE, glm::value_ptr(Data));

};

void SetFloat(Shader shader, const char Name[], float Data) {

	int VarLoc = glGetUniformLocation(shader.programID,Name);
	glUniform1f(VarLoc, Data);

};

void SetInt(Shader shader, const char Name[], int Data) {

	int VarLoc = glGetUniformLocation(shader.programID, Name);
	glUniform1i(VarLoc, Data);

};