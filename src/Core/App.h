#pragma once
#include <GLFW/glfw3.h>

#include "Logger.h"
#include "Settings.h"
#include "FileManager.h"

class App
{
    GLFWwindow* window;
public:
    Logger logger; // -> nothing :D
    Settings settings;
    FileManager fileManager; // -> logger

    void init();
    ~App();

    GLFWwindow* getWindow() const;
    bool shouldClose() const;

    void startFrame();
    void endFrame();
};