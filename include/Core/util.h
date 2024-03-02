#pragma once

#include <filesystem>
#include <string>

#include "Core/types.h"

//! provides universal access to path related utilities
//! @todo implement getProgramPath() for Windows
class Path {
public:
    //! transforms a relative path in app data directory to an absolute path
    static path_t inDataDir(path_t path);
    //! returns absolute path of the application data directory (%APPDATA% on Windows, ~/.config on Linux)
    static path_t getDataPath();
    
    //! transforms a relative path in program directory to an absolute path
    static path_t inProgramDir(path_t path);
    //! returns absolute path of the binary's parent dir
    static path_t getProgramPath();
};

//! provides universal access to time related utilities
class Time {
public:
    //! returns current time and date in string format "DD-MM-YY HH:MM:SS"
    static std::string getTimestamp();
    static float deltaTime();
};