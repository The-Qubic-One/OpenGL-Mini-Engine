#include "opengl/gl_object.h"

GLObject::~GLObject() {}

void GLObject::setId(const glint_t& id) noexcept {
  this->id = id;
}

glint_t GLObject::getId() const noexcept {
  return this->id;
}

bool GLObject::empty() const noexcept {
  return this->id == 0;
}
