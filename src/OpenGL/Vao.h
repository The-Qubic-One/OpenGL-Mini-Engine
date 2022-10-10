#pragma once
#include "Core/types.h"
#include <cstdint>
#include <vector>

class Vao
{
    glint id = 0;
    std::vector<glint> atb_len, atb_type, atb_size;

public:
    Vao();
    ~Vao();

    glint getId();
    void bind();
    void unbind();

    void queueAttrib(glint type, int n);
    void setAttribs();
};