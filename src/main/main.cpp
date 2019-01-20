//main file
//build a window and call main loop

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "mainloop.h"
#include "callbacks.h"

#include <iostream>

int main(int argc, char** argv) {
    if (!glfwInit()) {
        std::cout << "Init failed";
        return 1;
    }
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "Engine_Title_Placeholder", NULL, NULL);

    if (!window) {
        std::cout << "Window failed";
        return 1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    setupCallbacks(window);

    mainLoop(window);

    //shutdown protocol
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
