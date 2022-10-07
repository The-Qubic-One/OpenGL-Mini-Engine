#pragma once
#include "types.h"
#include <string>
#include <boost/property_tree/ptree.hpp>

class Settings {
    tree_t dataTree;

public:
    Settings();

    void set(const std::string& key, const std::string& value);
    void setFromTree(const tree_t& data);

    std::string get(const std::string& keyPath) const;
    tree_t getTree() const;

    bool isComplete() const;
    void reset();
};