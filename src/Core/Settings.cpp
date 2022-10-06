#include "Settings.h"

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

/*
    [general]
    version="0.0"

    [background]
    color="gray"
*/

void Settings::reset() {
    dataTree.clear();

    dataTree.put("general.version", "0.0");
    dataTree.put("general.version", "gray");
}