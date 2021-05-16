#version 430 core
//in vec4 out_color;

out vec4 color;

uniform vec4 U_color;

void main(void) {
    color = U_color;
}