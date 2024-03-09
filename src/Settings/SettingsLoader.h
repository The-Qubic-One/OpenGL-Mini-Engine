#ifndef SETTINGS_LOADER_H
#define SETTINGS_LOADER_H

#include "Settings/Settings.h"

/// Provides a service for loading and saving Settings into text
class SettingsLoader {
 public:
  /// load settings from text
  static Settings loadFrom(const std::string& text);

  /// save settings into text
  static std::string saveInto(const Settings& settings);
};

#endif