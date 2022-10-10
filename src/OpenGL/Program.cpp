#include "Program.h"
#include <glad/glad.h>
#include <exception>
#include <glm/gtc/type_ptr.hpp>

Program::Program(glint vertex, glint fragment) {
    id = glCreateProgram();

    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
}

Program::~Program() {
    glDeleteProgram(id);
}

void Program::link() {
    glLinkProgram(id);

    int success;
    char infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        throw std::exception(infoLog);
    }
}

void Program::use() {
    glUseProgram(id);
}

glint Program::getId() const {
    return id;
}

void Program::setUniform1f(const char* name, const float& value) {
    glUniform1f(glGetUniformLocation(id, name), value);
}

void Program::setUniform2f(const char* name, const float& value1, const float& value2) {
    glUniform2f(glGetUniformLocation(id, name), value1, value2);
}

void Program::setUniform3f(const char* name, const float& value1, const float& value2, const float& value3) {
    glUniform3f(glGetUniformLocation(id, name), value1, value2, value3);
}

void Program::setUniform4f(const char* name, const float& value1, const float& value2, const float& value3, const float& value4) {
    glUniform4f(glGetUniformLocation(id, name), value1, value2, value3, value4);
}

void Program::setUniform1i(const char* name, const int& value) {
    glUniform1i(glGetUniformLocation(id, name), value);
}

void Program::setUniformMat4f(const char* name, glm::mat4 value) {
    glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, glm::value_ptr(value));
}