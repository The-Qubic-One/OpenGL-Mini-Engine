#ifndef CORE_INPUT_H_
#define CORE_INPUT_H_

/// @brief Collection of keyboard and mouse input gathering services.
namespace Input {

/// @brief initialize gathering input
/// @param window current window
void init(GLFWwindow* window);

/// @brief process camera movement from cursor (this should be used once per
/// frame)
/// @param window current window
void processCamera(GLFWwindow* window);

};  // namespace Input

#endif