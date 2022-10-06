#include "FileManager.h"
#include <fstream>
#include <stb_image/stb_image.h>
#include "util.h"

// Files

std::string FileManager::readTextFile(const path_t& path) const {
    std::string text, line;
    std::ifstream file(path);
    while (std::getline(file, line))
        text += line + '\n';
    return text;
}

void FileManager::writeTextFile(const path_t& path, const std::string& text) const {
    std::ofstream file(path, std::ios_base::trunc);
    file << text;
    file.close();
}

void FileManager::appendTextFile(const path_t& path, const std::string& text) const {
    std::ofstream file(path, std::ios_base::app);
    file << text;
    file.close();
}

// Ini Files

tree_t FileManager::readIniFile(const path_t& path) const {
    tree_t out;
    boost::property_tree::ini_parser::read_ini(path.string(), out);
    return out;
}

void FileManager::writeIniFile(const path_t& path, const tree_t& data) const {
    boost::property_tree::ini_parser::write_ini(path.string(), data);
}

// Directories

bool FileManager::dirExists(const path_t& path) const {
    return std::filesystem::exists(path);
}

void FileManager::createDir(const path_t& path) const {
    std::filesystem::create_directories(path);
}

// File Tests

bool FileManager::fileExists(const path_t& path) const {
    return std::filesystem::exists(path);
}

// Textures

unsigned char* FileManager::loadTexture(const char& filename, int width, int height, int channels) const {
    return stbi_load(&filename, &width, &height, &channels, 0);
}