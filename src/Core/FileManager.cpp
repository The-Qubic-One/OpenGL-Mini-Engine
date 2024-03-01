#include "Core/FileManager.h"
#include <fstream>
#include <stb_image/stb_image.h>
#include "Core/util.h"
#include <stdexcept>
#include <string>

// Files

std::string FileManager::readTextFile(const path_t& path) {
    std::string text, line;
    std::ifstream file(path);
    while (std::getline(file, line))
        text += line + '\n';
    return text;
}

void FileManager::writeTextFile(const path_t& path, const std::string& text) {
    std::ofstream file(path, std::ios_base::trunc);
    file << text;
    file.close();
}

void FileManager::appendTextFile(const path_t& path, const std::string& text) {
    std::ofstream file(path, std::ios_base::app);
    file << text;
    file.close();
}

// Directories

bool FileManager::dirExists(const path_t& path) {
    return std::filesystem::exists(path);
}

void FileManager::createDir(const path_t& path) {
    std::filesystem::create_directories(path);
}

// File Tests

bool FileManager::fileExists(const path_t& path) {
    return std::filesystem::exists(path);
}

// Textures

TextureData FileManager::loadTextureData(const char* filename) {
    stbi_set_flip_vertically_on_load(true);
    TextureData tex;
    int width, height, channels;
    tex.data = stbi_load(filename, &width, &height, &channels, 0);

    if (!tex.data)
        throw std::runtime_error("Unable to load texture: " + std::string(filename));

    tex.width = width;
    tex.height = height;
    tex.channels = channels;
    return tex;
}

void TextureData::destroy() {
    stbi_image_free(data);
}