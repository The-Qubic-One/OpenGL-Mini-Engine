#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <filesystem>
#include "types.h"

//! @brief Class that provides utility services which implementation would differ between Windows and Linux.
//! @todo implement getDataPath() for Windows
class Util {
public:
    static std::string getTimestamp();
    static path_t getDataPath();
    static path_t getProgramPath();
    static float deltaTime();
};