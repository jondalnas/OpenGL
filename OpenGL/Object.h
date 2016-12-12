#pragma once
#include <GL\glew.h>

class Object {
public:
	Object();
	~Object();

	void init(float x, float y);

	void render();

private:
	GLuint _vboID;
	GLuint _vaoID;
};

