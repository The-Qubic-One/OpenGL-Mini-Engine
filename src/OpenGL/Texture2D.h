#pragma once
#include "Core/types.h"
#include <cstdint>
#include <glad/glad.h>

class Texture2D
{
private:
    glint id = 0;
    glint width, height, channels;

public:
    Texture2D();
    ~Texture2D();

    void bind();
    static void activateUnit(unsigned int index);
    void unbind();
    
    void setParameter(glint key, glint val);

    void data(unsigned char* data, glint width, glint height, glint channels = GL_RGB);
};