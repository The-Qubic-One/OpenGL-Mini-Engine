#pragma once
#include <string>

/// @brief Engine main logger
///
/// Fully IO independent, used only to store logs until they are pulled.
class Logger {
  std::string logText;

 public:
  /// returns all stored logs and clears them, should be used to store
  /// the logs on disk in critical moments
  std::string pullLogs();

  /// checks if there are any logs stored
  bool empty() const;

  /// saves a message into logs and prints it in the console
  void log(const std::string& message);
};