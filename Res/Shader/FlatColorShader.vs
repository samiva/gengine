#version 430 core

layout (location = 0) in vec3 in_Pos;

//out vec4 out_color;
uniform mat4 _mvp;
//uniform vec4 U_color;

void main(void) {
    gl_Position =  _mvp * vec4(in_Pos,1.0f);
  //  out_color = U_color;
}