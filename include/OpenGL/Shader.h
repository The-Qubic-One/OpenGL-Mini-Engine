#pragma once
#include "Core/types.h"
#include <string>

class Shader
{
    glint id = 0;
    glint type;

public:
    Shader(const int& type);
    ~Shader();

    void source(const std::string& src);

    bool empty() const;
    glint getId() const;
    glint getType() const;
};