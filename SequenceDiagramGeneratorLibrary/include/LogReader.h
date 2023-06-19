#pragma once

#include "ILogReadingStrategy.h"
#include "LogEntry.h"

#include <memory>
#include <string>

class LogReader
{
public:
    explicit LogReader(std::unique_ptr<ILogReadingStrategy> strategy);

    void readLogs(const std::string &filePath);
    LogEntry getNextLine();
    bool hasMoreLines() const;

private:
    std::unique_ptr<ILogReadingStrategy> readingStrategy;
    std::deque<LogEntry> logEntries;
};