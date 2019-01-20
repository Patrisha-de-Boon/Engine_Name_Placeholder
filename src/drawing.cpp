#include "drawing.h"

using namespace std;

string vertexShader = "#version 330 core\nlayout (location = 0) in vec3 aPos;\nvoid main(){\ngl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}";
string fragmentShader = "#version 330 core\nout vec4 FragColor;\nvoid main()\n{\nFragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n}";


float vertices[] = {
-0.5f, -0.5f, 0.0f,
 0.5f, -0.5f, 0.0f,
 0.0f,  0.5f, 0.0f
};

void draw() {
    // idk if it works but it doesn't not work
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);\

    // unsigned int vertexShader;
    // vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //
    // glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // glCompileShader(vertexShader);
    //
    // int  success;
    // char infoLog[512];
    // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    //
    // if(!success) {
    //     glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    //     cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
    // }
    //
    // unsigned int fragmentShader;
    // fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // glCompileShader(fragmentShader);
    //
    // unsigned int shaderProgram;
    // shaderProgram = glCreateProgram();
    //
    // glAttachShader(shaderProgram, vertexShader);
    // glAttachShader(shaderProgram, fragmentShader);
    // glLinkProgram(shaderProgram);
    //
    // glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    // if(!success) {
    //     glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    // }
    //
    // glUseProgram(shaderProgram);
    //
    // glDeleteShader(vertexShader);
    // glDeleteShader(fragmentShader);
}
