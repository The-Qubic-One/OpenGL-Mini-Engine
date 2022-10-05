#include "BufferObject.h"
#include <glad/glad.h>

BufferObject::BufferObject(glint type) : type(type) {
    glGenBuffers(1, &id);
}

BufferObject::~BufferObject() {
    glDeleteBuffers(1, &id);
}

glint BufferObject::getId() {
    return id;
}

glint BufferObject::getType() {
    return type;
}

void BufferObject::bind() {
    glBindBuffer(type, id);
}

void BufferObject::unbind() {
    glBindBuffer(type, 0);
}

void BufferObject::data(unsigned int size, const void* data, unsigned int usage) {
    bind();
    glBufferData(type, size, data, usage);
    unbind();
}