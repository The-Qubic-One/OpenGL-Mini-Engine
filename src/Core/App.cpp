#include <glad/glad.h>
#include "App.h"
#include "util.h"
#include "types.h"
#include <iostream>
#include <string>

//  GLFW Callbacks

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void glfw_error_callback(int error, const char *description) {
    std::cerr << "GLFW Error " + std::to_string(error) + ": " + std::string(description);
}

void App::initialize() {
    // GLFW
    if (glfwInit() == GL_FALSE) {
        logger.log("Failed to initialize GLFW");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // WINDOW CREATION
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (window == NULL) {
        logger.log("Failed to create GLFW window");
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetErrorCallback(glfw_error_callback);

    //  GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        logger.log("Failed to initialize GLAD");
        exit(EXIT_FAILURE);
    }

    // ADDITIONAL
    glEnable(GL_DEPTH_TEST);

    // APPDATA FOLDER
    path_t appdata = getAppDataPath().append(APPDATA_DIRNAME);
    if(!fileManager.dirExists(appdata))
        fileManager.createDir(appdata);

    // SETTINGS
    settings.reset();
    if (fileManager.fileExists(appdata / "settings.ini")) {
        try {
            settings.setFromTree(fileManager.readIniFile(appdata / "settings.ini"));
            if(!settings.isComplete())
                settings.reset();
        }
        catch(const std::exception& e) {
            logger.log(e.what());
        }
    }
}

void App::terminate() {
    glfwTerminate();

    path_t appdata = getAppDataPath().append(APPDATA_DIRNAME);
    if(!logger.empty())
        fileManager.appendTextFile(appdata / "log.txt", logger.pullLogs());
    fileManager.writeIniFile(appdata / "settings.ini", settings.getTree());
}

GLFWwindow* App::getWindow() const {
    return window;
}

bool App::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void App::startFrame() {
    processInput(window);
    glClearColor(BG_COLOR);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void App::endFrame() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}