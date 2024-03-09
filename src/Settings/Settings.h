#ifndef SETTINGS_H
#define SETTINGS_H

#include "Core/types.h"

/// @brief Stores a set of key-value pair settings.
///
/// IO independent, to load or save values to text, an external service has to
/// be used.
class Settings {
  tree_t data;

 protected:
  /// returns raw data for comparison and savings purposes
  const tree_t& getData() const;

  /// overwrites raw data for file loading purposes
  void setData(const tree_t& data);

 public:
  friend class SettingsLoader;

  /// checks if settings stores any data
  bool empty() const;

  /// checks if two settings sets are the same
  bool equals(const Settings& other) const;

  /// overwrites all values into defaults
  void setDefaults();

  /// sets a value associated to a key
  void set(const std::string& keyPath, const std::string& value);

  /// gets a key's value
  std::string get(const std::string& keyPath) const;
};

#endif