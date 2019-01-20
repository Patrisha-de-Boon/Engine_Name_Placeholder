#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vector>
#include "DataStructures.h"
#include "physics_logic.h"

int fps = 60;
double MinMillisPerFrame = 1000/fps;
double lastTime = 0;
glm::vec3 gravity = glm::vec3(0.0, 0.0, -9.81);

void move_shape (DrawableShape* drawable, double elapsedTime) {
    Shape shape = drawable->collidable;
    if (shape.isMovable) {
        shape.centerPoint += (shape.velocity * (float)elapsedTime);
        shape.velocity *= gravity;
    }
}

void physics_loop (GLFWwindow* window, std::vector<DrawableShape>* drawables){
    while (glfwWindowShouldClose(window) == 0) {
        double elapsedTime = glfwGetTime() - lastTime;

        if (elapsedTime >= MinMillisPerFrame){
            lastTime = glfwGetTime();
            for(DrawableShape drawable : *drawables) {
                move_shape(&drawable, elapsedTime);
            }
        }

        for (DrawableShape drawable1 : *drawables) {
            for (DrawableShape drawable2 : *drawables) {
                if (&drawable1 != &drawable2) {
                    CollideShapes(&drawable1.collidable, &drawable2.collidable);
                }
            }
        }    
    }
}

