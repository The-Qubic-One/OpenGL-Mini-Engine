#pragma once
#include "Core/types.h"
#include <cstdint>
#include <vector>

class Vao
{
    glint id = 0;
    std::vector<int> attribNum;

public:
    Vao();
    ~Vao();

    glint getId();
    void bind();
    void unbind();

    void queueAttribf(int componentNo);
    void setAttribs();
};