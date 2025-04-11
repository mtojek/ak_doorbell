#include <unistd.h>

#include "spdlog/spdlog.h"

#include "lv_port/port_init.hpp"

#include "lv_examples/lv_examples.h"

int main() {
  spdlog::set_level(spdlog::level::debug);
  spdlog::info("LVGL initialized");

  lv_port_init();

  lv_demo_widgets();

  while (true) {
    lv_tick_inc(5);
    lv_task_handler();

    usleep(5000); // FIXME ak_sdk_init + ak_sleep_ms
  }

  return 0;
}
