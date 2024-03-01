#pragma once

#include <string>
#include "Settings/Settings.h"

/*! @brief Provides a service for loading and saving Settings into text
*/
class SettingsLoader {
public:
    //! @brief load settings from text
    static Settings loadFrom(const std::string& text);

    //! @brief save settings into text
    static std::string saveInto(const Settings& settings);
};