#pragma once
#include <string>

class Logger {
    std::string logText;

public:
    std::string pullLogs();
    bool empty() const;

    void log(const std::string& message);
};