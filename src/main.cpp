#include <atomic>
#include <csignal>
#include <unistd.h>

#include "hw/display.hpp"
#include "log/logger.hpp"
#include "lv_port/port_init.hpp"

#include "lv_examples/lv_examples.h"
#include "ui/ui.hpp"

std::atomic<bool> app_running(true);

void on_signal(int signal) {
  log::warn("main|on_signal", "Received signal: " + std::to_string(signal));
  app_running = false;
}

int main() {
  log::set_level(log::Level::DEBUG);
  log::info("main", "Start application");

  lv_port_init();
  // lv_demo_widgets();
  ui::init();

  display::init();
  std::signal(SIGINT, on_signal);
  std::signal(SIGTERM, on_signal);
  display::enable(true);

  while (app_running) {
    ui::loop();
    lv_task_handler();

    lv_tick_inc(5);
    usleep(5000); // FIXME ak_sdk_init + ak_sleep_ms
  }

  log::info("main", "Shutting down...");
  display::enable(false);

  return 0;
}
