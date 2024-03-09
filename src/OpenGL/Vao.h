#ifndef VAO_H
#define VAO_H

#include "Core/types.h"

class Vao {
  glint id = 0;
  std::vector<glint> atb_len, atb_type, atb_size;

 public:
  Vao();
  ~Vao();

  glint getId();
  void bind();
  void unbind();

  void queueAttrib(glint type, int n);
  void setAttribs();
};

#endif