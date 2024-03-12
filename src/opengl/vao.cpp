#include "opengl/vao.h"

Vao::Vao() {
  glint_t temp = getId();
  glGenVertexArrays(1, &temp);
  setId(temp);
}

Vao::~Vao() {
  glint_t temp = getId();
  glDeleteVertexArrays(1, &temp);
  setId(temp);
}

//  Binding

void Vao::bind() {
  glBindVertexArray(getId());
}

void Vao::unbind() {
  glBindVertexArray(0);
}

//  Attributes

std::map<glint_t, unsigned int> gl_to_size = {
    {GL_INT, sizeof(int)},
    {GL_UNSIGNED_INT, sizeof(unsigned int)},
    {GL_FLOAT, sizeof(float)}};

void Vao::queueAttrib(glint_t type, int quantity) {
  atb_len.push_back(quantity);
  atb_type.push_back(type);
  atb_size.push_back(quantity * gl_to_size[type]);
}

void Vao::setAttribs() {
  int stride = std::accumulate(atb_size.begin(), atb_size.end(), 0);
  uintptr_t sizeNow = 0;
  for (int i = 0; i < atb_len.size(); i++) {
    glVertexAttribPointer(i, atb_len[i], atb_type[i], GL_FALSE, stride,
                          (void*)sizeNow);
    glEnableVertexAttribArray(i);
    sizeNow += atb_size[i];
  }
}