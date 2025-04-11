#include "input.hpp"

void lv_port_input_init() {
  spdlog::debug("Initialize touch input.");

  evdev_init();

  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = evdev_read; // Use evdev for touch input
  lv_indev_drv_register(&indev_drv);

  spdlog::debug("Input initialized.");
}