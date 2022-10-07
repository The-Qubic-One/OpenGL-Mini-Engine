#pragma once
#include <string>
#include "types.h"
#include <filesystem>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

class FileManager {
public:

    // Text Files
    std::string readTextFile(const path_t& path) const;
    void writeTextFile(const path_t& path, const std::string& text) const;
    void appendTextFile(const path_t& path, const std::string& text) const;

    // Ini Files
    tree_t readIniFile(const path_t& path) const;
    void writeIniFile(const path_t& path, const tree_t& data) const;

    // Directories
    bool dirExists(const path_t& path) const;
    void createDir(const path_t& path) const;

    // File Tests
    bool fileExists(const path_t& path) const;

    // Textures
    unsigned char* loadTexture(const char& filename, int* width, int* height, int* channels) const;
};