#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include "Core/types.h"
#include "OpenGL/GLObject.h"

class Texture2D : public GLObject {
 private:
  glint width, height, channels;

 public:
  Texture2D();
  ~Texture2D();

  void bind();
  static void activateUnit(unsigned int index);
  void unbind();

  void setParameter(glint key, glint val);

  void data(unsigned char* data, glint width, glint height,
            glint channels = GL_RGB);
};

#endif