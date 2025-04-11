#pragma once

#include <string>

class PWM {
public:
  PWM(int chip, int channel);

  bool export_if_needed();
  bool enable(bool on);
  bool set_period(int period_ns);
  bool set_duty(int duty_ns);
  bool set_duty_and_period(int duty_ns, int period_ns);

  bool is_exported() const;

private:
  std::string base_path() const;
  int chip_;
  int channel_;
};
