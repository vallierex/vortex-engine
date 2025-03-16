#include "console_logger.h"

#include <iostream>

void ConsoleLogger::log(const std::string &message) {
#ifdef VE_DEBUG
    std::cout << message << '\n';
#endif
}
