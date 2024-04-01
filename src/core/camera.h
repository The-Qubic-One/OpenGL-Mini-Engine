#ifndef CORE_CAMERA_H_
#define CORE_CAMERA_H_

/// @brief Basic perspective camera
class Camera {
  glm::vec3 pos;
  float yaw, pitch;

 public:
  Camera();

  /// @brief constructs a view matrix from the point of the camera
  glm::mat4 view() const;

  /// @brief translates the camera
  /// @param transf displacement vector
  inline void move(glm::vec3 transf) { pos += transf; }

  /// @brief rotates the camera
  /// @param yaw vertical angle in degrees
  /// @param pitch horizontal angle in degrees
  void rotate(float yaw, float pitch);

  /// @brief returns a normalized vector pointing in the direction the camera is
  /// pointing
  glm::vec3 front() const;
  
  /// @brief returns a vector pointing upwards
  glm::vec3 up() const;
};

#endif