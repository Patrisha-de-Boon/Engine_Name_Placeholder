#include "mainloop.h"
#include <GLFW/glfw3.h>

bool continueLoop = true;

void mainLoop(GLFWwindow* window) {
    do {
        // Clear the screen
        glClear( GL_COLOR_BUFFER_BIT );

        // Swap buffers and get events
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS
            && glfwWindowShouldClose(window) == 0);
}
