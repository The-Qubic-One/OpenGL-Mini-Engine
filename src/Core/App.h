#pragma once

#include "Core/FileManager.h"
#include "Core/Logger.h"
#include "Settings/Settings.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void glfw_error_callback(int error, const char* description);

class App {
  GLFWwindow* window;
  std::string imgui_log;
  std::string imgui_settings;

  void displayPerformanceWindow();

 public:
  float bg_color[3] = {BG_COLOR};
  bool displayDiagnostics = true;

  Logger logger;
  Settings settings;

  void initialize();
  void terminate();

  GLFWwindow* getWindow() const;
  bool shouldClose() const;

  void startFrame();
  void endFrame();
};