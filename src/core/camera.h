#ifndef CORE_CAMERA_H_
#define CORE_CAMERA_H_

class Camera {
  glm::vec3 pos;

 public:
  Camera();

  glm::mat4 view() const;
  void move(glm::vec3 transf);

  glm::vec3 front() const;
  glm::vec3 up() const;
};

#endif