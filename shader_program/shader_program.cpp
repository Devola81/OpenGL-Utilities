#include "shader_program.h"
#include <vector>

Shader::Shader(std::string vertex, std::string frag) {

		std::fstream vert_file(vertex);
		std::fstream frag_file(frag);
		std::string temp_vert_string;
		std::string temp_frag_string;
		std::string source_vert_string;
		std::string source_frag_string;


		while (std::getline(vert_file, temp_vert_string)) {
			source_vert_string += temp_vert_string;
			source_vert_string +=  "\n";
		}

		while (std::getline(frag_file, temp_frag_string)) {
			source_frag_string += temp_frag_string;
			source_frag_string +=  "\n";
		}

		const char* vertexsource = source_vert_string.c_str();
		const char* fragmentsource = source_frag_string.c_str();


		vertID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertID, 1, &vertexsource, NULL);
		glCompileShader(vertID);

        
        fragID = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragID, 1, &fragmentsource, NULL);
        glCompileShader(fragID);

        

        programID = glCreateProgram();
        glAttachShader(programID, vertID);
        glAttachShader(programID, fragID);
        glLinkProgram(programID);

}

void Shader::UseShader() {
	glUseProgram(programID);
}

void Shader::DeleteShader() {
	glDeleteShader(vertID);
	glDeleteShader(fragID);
}

void Shader::SetVec3( const char Name[], glm::vec3 Data) {

	int VarLoc = glGetUniformLocation(programID, Name);
	glUniform3fv(VarLoc, 1, glm::value_ptr(Data));

};

void Shader::SetMat4(const char Name[], glm::mat4 Data) {

	int VarLoc = glGetUniformLocation(programID, Name);
	glUniformMatrix4fv(VarLoc, 1, GL_FALSE, glm::value_ptr(Data));

};

void Shader::SetFloat(const char Name[], float Data) {

	int VarLoc = glGetUniformLocation(programID, Name);
	glUniform1f(VarLoc, Data);

};

void Shader::SetInt(const char Name[], int Data) {

	int VarLoc = glGetUniformLocation(programID, Name);
	glUniform1i(VarLoc, Data);

};