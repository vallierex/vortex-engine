#include "file_logger.h"

FileLogger::FileLogger(const std::string &log_file) {
    file_stream_.open(log_file, std::ios::out | std::ios::app);
}

FileLogger::~FileLogger() {
    if (file_stream_.is_open()) {
        file_stream_.close();
    }
}

void FileLogger::log(const std::string &message) {
    std::scoped_lock lock_guard(mutex_);
    if (file_stream_.is_open()) {
        file_stream_ << message << '\n';
    }
}
