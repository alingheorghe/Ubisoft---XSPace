#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"

#pragma pack(push, 1)
struct Vertex
{
    GLfloat x;
    GLfloat y;
	GLfloat z;
	GLfloat u;
	GLfloat v;
	Vertex(){}
	Vertex(GLfloat _x,GLfloat _y,GLfloat _z,GLfloat _u,GLfloat _v): x(_x),y(_y),z(_z),u(_u),v(_v)
	{
	}
};
#pragma pack(pop)

#pragma pack(push , 1)
struct Position
{
    GLfloat x;
    GLfloat y;
	GLfloat z;
	Position(){}
	Position(GLfloat _x,GLfloat _y,GLfloat _z): x(_x),y(_y),z(_z)
	{
	}
};
#pragma pack(pop)

enum
{
	BaseShip,
	Enemy1,
	Enemy2,

};

