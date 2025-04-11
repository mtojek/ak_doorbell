#include "logger.hpp"

namespace log {

Level current_level = Level::INFO;

const char *level_to_string(Level level) {
  switch (level) {
  case Level::DEBUG:
    return "DEBUG";
  case Level::INFO:
    return "INFO";
  case Level::WARN:
    return "WARN";
  case Level::ERROR:
    return "ERROR";
  default:
    return "UNKNOWN";
  }
}

std::string timestamp() {
  std::time_t now = std::time(nullptr);
  std::tm tm{};
  localtime_r(&now, &tm);

  char buf[32];
  std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
  return std::string(buf);
}

void set_level(Level level) { current_level = level; }

void write(Level level, const std::string &tag, const std::string &message) {
  if (level < current_level)
    return;

  std::cout << "[" << timestamp() << "] "
            << "[" << level_to_string(level) << "] "
            << "[" << tag << "] " << message << std::endl;
}

void debug(const std::string &tag, const std::string &msg) {
  write(Level::DEBUG, tag, msg);
}

void info(const std::string &tag, const std::string &msg) {
  write(Level::INFO, tag, msg);
}

void warn(const std::string &tag, const std::string &msg) {
  write(Level::WARN, tag, msg);
}

void error(const std::string &tag, const std::string &msg) {
  write(Level::ERROR, tag, msg);
}

} // namespace log
