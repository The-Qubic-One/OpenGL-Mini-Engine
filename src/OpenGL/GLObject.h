#ifndef GL_OBJECT_H
#define GL_OBJECT_H

#include "Core/types.h"

/// base class of all OpenGL classes, manages their openGL handle
class GLObject {
  /// object handle (id), if this is zero, it means there was an error during
  /// initialization
  glint id = 0;

 protected:
  /// sets the object's handle
  void setId(const glint& id) noexcept;

 public:
  virtual ~GLObject();

  /// returns object handle (id)
  glint getId() const noexcept;

  /// checks if the object was correctly initialized
  bool empty() const noexcept;
};

#endif