#ifndef OPENGL_GLOBJECT_H_
#define OPENGL_GLOBJECT_H_

#include "core/types.h"

/// base class of all OpenGL classes, manages their openGL handle
class GLObject {
  /// object handle (id), if this is zero, it means there was an error during
  /// initialization
  glint_t id = 0;

 protected:
  /// sets the object's handle
  void setId(const glint_t& id) noexcept;

 public:
  virtual ~GLObject();

  /// returns object handle (id)
  glint_t getId() const noexcept;

  /// checks if the object was correctly initialized
  bool empty() const noexcept;
};

#endif