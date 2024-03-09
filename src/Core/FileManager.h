#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "types.h"

/// Stores data and context of a single texture
struct TextureData {
  int width, height, channels;
  unsigned char* data;

  /// free the bitmap
  void destroy();
};

/// Collection of io services for the filesystem
class FileManager {
 public:
  /// read text file
  static std::string readTextFile(const path_t& path);

  /// overwrite file with text
  static void writeTextFile(const path_t& path, const std::string& text);

  /// append text to a file
  static void appendTextFile(const path_t& path, const std::string& text);

  /// checks if directory exists
  static bool dirExists(const path_t& path);

  /// creates a directory
  static void createDir(const path_t& path);

  /// checks if a file exists
  static bool fileExists(const path_t& path);

  /// loads textures
  static TextureData loadTextureData(const char* filename);
};

#endif