#pragma once
#include "Core/types.h"
#include <cstdint>
#include <glm/mat4x4.hpp>

class Program
{
    glint id;

public:
    Program(glint vertex, glint fragment);
    ~Program();

    void link();
    void use();

    glint getId() const;

    // Uniforms
    void setUniform1f(const char* name, const float& value);
    void setUniform2f(const char* name, const float& value1, const float& value2);
    void setUniform3f(const char* name, const float& value1, const float& value2, const float& value3);
    void setUniform4f(const char* name, const float& value1, const float& value2, const float& value3, const float& value4);
    
    void setUniform1i(const char* name, const int& value);

    void setUniformMat4f(const char* name, glm::mat4 value);
};