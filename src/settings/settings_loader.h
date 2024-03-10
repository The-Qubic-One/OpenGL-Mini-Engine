#ifndef SETTINGS_SETTINGSLOADER_H_
#define SETTINGS_SETTINGSLOADER_H_

#include "settings/settings.h"

/// Provides a service for loading and saving Settings into text
class SettingsLoader {
 public:
  /// load settings from text
  static Settings loadFrom(const std::string& text);

  /// save settings into text
  static std::string saveInto(const Settings& settings);
};

#endif