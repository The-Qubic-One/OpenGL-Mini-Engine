#include "core/util.h"

std::tuple<int, int, int> HexColor::values(const std::string& hex) {
  std::istringstream iss(
      hex.substr(hex[0] == '#'));  // Ignore the '#' character
  int color_value;
  iss >> std::hex >> color_value;

  return std::make_tuple((color_value >> 16) & 0xFF, (color_value >> 8) & 0xFF,
                         color_value & 0xFF);
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

path_t Path::getDataPath() {
  struct passwd* pw = getpwuid(getuid());
  const char* home_dir = pw->pw_dir;
  return path_t(home_dir).append(".config").append(APPDATA_DIRNAME);
}

path_t Path::getProgramPath() {
  return std::filesystem::canonical("/proc/self/exe").parent_path();
}

std::string Time::getTimestamp() {
  char buffer[80];

  std::time_t current_time = std::time(nullptr);
  std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %T",
                std::localtime(&current_time));

  return buffer;
}

#endif

float Time::deltaTime() {  // bottleneck?
  return ImGui::GetIO().DeltaTime;
}