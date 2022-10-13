#include "Vao.h"
#include <glad/glad.h>
#include <numeric>
#include <map>

Vao::Vao() {
    glGenVertexArrays(1, &id);
}

Vao::~Vao() {
    glDeleteVertexArrays(1, &id);
}

glint Vao::getId() {
    return id;
}

//  Binding

void Vao::bind() {
    glBindVertexArray(id);
}

void Vao::unbind() {
    glBindVertexArray(0);
}

//  Attributes

std::map<glint, unsigned int> gl_to_size = {
    {GL_INT,            sizeof(int)},
    {GL_UNSIGNED_INT,   sizeof(unsigned int)},
    {GL_FLOAT,          sizeof(float)}
};

void Vao::queueAttrib(glint type, int quantity) {
    atb_len.push_back(quantity);
    atb_type.push_back(type);
    atb_size.push_back(quantity * gl_to_size[type]);
}

void Vao::setAttribs() {
    int stride = std::accumulate(atb_size.begin(), atb_size.end(), 0);
    int sizeNow = 0;
    for (int i = 0; i < atb_len.size(); i++) {
        glVertexAttribPointer(i, atb_len[i], atb_type[i], GL_FALSE, stride, (void*)sizeNow);
        glEnableVertexAttribArray(i);
        sizeNow += atb_size[i];
    }
}