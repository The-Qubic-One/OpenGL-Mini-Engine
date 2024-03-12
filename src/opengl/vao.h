#ifndef OPENGL_VAO_H_
#define OPENGL_VAO_H_

#include "opengl/gl_object.h"

class Vao : public GLObject {
  std::vector<glint_t> atb_len, atb_type, atb_size;

 public:
  Vao();
  ~Vao();

  void bind();
  void unbind();

  void queueAttrib(glint_t type, int n);
  void setAttribs();
};

#endif