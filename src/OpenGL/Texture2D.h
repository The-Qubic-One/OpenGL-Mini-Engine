#pragma once
#include "Core/types.h"
#include <cstdint>

class Texture2D
{
private:
    glint id = 0;
    glint width, height, channels;

public:
    Texture2D();
    ~Texture2D();

    void bind();
    void unbind();
    
    void setParameter(glint key, glint val);

    void data(unsigned char* data, glint width, glint height);
};