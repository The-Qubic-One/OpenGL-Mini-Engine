#include <glad/glad.h>
#include "App.h"
#include "util.h"
#include "types.h"
#include <iostream>

void App::init() {
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

    //  GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        logger.log("Failed to initialize GLAD");
        exit(EXIT_FAILURE);
    }

    // APPDATA FOLDER
    path_t appdata = getAppDataPath().append(APPDATA_DIRNAME);
    if(!fileManager.dirExists(appdata))
        fileManager.createDir(appdata);

    // SETTINGS
    settings.reset();
    if (fileManager.fileExists(appdata / "settings.ini")) {
        settings.setFromTree(fileManager.readIniFile(appdata / "settings.ini"));
    }
}

App::~App() {
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
    glClear(GL_COLOR_BUFFER_BIT);
}

void App::endFrame() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}