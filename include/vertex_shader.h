#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#version 330 core
layout (location = 0) in vec3 aPos;  //the position variable has attribute position 0

out vec4 vertexColor;

void main() {
    gl_Position = vec4(aPos, 1.0); //convert vec3 to vec4
    vertexColor =vec4(0.5, 0.6, 0.0, 0.0);
}