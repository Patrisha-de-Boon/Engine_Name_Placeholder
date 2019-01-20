#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
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
            
            const char * vertexCstring = vertexCode.c_str();
            const char * fragmentCstring = fragmentCode.c_str();
            unsigned int vertex;
            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vertexCstring, NULL);
            glCompileShader(vertex);

            unsigned int fragment;
            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fragmentCstring, NULL);
            glCompileShader(fragment);

            programID = glCreateProgram();
            glAttachShader(programID, vertex);
            glAttachShader(programID, fragment);
            glLinkProgram(programID);
            
        };

        void use() {
            glUseProgram(programID);
        }
        void setBool(const std::string &name, bool value) const {
            glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value); 
        }
        void setInt(const std::string &name, int value) const {
            glUniform1i(glGetUniformLocation(programID, name.c_str()), value); 
        }
        void setFloat(const std::string &name, float value) const {
            glUniform1f(glGetUniformLocation(programID, name.c_str()), value); 
        }
        void setVec2(const std::string &name, const glm::vec2 &value) const { 
            glUniform2fv(glGetUniformLocation(programID, name.c_str()), 1, &value[0]); 
        }
        void setVec2(const std::string &name, float x, float y) const { 
            glUniform2f(glGetUniformLocation(programID, name.c_str()), x, y); 
        }
        void setVec3(const std::string &name, const glm::vec3 &value) const { 
            glUniform3fv(glGetUniformLocation(programID, name.c_str()), 1, &value[0]); 
        }
        void setVec3(const std::string &name, float x, float y, float z) const { 
            glUniform3f(glGetUniformLocation(programID, name.c_str()), x, y, z); 
        }
        void setVec4(const std::string &name, const glm::vec4 &value) const { 
            glUniform4fv(glGetUniformLocation(programID, name.c_str()), 1, &value[0]); 
        }
        void setVec4(const std::string &name, float x, float y, float z, float w) { 
            glUniform4f(glGetUniformLocation(programID, name.c_str()), x, y, z, w); 
        }
        void setMat2(const std::string &name, const glm::mat2 &mat) const {
            glUniformMatrix2fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        }
        void setMat3(const std::string &name, const glm::mat3 &mat) const {
            glUniformMatrix3fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        }
        void setMat4(const std::string &name, const glm::mat4 &mat) const {
            glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        }
};

#endif
