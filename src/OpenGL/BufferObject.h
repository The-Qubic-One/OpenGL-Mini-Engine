#pragma once
#include "Core/types.h"
#include <cstdint>

class BufferObject
{
    glint id = 0;
    glint type;

public:
    BufferObject(glint type);
    ~BufferObject();

    glint getId();
    glint getType();
    void bind();
    void unbind();

    void data(unsigned int size, const void* data, unsigned int usage);

    template<typename T>
    void data(size_t size, T data[], unsigned int usage) {
        glBufferData(type, size, data, usage);
    }
};