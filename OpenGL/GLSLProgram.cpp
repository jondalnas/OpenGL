#include "GLSLProgram.h"

#include <fstream>

GLuint GLSLProgram::_vertexShaderID = 0;
GLuint GLSLProgram::_fragmentShaderID = 0;
GLuint GLSLProgram::_shaderProgramID = 0;
GLuint GLSLProgram::_numAttributes = 0;
std::map<std::string, GLuint> GLSLProgram::attribMap = std::map<std::string, GLuint>();

GLSLProgram::GLSLProgram() {
}


GLSLProgram::~GLSLProgram() {
}

void GLSLProgram::loadShader() {
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

	const char* vertexShaderPtr = loadProgram("Shaders/Shader.vert");

	glShaderSource(_vertexShaderID, 1, &vertexShaderPtr, NULL);
	glCompileShader(_vertexShaderID);

	_fragmentShaderID = glCreateShader(GL_VERTEX_SHADER);

	const char* fragmentShaderPtr = loadProgram("Shaders/Shader.vert");

	glShaderSource(_fragmentShaderID, 1, &fragmentShaderPtr, NULL);
	glCompileShader(_fragmentShaderID);

	_shaderProgramID = glCreateProgram();
	glAttachShader(_shaderProgramID, _vertexShaderID);
	glAttachShader(_shaderProgramID, _fragmentShaderID);

	glBindFragDataLocation(_shaderProgramID, 0, "outColor");

	glLinkProgram(_shaderProgramID);
}

char* GLSLProgram::loadProgram(const std::string& filePath) {
	std::ifstream shaderFile(filePath);
	if (shaderFile.fail()) {
		perror(filePath.c_str());
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(shaderFile, line)) {
		fileContents += line + "\n";
	}

	shaderFile.close();

	return (char*) fileContents.c_str();
}

void GLSLProgram::addAttribute(const std::string& attributeName) {
	glBindAttribLocation(_shaderProgramID, _numAttributes++, attributeName.c_str());
}

void GLSLProgram::use() {
	glUseProgram(_shaderProgramID);
	for (unsigned int i = 0; i < _numAttributes; i++) {
		glEnableVertexAttribArray(i);
	}
}

void GLSLProgram::unuse() {
	glUseProgram(0);
	for (unsigned int i = 0; i < _numAttributes; i++) {
		glDisableVertexAttribArray(i);
	}
}

GLuint GLSLProgram::getAttribLocation(std::string attribName) {
	GLuint attribLocation = 0;
	if (attribMap.find(attribName) != attribMap.end()) {
		return attribLocation;
	}

	attribLocation = glGetAttribLocation(_shaderProgramID, attribName.c_str());

	attribMap.emplace(attribName, attribLocation);

	return attribLocation;
}
