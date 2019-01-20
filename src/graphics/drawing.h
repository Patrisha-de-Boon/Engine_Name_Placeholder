#ifndef DRAWING_H
#define DRAWING_H
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<shader.h>

unsigned int createShaders();
void draw(Shader shader, float vertices[], int size);
#endif
