#include "Core/Logger.h"
#include "Core/util.h"
#include <iostream>

std::string Logger::pullLogs() {
    std::string out = '\t' + getTimestamp();
    out.push_back('\n');
    out.insert(out.end(), logText.begin(), logText.end());
    out.push_back('\n');

    logText.clear();
    return out;
}

bool Logger::empty() const {
    return logText.empty();
}

void Logger::log(const std::string& message) {
    const char* white = " \n\t";
    logText.insert(logText.end(), message.begin() + message.find_first_not_of(white), message.begin() + message.find_last_not_of(white) + 1);
    logText.push_back('\n');
}