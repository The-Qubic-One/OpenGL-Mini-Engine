#include "AttribList.h"
#include <numeric>
#include <glad/glad.h>

void AttribList::addAtrib(uint32_t val) {
    attribs.push_back(val);
}

void AttribList::construct() {
    for (int i = 0; i < attribs.size(); i++) {
        //glVertexAttribPointer();
    }
    
}

size_t AttribList::size() const {
    return attribs.size();
}

uint32_t AttribList::getStride() const {
    return std::accumulate(attribs.begin(), attribs.end(), 0);
}