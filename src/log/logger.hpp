#pragma once

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <string.h>

namespace log {

enum class Level { DEBUG = 0, INFO, WARN, ERROR };

// Set the global log level
void set_level(Level level);

// Core logging function
void write(Level level, const std::string &tag, const std::string &message);

// Convenience helpers
void debug(const std::string &tag, const std::string &msg);
void info(const std::string &tag, const std::string &msg);
void warn(const std::string &tag, const std::string &msg);
void error(const std::string &tag, const std::string &msg);

} // namespace log
