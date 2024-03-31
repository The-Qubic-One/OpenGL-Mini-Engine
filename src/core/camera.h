#ifndef CORE_CAMERA_H_
#define CORE_CAMERA_H_

class Camera {
  glm::vec3 pos;
  float yaw, pitch;

 public:
  Camera();

  glm::mat4 view() const;

  inline void move(glm::vec3 transf) { pos += transf; }
  void rotate(float yaw, float pitch);

  glm::vec3 front() const;
  glm::vec3 up() const;
};

#endif