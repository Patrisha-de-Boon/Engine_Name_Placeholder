#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "DataStructures.h"
#include "physics_logic.h"

int fps = 60;
double MinMillisPerFrame = 1000/fps;

void physics_loop (GLFWwindow* window){
    double lastTime = 0;

    while (glfwWindowShouldClose(window) == 0) {
        double elapsedTime = glfwGetTime() - lastTime;
        if (elapsedTime >= MinMillisPerFrame){
            
            
            lastTime = glfwGetTime();
        }
    } 
}