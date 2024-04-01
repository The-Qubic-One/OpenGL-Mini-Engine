#include "core/camera.h"

#include "core/global.h"

Camera::Camera() {
  pos = glm::vec3(0.0f, 0.0f, 3.0f);
  yaw = -90.0f;
  pitch = -15.0f;
}

glm::mat4 Camera::view() const {
  return glm::lookAt(pos, pos + front(), up());
}

void Camera::rotate(float yaw, float pitch) {
  this->yaw += yaw;
  this->pitch = std::min(std::max(this->pitch + pitch, -89.9f), 89.9f);
}

glm::vec3 Camera::front() const {
  glm::vec3 direction(cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
                      sin(glm::radians(pitch)),
                      sin(glm::radians(yaw)) * cos(glm::radians(pitch)));
  return glm::normalize(direction);
}

glm::vec3 Camera::up() const {
  return glm::vec3(0.0f, 1.0f, 0.0f);
}