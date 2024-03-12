#include "opengl/program.h"

Program::Program(const Shader& vertex, const Shader& fragment) {
  GLObject::setId(glCreateProgram());

  if (vertex.getType() != ShaderType::VERTEX ||
      fragment.getType() != ShaderType::FRAGMENT)
    throw std::invalid_argument("Incorrect shader types");

  glAttachShader(GLObject::getId(), vertex.getId());
  glAttachShader(GLObject::getId(), fragment.getId());
}

Program::~Program() {
  glDeleteProgram(GLObject::getId());
}

void Program::link() {
  glLinkProgram(GLObject::getId());

  int success;
  char infoLog[512];
  glGetProgramiv(GLObject::getId(), GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(GLObject::getId(), 512, NULL, infoLog);
    throw std::runtime_error(infoLog);
  }
}

void Program::use() {
  glUseProgram(GLObject::getId());
}

void Program::setUniform1f(const char* name, const float& value) {
  glUniform1f(glGetUniformLocation(GLObject::getId(), name), value);
}

void Program::setUniform2f(const char* name,
                           const float& value1,
                           const float& value2) {
  glUniform2f(glGetUniformLocation(GLObject::getId(), name), value1, value2);
}

void Program::setUniform3f(const char* name,
                           const float& value1,
                           const float& value2,
                           const float& value3) {
  glUniform3f(glGetUniformLocation(GLObject::getId(), name), value1, value2,
              value3);
}

void Program::setUniform4f(const char* name,
                           const float& value1,
                           const float& value2,
                           const float& value3,
                           const float& value4) {
  glUniform4f(glGetUniformLocation(GLObject::getId(), name), value1, value2,
              value3, value4);
}

void Program::setUniform1i(const char* name, const int& value) {
  glUniform1i(glGetUniformLocation(GLObject::getId(), name), value);
}

void Program::setUniformMat4f(const char* name, glm::mat4 value) {
  glUniformMatrix4fv(glGetUniformLocation(GLObject::getId(), name), 1, GL_FALSE,
                     glm::value_ptr(value));
}