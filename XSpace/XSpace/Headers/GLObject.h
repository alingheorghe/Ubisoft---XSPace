#pragma once

#include "Structures.h"

class GLObject
{
private:
	GLuint vertexArrayObject;
	GLuint vertexBufferObject;
	GLuint indexArrayObject;
	GLuint texObject;

	int vertexCount;
	GLuint shaderProgram;
public:
	glm::mat4 modelMatrix;
	int type;
	
	GLObject(GLint _shaderProgramme, GLuint _texObject);
	~GLObject(void);

	void draw();
#if type == BaseShip{
	void move();
	void rotate();
#endif



};

