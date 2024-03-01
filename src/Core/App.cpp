#include <glad/glad.h>
#include "Core/App.h"
#include "Core/util.h"
#include "Core/types.h"
#include "Settings/SettingsLoader.h"
#include <iostream>
#include <string>
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"

void App::displayPerformanceWindow() {
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_NoBackground;
    window_flags |= ImGuiWindowFlags_AlwaysAutoResize;
    window_flags |= ImGuiWindowFlags_NoInputs;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
    bool p_open = true;

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("Performance", &p_open, window_flags);
    ImGui::Text("%.3f ms\n%.1f FPS", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}

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

    // IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();


    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(GLSL_VERSION);

    // APPDATA FOLDER
    path_t appdata = Util::getDataPath();
    if(!fileManager.dirExists(appdata))
        fileManager.createDir(appdata);

    imgui_settings = (appdata / IMGUI_SETTINGS_FILENAME).string();
    imgui_log = (appdata / IMGUI_LOG_FILENAME).string().c_str();

    io.IniFilename = imgui_settings.c_str();
    io.LogFilename = imgui_log.c_str();

    // SETTINGS
    settings.setDefaults();

    if (fileManager.fileExists(appdata / "settings.ini")) {
        try {
            std::string loaded = fileManager.readTextFile(appdata / "settings.ini");
            settings = SettingsLoader::loadFrom(loaded);
        } catch(const std::exception& e) {
            logger.log(e.what());
        }
    }
}

void App::terminate() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();

    path_t appdata = Util::getDataPath();
    
    if(!logger.empty())
        fileManager.appendTextFile(appdata / "log.txt", logger.pullLogs());
    
    fileManager.writeTextFile(appdata / "settings.ini", SettingsLoader::saveInto(settings));
}

GLFWwindow* App::getWindow() const {
    return window;
}

bool App::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void App::startFrame() {
    processInput(window);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    
    //glClearColor(BG_COLOR);
    glClearColor(bg_color[0], bg_color[1], bg_color[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (displayDiagnostics)
        displayPerformanceWindow();
}

void App::endFrame() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
    glfwPollEvents();
}
