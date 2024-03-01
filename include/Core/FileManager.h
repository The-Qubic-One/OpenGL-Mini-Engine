#pragma once

#include <string>
#include <filesystem>

#include "types.h"

//! @brief Stores data and context of a single texture
struct TextureData {
    int width, height, channels;
    unsigned char* data;

    //! @brief free the bitmap
    void destroy();
};

//! @brief Collection of io services for the filesystem
class FileManager {
public:

    //! @brief read text file
    static std::string readTextFile(const path_t& path);

    //! @brief overwrite file with text
    static void writeTextFile(const path_t& path, const std::string& text);

    //! @brief append text to a file
    static void appendTextFile(const path_t& path, const std::string& text);

    //! @brief checks if directory exists
    static bool dirExists(const path_t& path);

    //! @brief creates a directory
    static void createDir(const path_t& path);

    //! @brief checks if a file exists
    static bool fileExists(const path_t& path);

    //! @brief loads textures
    static TextureData loadTextureData(const char* filename);
};