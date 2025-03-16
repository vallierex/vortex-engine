#ifndef LOG_MESSAGE_FORMATER_H
#define LOG_MESSAGE_FORMATER_H

#include <chrono>

class LogMessageFormater {
public:
    static std::string format_message(const std::string &message);
};


#endif //LOG_MESSAGE_FORMATER_H
