#include "ui.hpp"
#include "clock.hpp"

#include "lvgl.h"

namespace ui {

void welcome() {
  ClockScreen::create();

  lv_scr_load(ClockScreen::get());
}

} // namespace ui