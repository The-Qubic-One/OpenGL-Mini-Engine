#include <glad/glad.h>
#include "util.h"
#include <chrono>
#include <shlobj_core.h>

std::string getTimeAndDate() {
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

path_t getAppDataPath() {
    wchar_t* path;
    SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &path);
    return path_t(path);
}