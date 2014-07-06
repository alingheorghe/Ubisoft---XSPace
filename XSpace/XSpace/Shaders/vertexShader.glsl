#version 400 // 150 daca nu e suportat opengl 4.x dar e suportat 3.3
in vec3 in_position;	
in vec2 texCoord;
out vec2 Texcoord;


uniform mat4 model_matrix, view_matrix, projection_matrix ;

void main(){
    Texcoord = texCoord;
	gl_Position = projection_matrix * view_matrix * model_matrix * vec4(in_position, 1); 
}
