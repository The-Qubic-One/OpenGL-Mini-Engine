#ifndef OPENGL_SHADER_H_
#define OPENGL_SHADER_H_

#include "OpenGL/GLObject.h"

/// @brief represents all possible types of shader (vertex, geometry or
/// fragment)
/// @todo compute, tess_controll and tess_evaluation type values cannot be
/// imported
enum class ShaderType { VERTEX, GEOMETRY, FRAGMENT };

/// maps ShaderType enum to an actual uint value used in OpenGL, this exists to
/// decouple header files from glad API
glint mapShaderType(ShaderType type);

/// @brief represents one openGL shader, holds its initialization, compilation
/// and termination
///
/// for the shader to actually work, it first has to be compiled from source,
/// provided in compile().
class Shader : public GLObject {
  ShaderType type;

 public:
  /// initializes an openGL shader
  Shader(const ShaderType& type);

  /// destructor, will automatically free the openGL shader
  ~Shader();

  /// sets the shader's source and compiles the shader
  void compile(const std::string& source);

  /// returns type of the shader
  ShaderType getType() const;
};

#endif