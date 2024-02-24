#include <glad/glad.h>
#include "Shader.h"
#include "exception"

Shader::Shader(const int& type) : type(type) {
    id = glCreateShader(type);
}

Shader::~Shader() {
    glDeleteShader(id);
}

void Shader::source(const std::string& src) {
    const char* source = src.c_str();
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    int success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        // TODO: fix this
        // throw std::exception(infoLog);
    }
}

bool Shader::empty() const {
    return (bool)id;
}

glint Shader::getId() const {
    return id;
}

glint Shader::getType() const {
    return type;
}