#include "Settings/Settings.h"
#include <iostream>

const tree_t& Settings::getData() const {
    return data;
};

void Settings::setData(const tree_t& data) {
    this->data = data;
}

bool Settings::empty() const {
    return data.empty();
};

bool compare_ptrees(const tree_t& pt1, const tree_t& pt2) {
    if (pt1.size() != pt2.size())
        return false;

    for (const auto& p1 : pt1) {
        const auto& key = p1.first;
        const auto& value1 = p1.second;
        
        const auto& value2 = pt2.get_child_optional(key);
        if (!value2)
            return false;

        if (value1.data() != value2->data())
            return false;

        if (!compare_ptrees(value1, *value2))
            return false;
    }

    return true;
}

bool Settings::equals(const Settings& other) const {
    tree_t otherData = other.getData();
    return compare_ptrees(data, otherData);
};

/*  Default Settings:

    [general]
    version="0.0"

    [background]
    color="#334D4D"

*/

std::string defaultVals[] = {
    "general.version", "1.0.0",
    "background.color", "#334D4D"
};

int defaultValsNo = 2;

void Settings::setDefaults() {
    data.clear();
    for(int i = 0; i < defaultValsNo; i++)
        data.put(defaultVals[2*i], defaultVals[2*i+1]);
};

void Settings::set(const std::string& keyPath, const std::string& value) {
    data.put(keyPath, value);
};

std::string Settings::get(const std::string& keyPath) const {
    return data.get<std::string>(keyPath);
};
