#include "GLObject.h"

//constructor
GLObject::GLObject(GLint _shaderProgramme, GLuint _texObject)
{
	//primim shader-ul
	this->shaderProgram = _shaderProgramme;

	//init buffers
	Vertex vertexBuffer[4];
	vertexBuffer[0] = Vertex(0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	vertexBuffer[1] = Vertex(0.3f, 0.0f, 0.0f, 1.0f, 0.0f);
	vertexBuffer[2] = Vertex(0.3f, 0.3f, 0.0f, 1.0f, 1.0f);
	vertexBuffer[3] = Vertex(0.0f, 0.3f, 0.0f, 0.0f, 1.0f);
	
	GLushort indices[] = { 0, 1, 2, 0, 2, 3};

	//get shader positions
	GLint vertexPosition = glGetAttribLocation(shaderProgram, "in_position");
	GLint texCoord = glGetAttribLocation(shaderProgram, "texCoord");

	//setup GPU buffers
	this->vertexCount = 6;

	//vertexArray
	glGenVertexArrays(1, &this->vertexArrayObject);
	glBindVertexArray(this->vertexArrayObject);
	
	//vertexBuffer
	glGenBuffers(1, &this->vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBuffer) , vertexBuffer, GL_STATIC_DRAW);
	
	//vertex position
	glVertexAttribPointer(vertexPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), &vertexBuffer[0]);

	//texture
	glVertexAttribPointer(texCoord, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), &vertexBuffer[0].u);
	
	glEnableVertexAttribArray(vertexPosition); 
	glEnableVertexAttribArray(texCoord);
	
	//indexArray
	glGenBuffers(1, &this->indexArrayObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexArrayObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexCount * sizeof(GLushort), indices, GL_STATIC_DRAW);

	//disable buffers
	glBindVertexArray(NULL);
	glBindBuffer(GL_ARRAY_BUFFER, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);

	this->texObject = _texObject;
	this->modelMatrix = glm::mat4(1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1);
	this->type = BaseShip;
}
//destructor
GLObject::~GLObject(void)
{
	glDeleteBuffers(1,&this->vertexBufferObject);
	glDeleteBuffers(1,&this->vertexArrayObject);
	glDeleteBuffers(1,&this->indexArrayObject);
}

void GLObject::draw(){
	glUseProgram(shaderProgram);
	glBindVertexArray(this->vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObject);
	
	//vertex position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);

	//texture
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(NULL + 12));

	glEnableVertexAttribArray(0); 
	glEnableVertexAttribArray(1);
	

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexArrayObject);
	
	glDrawElements(GL_TRIANGLES, this->vertexCount, GL_UNSIGNED_SHORT, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
	glBindVertexArray(NULL);

}
