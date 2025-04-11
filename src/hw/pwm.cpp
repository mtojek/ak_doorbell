#include "pwm.hpp"

#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <unistd.h>

bool write_to_file(const std::string &path, const std::string &value) {
  std::ofstream fs(path);
  if (!fs.is_open())
    return false;
  fs << value;
  return fs.good();
}

bool file_exists(const std::string &path) {
  struct stat st;
  return stat(path.c_str(), &st) == 0;
}

PWM::PWM(int chip, int channel) : chip_(chip), channel_(channel) {}

std::string PWM::base_path() const {
  std::ostringstream oss;
  oss << "/sys/class/pwm/pwmchip" << chip_ << "/pwm" << channel_;
  return oss.str();
}

bool PWM::is_exported() const { return file_exists(base_path()); }

bool PWM::export_if_needed() {
  if (is_exported())
    return true;
  std::ostringstream path;
  path << "/sys/class/pwm/pwmchip" << chip_ << "/export";
  return write_to_file(path.str(), std::to_string(channel_));
}

bool PWM::enable(bool on) {
  return write_to_file(base_path() + "/enable", on ? "1" : "0");
}

bool PWM::set_period(int period_ns) {
  return write_to_file(base_path() + "/period", std::to_string(period_ns));
}

bool PWM::set_duty(int duty_ns) {
  return write_to_file(base_path() + "/duty_cycle", std::to_string(duty_ns));
}

bool PWM::set_duty_and_period(int duty_ns, int period_ns) {
  return set_period(period_ns) && set_duty(duty_ns);
}
