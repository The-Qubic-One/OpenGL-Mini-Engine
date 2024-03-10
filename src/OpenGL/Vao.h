#ifndef VAO_H
#define VAO_H

#include "Core/types.h"
#include "OpenGL/GLObject.h"

class Vao : public GLObject {
  std::vector<glint> atb_len, atb_type, atb_size;

 public:
  Vao();
  ~Vao();

  void bind();
  void unbind();

  void queueAttrib(glint type, int n);
  void setAttribs();
};

#endif