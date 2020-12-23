#version 430 core

in vec4 out_color;
in vec2 v_texcoord;

out vec4 color;

uniform sampler2D texture0;

void main(void){

    color = vec4(vec3(1.0-texture2D(texture0,v_texcoord)),1.0);
}