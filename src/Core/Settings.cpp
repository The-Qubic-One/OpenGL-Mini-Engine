#include "Settings.h"
#include <iostream>

Settings::Settings() {
    reset();
}

void Settings::set(const std::string& key, const std::string& value) {
    
}

void Settings::setFromTree(const tree_t& data) {
    dataTree = data;
}

std::string Settings::get(const std::string& keyPath) const {
    return dataTree.get<std::string>(keyPath);
}

tree_t Settings::getTree() const {
    return dataTree;
}

/*  Default Settings:

    [general]
    version="0.0"

    [background]
    color="gray"

*/

std::string defaultVals[] = {
    "general.version", "1.0.0",
    "background.color", "gray"
};
int defaultValsNo = 2;

bool Settings::isComplete() const {
    try
    {
        for(int i = 0; i < defaultValsNo; i++)
            if (dataTree.get<std::string>(defaultVals[2*i])=="")
                return false;
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
}

void Settings::reset() {
    dataTree.clear();
    for(int i = 0; i < defaultValsNo; i++)
        dataTree.put(defaultVals[2*i], defaultVals[2*i+1]);
}