#include <glad/glad.h>
#include "util.h"
#include "ImGui/imgui.h"

#ifdef _WIN32

#include <shlobj_core.h>
#include <chrono>

path_t getDataPath() {
    wchar_t* path;
    SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &path);
    return path_t(path).append(APPDATA_DIRNAME);
}

std::string getTimestamp() {
    auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char timeString[20] = "";

    // Oh and a tm struct too! Gotta have that, just to make it more complicated!
    tm tmStruct;

    // Oh and BTW, you can't just get your local time directly;
    // you need to call localtime_s with the tm AND the time_t!
    // Can't use localtime anymore since it's "unsafe"
    localtime_s(&tmStruct, &time);

    // Hurray! We finally have a readable string!!
    strftime(timeString, 20, "%d-%m-%Y %T", &tmStruct);

    return timeString;
}

#elif __linux__

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

path_t getDataPath() {
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    return path_t(homedir).append(".config").append(APPDATA_DIRNAME);
}

std::string getTimestamp() {
    char buffer[80];

    std::time_t currentTime = std::time(nullptr);
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %T", std::localtime(&currentTime));

    return buffer;
}

#endif

float deltaTime() {  // bottleneck?
    return ImGui::GetIO().DeltaTime;
}