#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <filesystem>
#include "types.h"

std::string getTimestamp();
path_t getDataPath();
path_t getProgramPath();
float deltaTime();