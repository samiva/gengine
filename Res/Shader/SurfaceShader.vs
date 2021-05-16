#version 430 core

layout (location = 0) in vec3 in_pos;
layout (location = 1) in vec3 in_normal;

uniform mat4 u_mvp;
uniform mat4 u_model;
uniform vec3 u_lightPos;

out vec3 ex_normal;
out vec3 ex_fragPos;
out vec3 ex_lightVector;

void main(void) 
{
    ex_fragPos = (u_model*vec4(in_position,1.0)).xyz;

    ex_lightVector = normalize(u_lightPos-ex_fragPos);

    ex_normal = mat3(inverse(transpose(u_model)))*in_normal;
    gl_Position = u_mvp * vec4(in_position,1.0);
}