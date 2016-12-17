#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Object.h"
#include "GLSLProgram.h"

#include <vector>

class Main {
public:
	Main();
	~Main();

	std::vector<Object> objects;

	void start();

private:
	GLSLProgram _program;

	GLFWwindow *_window;

	void initProgram();
	void initGL();
	void gameLoop();
};

