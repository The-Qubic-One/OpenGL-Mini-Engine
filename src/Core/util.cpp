#include "Core/util.h"

#include <glad/glad.h>

#include "ImGui/imgui.h"

std::tuple<int, int, int> HexColor::values(const std::string& hex) {
  std::istringstream iss(
      hex.substr(hex[0] == '#'));  // Ignore the '#' character
  int colorValue;
  iss >> std::hex >> colorValue;

  return std::make_tuple((colorValue >> 16) & 0xFF, (colorValue >> 8) & 0xFF,
                         colorValue & 0xFF);
}

std::string HexColor::toStr(const int& r, const int& g, const int& b) {
  int red = std::min(std::max(r, 0), 255);
  int green = std::min(std::max(g, 0), 255);
  int blue = std::min(std::max(b, 0), 255);

  std::stringstream ss;
  ss << "#" << std::hex << std::setw(2) << std::setfill('0') << red
     << std::setw(2) << green << std::setw(2) << blue;

  return ss.str();
}

#ifdef _WIN32

#include <shlobj_core.h>

#include <chrono>

path_t Path::getDataPath() {
  wchar_t* path;
  SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &path);
  return path_t(path).append(APPDATA_DIRNAME);
}

std::string Time::getTimestamp() {
  auto time =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
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

#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

path_t Path::getDataPath() {
  struct passwd* pw = getpwuid(getuid());
  const char* homedir = pw->pw_dir;
  return path_t(homedir).append(".config").append(APPDATA_DIRNAME);
}

path_t Path::getProgramPath() {
  path_t aaa = std::filesystem::canonical("/proc/self/exe");
  return aaa.parent_path();
}

std::string Time::getTimestamp() {
  char buffer[80];

  std::time_t currentTime = std::time(nullptr);
  std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %T",
                std::localtime(&currentTime));

  return buffer;
}

#endif

float Time::deltaTime() {  // bottleneck?
  return ImGui::GetIO().DeltaTime;
}