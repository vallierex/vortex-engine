#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include <fstream>
#include <mutex>

#include "base_logger.h"


class FileLogger : public BaseLogger {
    std::ofstream file_stream_;
    std::mutex mutex_;

public:
    explicit FileLogger(const std::string &log_file);

    ~FileLogger() override;

    void log(const std::string &message) override;
};


#endif //FILE_LOGGER_H
