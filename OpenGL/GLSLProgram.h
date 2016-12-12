#pragma once

#include <GL/glew.h>

#include <string>
#include <map>

class GLSLProgram {
public:
	GLSLProgram();
	~GLSLProgram();

	static void loadShader();
	static void addAttribute(const std::string& attributeName);
	static void use();
	static void unuse();
	static GLuint getAttribLocation(std::string attribName);
private:
	static GLuint _vertexShaderID;
	static GLuint _fragmentShaderID;
	static GLuint _shaderProgramID;
	static GLuint _numAttributes;
	static std::map<std::string, GLuint> attribMap;
	static char* loadTexture(const std::string& filePath);
};