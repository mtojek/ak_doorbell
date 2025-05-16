#pragma once

#include <lvgl.h>

#include "screen.hpp"

namespace ui {

class ScreenManager {
public:
  void navigate_to(Screen *screen);
  void loop();

private:
  Screen *current = nullptr;
  lv_obj_t *root = nullptr;
};

} // namespace ui