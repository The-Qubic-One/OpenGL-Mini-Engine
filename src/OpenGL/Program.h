#ifndef PROGRAM_H
#define PROGRAM_H

#include "OpenGL/GLObject.h"
#include "OpenGL/Shader.h"

/// @brief represents one openGL program, consisting of shaders and uniforms
///
/// a complete program will require a vertex shader and a fragment shader,
/// as well as have all uniform values registered in order to work properly
class Program : public GLObject {
  glint id;

 public:
  /// initializes the program using two shaders. This is the bare minimum for a
  /// working OpenGL program
  Program(const Shader& vertexShader, const Shader& fragmentShader);
  ~Program();

  void link();
  void use();

  // Uniforms
  void setUniform1f(const char* name, const float& value);
  void setUniform2f(const char* name, const float& value1, const float& value2);
  void setUniform3f(const char* name, const float& value1, const float& value2,
                    const float& value3);
  void setUniform4f(const char* name, const float& value1, const float& value2,
                    const float& value3, const float& value4);

  void setUniform1i(const char* name, const int& value);

  void setUniformMat4f(const char* name, glm::mat4 value);
};

#endif