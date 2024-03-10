#ifndef BUFFER_OBJECT_H
#define BUFFER_OBJECT_H

#include "Core/types.h"
#include "OpenGL/GLObject.h"

class BufferObject : public GLObject {
 protected:
  glint type;

 public:
  BufferObject(glint type);
  ~BufferObject();

  glint getType();

  void bind();
  void unbind();

  void data(unsigned int size, const void* data, unsigned int usage);

  template <typename T>
  void data(size_t size, T data[], unsigned int usage) {
    glBufferData(type, size, data, usage);
  }
};

class Vbo : public BufferObject {
 public:
  Vbo() : BufferObject(GL_ARRAY_BUFFER){};
};

class Ebo : public BufferObject {
 public:
  Ebo() : BufferObject(GL_ELEMENT_ARRAY_BUFFER){};
};

#endif