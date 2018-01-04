#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 1) in vec3 vertexPosition_modelspace;
layout(location = 2) in vec3 vertexColor;
layout(location = 3) in vec2 vertexUV;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

out vec3 fragmentColor;
out vec2 UV;

void main(){
  // Output position of the vertex, in clip space : MVP * position
  gl_Position =  MVP * vec4(vertexPosition_modelspace,1);

  fragmentColor = vertexColor;
  UV = vertexUV;
}
