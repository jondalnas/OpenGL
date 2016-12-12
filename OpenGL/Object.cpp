#include "Object.h"
#include "GLSLProgram.h"

Object::Object() {
	_vboID = 0;
}


Object::~Object() {
}

void Object::init(float x, float y) {
	if (_vaoID == 0) {
		glGenVertexArrays(1, &_vaoID);
	}
	if (_vboID == 0) {
		glGenBuffers(1, &_vboID);
	}

	float vertices[] = { 0.0f,  0.5f,
						 0.5f, -0.5f,
						-0.5f, -0.5f };

	glBindVertexArray(_vaoID);

	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	glVertexAttribPointer(GLSLProgram::getAttribLocation("position"), 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(GLSLProgram::getAttribLocation("position"));

}

void Object::render() {
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
