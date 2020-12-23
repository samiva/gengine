#version 430 core

layout (location = 0) in vec3 in_Pos;
layout (location = 1) in vec2 in_TexCoord;

out vec2 v_texcoord;



void main(void) {
    gl_Position = vec4(in_Pos,1.0f);
    v_texcoord = in_TexCoord; 
}