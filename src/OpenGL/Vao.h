#pragma once
#include "Core/types.h"
#include <cstdint>

class Vao
{
    glint id = 0;
    glint attribs = 0;

public:
    Vao();
    ~Vao();

    glint getId();
    glint getNumberOfAttribs();
    void bind();
    void unbind();

    void addAttrib(glint size, glint type, glint normalized, glint stride, const void* pointer);
};