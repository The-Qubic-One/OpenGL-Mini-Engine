#include "core/input.h"

#include "core/global.h"
#include "core/types.h"
#include "core/util.h"

void key_callback(GLFWwindow* window,
                  int key,
                  int scancode,
                  int action,
                  int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glint_t inverted = Global::cameraMovementEnabled ? GLFW_CURSOR_NORMAL
                                                     : GLFW_CURSOR_DISABLED;
    glfwSetInputMode(window, GLFW_CURSOR, inverted);
    Global::cameraMovementEnabled = !Global::cameraMovementEnabled;
    Global::firstCameraRecord = true;
  }
}

void processMouse(GLFWwindow* window, double xpos, double ypos) {
  using namespace Global;

  if (!cameraMovementEnabled)
    return;

  if (firstCameraRecord) {
    cursorX = xpos;
    cursorY = ypos;
    firstCameraRecord = false;
    return;
  }

  float deltaX = xpos - cursorX;
  float deltaY = ypos - cursorY;
  cursorX = xpos;
  cursorY = ypos;

  float sensitivity = 40.0f * Time::deltaTime();
  camera.rotate(deltaX * sensitivity, -deltaY * sensitivity);
}

void Input::init(GLFWwindow* window) {
  glfwSetKeyCallback(window, key_callback);
  glfwSetCursorPosCallback(window, processMouse);
}

void Input::processCamera(GLFWwindow* window) {
  using namespace Global;

  const float cameraSpeed = 2.5f * Time::deltaTime();  // adjust accordingly
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    camera.move(cameraSpeed * camera.front());
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    camera.move(-cameraSpeed * camera.front());
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    camera.move(-glm::normalize(glm::cross(camera.front(), camera.up())) *
                cameraSpeed);
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    camera.move(glm::normalize(glm::cross(camera.front(), camera.up())) *
                cameraSpeed);
}
