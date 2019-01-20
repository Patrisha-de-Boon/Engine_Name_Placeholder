#include "mainloop.h"
#include "drawing.h"
#include <GLFW/glfw3.h>

void mainLoop(GLFWwindow* window) {
    unsigned int shaderProgram = createShaders();

    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
    };

    // float vertices[] = {
    // -0.5f, -0.5f, 0.0f,
    //  0.5f, -0.5f, 0.0f,
    //  0.0f,  0.5f, 0.0f
    // };

    glClear(GL_COLOR_BUFFER_BIT);
    draw(shaderProgram, vertices, sizeof(vertices));
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
