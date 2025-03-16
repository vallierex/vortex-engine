#include "log_message_formater.h"

std::string LogMessageFormater::format_message(const std::string &message) {
    const auto now = std::chrono::system_clock::now();
    const auto time = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
    localtime_s(&tm, &time);

    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << ' ' << message;
    return ss.str();
}
