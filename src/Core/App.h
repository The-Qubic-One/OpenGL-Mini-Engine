#pragma once
#include <GLFW/glfw3.h>

#include "Logger.h"
#include "Settings.h"
#include "FileManager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void glfw_error_callback(int error, const char *description);

class App
{
    GLFWwindow* window;

public:
    Logger logger; // -> nothing :D
    Settings settings;
    FileManager fileManager; // -> logger

    void initialize();
    void terminate();

    GLFWwindow* getWindow() const;
    bool shouldClose() const;

    void startFrame();
    void endFrame();
};