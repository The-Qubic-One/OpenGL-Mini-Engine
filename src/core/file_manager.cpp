#include "core/file_manager.h"

// Files

std::string FileManager::readTextFile(const path_t& path) {
  std::string text, line;

  std::ifstream file(path);
  if (!file.is_open())
    throw std::runtime_error("Text resource not found: " + path.string());

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

TextureData FileManager::loadTextureData(const path_t& path) {
  stbi_set_flip_vertically_on_load(true);
  TextureData tex;
  int width, height, channels;

  if (!fileExists(path)) {
      std::stringstream ss;
      ss << "Texture resource not found: " << path;
      throw std::runtime_error(ss.str());
  }

  std::string path_str = path.string();
  tex.data = stbi_load(path_str.c_str(), &width, &height, &channels, 0);

  if (!tex.data)
    throw std::runtime_error("Unable to load texture: " + path.string());

  tex.width = width;
  tex.height = height;
  tex.channels = channels;
  return tex;
}

void TextureData::destroy() {
  stbi_image_free(data);
}