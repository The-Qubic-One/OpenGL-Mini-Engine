#pragma once
#include <vector>

class AttribList {
    std::vector<uint32_t> attribs;

public:
    void addAtrib(uint32_t val);
    void construct();

    size_t size() const;
    uint32_t getStride() const;
};