#pragma once

#include <lvgl.h>

#include "screen.hpp"

namespace ui {

class ClockScreen : public Screen {
private:
  lv_obj_t *labelTime;

public:
  void on_create(lv_obj_t *parent) override;
  void on_loop() override;
  void on_destroy() override;

  const char *get_name() override;
};

} // namespace ui