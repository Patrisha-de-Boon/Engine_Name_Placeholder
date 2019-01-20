#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void setupCallbacks(GLFWwindow* window);

static void errorCallback(int error, const char* description);
static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
static void cursorPositionCallback(GLFWwindow* window, double x, double y);
static void scrollCallback(GLFWwindow* window, double x, double y);
static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void joystickCallback(int joy, int event);
#endif
