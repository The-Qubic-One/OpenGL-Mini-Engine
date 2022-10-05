#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <filesystem>
#include "types.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

std::string getTimeAndDate();
path_t getAppDataPath();