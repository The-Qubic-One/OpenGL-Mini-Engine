#include "Settings/SettingsLoader.h"

#include "Core/types.h"

Settings SettingsLoader::loadFrom(const std::string& text) {
  std::istringstream iss(text);
  tree_t pt;
  read_ini(iss, pt);

  Settings out = Settings();
  out.setData(pt);
  return out;
};

std::string SettingsLoader::saveInto(const Settings& settings) {
  std::ostringstream oss;
  write_ini(oss, settings.getData());
  return oss.str();
};