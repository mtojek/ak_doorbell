#include "port_init.hpp"
#include "tick.hpp"

#include "display.hpp"
#include "input.hpp"

void lv_port_init() {
  spdlog::debug("Initialize LVGL port.");

  lv_init();

  lv_port_tick_init();
  lv_port_input_init();
  lv_port_disp_init();

  spdlog::debug("LVGL port initialized.");
}
