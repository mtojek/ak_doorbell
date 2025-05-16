#include <lvgl.h>

#include "log/logger.hpp"
#include "screen_manager.hpp"

namespace ui {

void ScreenManager::navigate_to(Screen *screen) {
  log::debug("screen_manager",
             std::string("Navigate to ") + screen->get_name() + " screen");

  if (current) {
    log::debug("screen_manager",
               std::string("Destroy ") + screen->get_name() + " screen");

    current->on_destroy();
    delete current;
    current = nullptr;
  }

  if (root) {
    lv_obj_clean(root);
  } else {
    root = lv_scr_act();
  }

  current = screen;

  log::debug("screen_manager",
             std::string("Create screen ") + screen->get_name());
  current->on_create(root);
}

void ScreenManager::loop() {
  if (current) {
    current->on_loop();
  }
}

} // namespace ui