#include <TextLogReadingStrategy.h>

#include <sstream>
#include <stdexcept>

std::deque<LogEntry> TextLogReadingStrategy::readLogs(const std::string &filePath)
{
    logFile.open(filePath);
    if (!logFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::deque<LogEntry> logEntries;
    std::string line;
    while (std::getline(logFile, line)) {
        LogEntry logEntry = parseLine(line);
        logEntries.push_back(std::move(logEntry));
    }

    logFile.close();
    return logEntries;
}

LogEntry TextLogReadingStrategy::parseLine(const std::string &line)
{
    std::istringstream lineStream(line);
    std::string timestamp;
    std::string threadId;
    std::string logLevel;
    std::string logMessage;
    lineStream >> timestamp >> threadId >> logLevel;
    std::getline(lineStream, logMessage);
    return {timestamp, threadId, logLevel, logMessage};
}