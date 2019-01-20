#include "callbacks.h"
#include "globals.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void setupCallbacks(GLFWwindow* window) {
    glfwSetErrorCallback(errorCallback);
    glfwSetJoystickCallback(joystickCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetScrollCallback(window, scrollCallback);
    glfwSetKeyCallback(window, keyCallback);

}

static void errorCallback(int error, const char* description) {
    std::cout << description << std::endl;
}

static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    //std::cout << "mouse click" << std::endl;
}

static void cursorPositionCallback(GLFWwindow* window, double x, double y) {
    globals::cursor_x = x;
    globals::cursor_y = y;
    //std::cout << "mouse move" << std::endl;
}

static void scrollCallback(GLFWwindow* window, double x, double y) {
    //std::cout << "mouse scroll" << std::endl;
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, 1);
    }
    //std::cout << key << std::endl;
}

static void joystickCallback(int joy, int event) {
    //std::cout << joy << std::endl;
}
