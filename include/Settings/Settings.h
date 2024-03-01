#pragma once

#include <string>
#include <boost/property_tree/ptree.hpp>

#include "Core/types.h"

/*! @brief Stores a set of key-value pair settings.
* 
* IO independent, to load or save values to text, an external service has to be used.
* Settings are validated only that they  
*/
class Settings {
    tree_t data;

protected:
    //! @brief returns raw data for comparison and savings purposes
    const tree_t& getData() const;

    //! @brief overwrites raw data for file loading purposes
    void setData(const tree_t& data);

public:
    friend class SettingsLoader;

    //! @brief checks if settings stores any data
    bool empty() const;

    //! @brief checks if two settings sets are the same
    bool equals(const Settings& other) const;

    //! @brief overwrites all values into defaults
    void setDefaults();

    //! @brief sets a value associated to a key
    void set(const std::string& keyPath, const std::string& value);
    
    //! @brief gets a key's value
    std::string get(const std::string& keyPath) const;
};
