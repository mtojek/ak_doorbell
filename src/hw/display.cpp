#include "display.hpp"
#include "pwm.hpp"

constexpr int kPwmChip = 2;
constexpr int kPwmChannel = 0;
constexpr int kPwmPeriod = 65536;
constexpr int kPwmDuty = 65536;

namespace display {

static hw::PWM pwm_display(kPwmChip, kPwmChannel);

bool init() {
  if (!pwm_display.export_if_needed()) {
    return false;
  }
  return pwm_display.set_duty_and_period(kPwmDuty, kPwmPeriod);
}

bool enable(bool on) { return pwm_display.enable(on); }

} // namespace display
