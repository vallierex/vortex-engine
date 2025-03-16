#ifndef BASE_LOGGER_H
#define BASE_LOGGER_H

#include <string>

class BaseLogger {
public:
    virtual ~BaseLogger() = default;

    virtual void log(const std::string &message) = 0;
};


#endif //BASE_LOGGER_H
