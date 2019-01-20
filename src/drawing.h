#ifndef DRAWING_H
#define DRAWING_H
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

unsigned int createShaders();
void draw(unsigned int shaderProgram);
#endif
