#include "Vao.h"
#include <glad/glad.h>
#include <numeric>

Vao::Vao() {
    glGenVertexArrays(1, &id);
}

Vao::~Vao() {
    glDeleteVertexArrays(1, &id);
}

glint Vao::getId() {
    return id;
}

void Vao::bind() {
    glBindVertexArray(id);
}

void Vao::unbind() {
    glBindVertexArray(0);
}

void Vao::queueAttribf(int componentNo) {
    
    attribNum.push_back(componentNo);
}

void Vao::setAttribs() {
    int stride = sizeof(float) * std::accumulate(attribNum.begin(), attribNum.end(), 0);
    int sizeNow = 0;
    for (int i = 0; i < attribNum.size(); i++)
    {
        int quantity = attribNum[i];
        glVertexAttribPointer(i, quantity, GL_FLOAT, GL_FALSE, stride, (void*)sizeNow);
        glEnableVertexAttribArray(i);
        sizeNow += quantity * sizeof(float);
    }
}