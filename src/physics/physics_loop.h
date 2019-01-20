#ifndef PHYSLOOP
#define PHYSLOOP

#include "DataStructures.h"
#include <GLFW/glfw3.h>
#include <vector>

void physics_loop (GLFWwindow* window, std::vector<DrawableShape>* drawables);
void move_shape (DrawableShape* drawable, double elapsedTime);

#endif