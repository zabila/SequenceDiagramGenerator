#pragma once

#include "LogEntry.h"

#include <deque>
#include <string>

class ILogReadingStrategy
{
public:
    virtual ~ILogReadingStrategy() = default;
    virtual std::deque<LogEntry> readLogs(const std::string &filePath) = 0;
};