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

int axisValue(GLFWwindow* window, glint_t positive, glint_t negative) {
  int plus = glfwGetKey(window, positive) == GLFW_PRESS;
  int minus = glfwGetKey(window, negative) == GLFW_PRESS;
  return plus - minus;
}

void Input::processCamera(GLFWwindow* window) {
  using namespace Global;

  const float cameraSpeed = 2.5f * Time::deltaTime();  // adjust accordingly

  // up - down
  camera.move(cameraSpeed *
              axisValue(window, GLFW_KEY_SPACE, GLFW_KEY_LEFT_SHIFT) *
              glm::vec3(0.0f, 1.0f, 0.0f));

  // front - back
  camera.move(cameraSpeed * axisValue(window, GLFW_KEY_W, GLFW_KEY_S) *
              camera.front());

  // left - right
  camera.move(cameraSpeed * axisValue(window, GLFW_KEY_A, GLFW_KEY_D) *
              -glm::normalize(glm::cross(camera.front(), camera.up())));
}
