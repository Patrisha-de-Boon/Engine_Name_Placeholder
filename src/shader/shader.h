#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class shader {
    public:
        unsigned int programID;

        Shader(const char* vertexPath, const char* fragmentPath) {
            std::string vertexCode;
            std::string fragmentCode;
            std::ifstream vertexFile;
            std::ifstream fragmentFile;
            std::stringstream vertexStream;
            std::stringstream fragmentStream;

            vertexFile.open(vertexPath);
            fragmentFile.open(fragmentPath);
            vertexStream << vertexFile.rdbuf();
            fragmentStream << fragmentFile.rdbuf();
            vertexCode = vertexStream.str();
            fragmentCode = fragmentStream.str();

            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vertexCode, NULL);
            glCompileShader(vertex);

            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fragmentCode, NULL);
            glCompileShader(fragment);

            programID = glCreateProgram();
            glAttachShader(programID, vertex);
            glAttachShader(programID, fragment);
            glLinkProgram(programID);
            
        }

        void use() {
            glUseProgram(programID);
        }
}

#endif
