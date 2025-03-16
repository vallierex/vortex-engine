#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H

#include "base_logger.h"


class ConsoleLogger : public BaseLogger {
public:
    void log(const std::string &message) override;
};


#endif //CONSOLE_LOGGER_H
