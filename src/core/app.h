#ifndef CORE_APP_H_
#define CORE_APP_H_

#include "core/camera.h"
#include "core/file_manager.h"
#include "core/logger.h"
#include "settings/settings.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height);

void processMouse(GLFWwindow* window, double xpos, double ypos);
void glfwErrorCallback(int error, const char* description);

class App {
  GLFWwindow* window;
  std::string imgui_log;
  std::string imgui_settings;

  void processInput(GLFWwindow* window);

  void displayPerformanceWindow();

 public:
  float bg_color[3] = {BG_COLOR};
  bool display_diagnostics = true;

  Logger logger;
  Settings settings;

  void initialize();
  void terminate();

  GLFWwindow* getWindow() const;
  bool shouldClose() const;

  void startFrame();
  void endFrame();
};

#endif