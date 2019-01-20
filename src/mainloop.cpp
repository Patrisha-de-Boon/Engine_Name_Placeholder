#include "mainloop.h"
#include "drawing.h"
#include <GLFW/glfw3.h>

void mainLoop(GLFWwindow* window) {
    unsigned int shaderProgram = createShaders();
    glClear(GL_COLOR_BUFFER_BIT);
    draw(shaderProgram);
    glfwSwapBuffers(window);

    do {
        // Clear the screen
        // glClear(GL_COLOR_BUFFER_BIT);

        // draw(shaderProgram);

        // Swap buffers and get events
        // glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwWindowShouldClose(window) == 0);
}
