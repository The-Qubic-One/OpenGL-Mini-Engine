#include "core/camera.h"

Camera::Camera() {
  pos = glm::vec3(0.0f, 0.0f, 3.0f);
}

glm::mat4 Camera::view() const {
  return glm::lookAt(pos, pos + front(), up());
}

void Camera::move(glm::vec3 transf) {
  pos += transf;
}

glm::vec3 Camera::front() const {
  return glm::vec3(0.0f, 0.0f, -1.0f);
}

glm::vec3 Camera::up() const {
  return glm::vec3(0.0f, 1.0f, 0.0f);
}