#version 330 core

in vec2 UV;
in vec3 fragmentColor;

uniform sampler2D myTextureSampler;

out vec3 color;

void main(){
//  color = vec3(1.0f, 1.0f, 1.0f);
//  color = fragmentColor;
  color = texture(myTextureSampler, UV).rgb;
}