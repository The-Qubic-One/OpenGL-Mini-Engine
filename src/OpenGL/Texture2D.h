#pragma once
#include "Core/types.h"
#include <cstdint>

class Texture2D
{
private:
    glint id = 0;
    glint wrap_s, wrap_t, min_filter, mag_filter;   //parameters - fixed for now
    glint width, height;

public:
    Texture2D();
    ~Texture2D();
    void bind();
    void unbind();
    void setParameters();
};