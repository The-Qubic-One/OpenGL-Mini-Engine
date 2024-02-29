#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <filesystem>
#include "types.h"

class Util {
public:
    static std::string getTimestamp();
    static path_t getDataPath();
    static path_t getProgramPath();
    static float deltaTime();
};