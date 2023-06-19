#pragma once

#include <string>

struct LogEntry
{
    std::string timestamp;
    std::string level;
    std::string message;
    std::string component;
    std::string podName;
};