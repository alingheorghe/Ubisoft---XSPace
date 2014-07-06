#pragma once

#include "GLObject.h"
#include "stb_image.h"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtc\matrix_transform.hpp"

#include <iostream>
#include <vector>


class Display
{
private:
	GLFWwindow* window;
	GLint viewportHeight;
	GLint viewportWidth;

	//shader
	GLuint shader_programme;

	//objects
	std::vector<GLObject*> objects;
	GLuint* texIndex;

	glm::mat4 view_mat, proj_mat;
public:
	Display(int width, int height, char* title);
	virtual ~Display(void);

	void Update();

	char * LoadFileInMemory(const char* filename);
	GLuint loadShaderProgramme(char *vertexShader, char* fragmentShader);
	GLuint* getTextures(std::vector<std::string> textures);
};

