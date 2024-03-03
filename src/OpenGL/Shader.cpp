#include "OpenGL/Shader.h"

#include <glad/glad.h>
#include <stdexcept>

glint mapShaderType(ShaderType type) {
    switch (type) {
            case ShaderType::VERTEX: return GL_VERTEX_SHADER;
            case ShaderType::GEOMETRY: return GL_GEOMETRY_SHADER;
            case ShaderType::FRAGMENT: return GL_FRAGMENT_SHADER;
            default: throw std::runtime_error("Shader Type not convertable, value: " + (glint)type);
    }
}

Shader::Shader(const ShaderType& type) : type(type) {
    GLObject::setId(glCreateShader(mapShaderType(type)));
}

Shader::~Shader() {
    glDeleteShader(GLObject::getId());
}

void Shader::compile(const std::string& source) {
    const char* sourceChar = source.c_str();
    glShaderSource(GLObject::getId(), 1, &sourceChar, NULL);
    glCompileShader(GLObject::getId());

    int success;
    char infoLog[512];
    glGetShaderiv(GLObject::getId(), GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(GLObject::getId(), 512, NULL, infoLog);
        throw std::runtime_error(infoLog);
    }
}

ShaderType Shader::getType() const {
    return type;
}