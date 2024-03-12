#ifndef OPENGL_TEXTURE2D_H_
#define OPENGL_TEXTURE2D_H_

#include "opengl/gl_object.h"

class Texture2D : public GLObject {
 private:
  glint_t width, height, channels;

 public:
  Texture2D();
  ~Texture2D();

  void bind();
  static void activateUnit(unsigned int index);
  void unbind();

  void setParameter(glint_t key, glint_t val);

  void data(unsigned char* data,
            glint_t width,
            glint_t height,
            glint_t channels = GL_RGB);
};

#endif