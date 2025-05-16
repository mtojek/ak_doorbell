// screen.hpp
#pragma once

#include <lvgl.h>

namespace ui {

class ScreenManager; // Forward declaration

class Screen {
public:
  virtual ~Screen() = default;

  void set_manager(ScreenManager *mgr) { manager = mgr; }

  virtual void on_create(lv_obj_t *parent) = 0;
  virtual void on_loop() = 0;
  virtual void on_destroy() {}

  virtual const char *get_name() = 0;

protected:
  ScreenManager *manager = nullptr;
};

} // namespace ui