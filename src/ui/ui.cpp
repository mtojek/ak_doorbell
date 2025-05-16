#include "ui.hpp"

#include "clock_screen.hpp"
#include "screen_manager.hpp"

#include "log/logger.hpp"

namespace ui {

ScreenManager manager;

void init() {
  log::debug("ui", "Initialize the UI.");
  ClockScreen *clockScreen = new ClockScreen();
  manager.navigate_to(clockScreen);
}

void loop() { manager.loop(); }

} // namespace ui
