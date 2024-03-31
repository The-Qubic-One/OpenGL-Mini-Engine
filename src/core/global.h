#ifndef CORE_GLOBAL_H_
#define CORE_GLOBAL_H_

#include "core/camera.h"

/// @brief  namespace for default global data
namespace Global {
inline float cursorX = 0.0f, cursorY = 0.0f;

inline Camera camera;

inline bool firstCameraRecord = true;
}  // namespace Global

#endif