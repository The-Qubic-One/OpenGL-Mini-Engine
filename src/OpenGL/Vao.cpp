#include "Vao.h"
#include <glad/glad.h>

Vao::Vao() {
    glGenVertexArrays(1, &id);
}

Vao::~Vao() {
    glDeleteVertexArrays(1, &id);
}

glint Vao::getId() {
    return id;
}

glint Vao::getNumberOfAttribs() {
    return attribs;
}

void Vao::bind() {
    glBindVertexArray(id);
}

void Vao::unbind() {
    glBindVertexArray(0);
}

void Vao::addAttrib(glint size, glint type, glint normalized, glint stride, const void* pointer) {
    glVertexAttribPointer(attribs, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(attribs);
    attribs++;
}