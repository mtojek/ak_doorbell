#include "port_init.hpp"
#include "tick.hpp"

#include "display.hpp"
#include "input.hpp"

void lv_port_init() {
  log::debug("lv_port_init", "Initialize LVGL port.");

  lv_init();

  lv_port_disp_init();
  lv_port_input_init();
  lv_port_tick_init();

  log::debug("lv_port_init", "LVGL port initialized.");
}
