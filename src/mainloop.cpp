#include "mainloop.h"
#include "drawing.h"
#include <GLFW/glfw3.h>

void mainLoop(GLFWwindow* window) {
    do {
        // Clear the screen
        glClear( GL_COLOR_BUFFER_BIT );

        draw();
        // Swap buffers and get events
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwWindowShouldClose(window) == 0);
}
