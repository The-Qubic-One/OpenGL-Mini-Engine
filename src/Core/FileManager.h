#pragma once
#include <string>
#include "types.h"
#include <filesystem>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

struct TextureData {
    int width, height, channels;
    const unsigned char* data;

    ~TextureData();
};

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
    TextureData loadTextureData(const char& filename) const;
};