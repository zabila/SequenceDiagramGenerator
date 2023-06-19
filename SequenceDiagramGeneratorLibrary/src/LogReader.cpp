#include "LogReader.h"

LogReader::LogReader(std::unique_ptr<ILogReadingStrategy> strategy)
    : readingStrategy(std::move(strategy))
{}

void LogReader::readLogs(const std::string &filePath)
{
    logEntries = readingStrategy->readLogs(filePath);
}

LogEntry LogReader::getNextLine()
{
    if (logEntries.empty()) {
        return {};
    }

    LogEntry nextLine = std::move(logEntries.front());
    logEntries.pop_front();
    return nextLine;
}

bool LogReader::hasMoreLines() const
{
    return !logEntries.empty();
}
