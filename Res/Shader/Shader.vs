#version 430 core

layout (location = 0) in vec3 in_Pos;
layout (location = 1) in vec3 in_Color;

out vec4 out_color;

uniform mat4 _mvp;

void main(void) {
    gl_Position =  _mvp * vec4(in_Pos,1.0f);
    out_color = vec4(in_Color,1.0f); 
}