#pragma once

#include <string>

#include "Settings/Settings.h"

/// Provides a service for loading and saving Settings into text
class SettingsLoader {
 public:
  /// load settings from text
  static Settings loadFrom(const std::string& text);

  /// save settings into text
  static std::string saveInto(const Settings& settings);
};