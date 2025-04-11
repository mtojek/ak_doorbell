#include <unistd.h>

#include "log/logger.hpp"
#include "lv_examples/lv_examples.h"
#include "lv_port/port_init.hpp"

int main() {
  log::set_level(log::Level::DEBUG);
  log::info("main", "Start application");

  lv_port_init();

  lv_demo_widgets();

  while (true) {
    lv_tick_inc(5);
    lv_task_handler();

    usleep(5000); // FIXME ak_sdk_init + ak_sleep_ms
  }

  return 0;
}
