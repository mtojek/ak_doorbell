#pragma once

namespace display {

bool init();          // setup PWM (duty + period)
bool enable(bool on); // turn display backlight on/off

} // namespace display