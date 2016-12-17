#include "Main.h"

#include <iostream>

Main::Main() {
}

Main::~Main() {
}

int main() {
	Main main;
	main.start();

	glfwTerminate();

	return 0;
}

void Main::start() {
	initGL();
	initProgram();

	Object o = Object();
	o.init(0, 0);
	Main::objects.push_back(o);
}

void Main::initProgram() {
	_program.loadShader();
	_program.addAttribute("position");
}

void Main::initGL() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	_window = glfwCreateWindow(640, 480, "Game Is Running", nullptr, nullptr);
	glfwMakeContextCurrent(_window);

	glewExperimental = GL_TRUE;
	glewInit();
}

void Main::gameLoop() {
	while (!glfwWindowShouldClose(_window)) {
		glfwSwapBuffers(_window);
		glfwPollEvents();

		_program.use();

		for (int i = 0; i < Main::objects.size(); i++) {
			Object obj = Main::objects[i];

			obj.render();
		}
	}
}