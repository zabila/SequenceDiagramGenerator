#pragma once

#include "ILogReadingStrategy.h"
#include "LogEntry.h"

#include <fstream>

class TextLogReadingStrategy : public ILogReadingStrategy
{
public:
    std::deque<LogEntry> readLogs(const std::string &filePath) override;

private:
    LogEntry parseLine(const std::string &line);

    std::ifstream logFile;
};