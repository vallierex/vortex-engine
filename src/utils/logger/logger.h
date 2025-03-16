#ifndef LOGGER_H
#define LOGGER_H

#include <string>

#include "console_logger.h"
#include "file_logger.h"
#include "log_message_formater.h"

class Logger final : public BaseLogger {
    std::unique_ptr<ConsoleLogger> console_logger_;
    std::unique_ptr<FileLogger> file_logger_;

public:
    explicit Logger(const std::string &log_file)
        : console_logger_(std::make_unique<ConsoleLogger>()),
          file_logger_(std::make_unique<FileLogger>(log_file)) {
    }

    void log(const std::string &message) override {
        const std::string formatted_message = LogMessageFormater::format_message(message);
        console_logger_->log(formatted_message);
        file_logger_->log(formatted_message);
    }

    void debug(const std::string &message) { log("DEBUG: " + message); }
    void info(const std::string &message) { log("INFO: " + message); }
    void warning(const std::string &message) { log("WARNING: " + message); }
    void error(const std::string &message) { log("ERROR: " + message); }
    void critical(const std::string &message) { log("CRITICAL: " + message); }
};

#endif // LOGGER_H
