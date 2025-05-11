#pragma once

#include "lvgl.h"

class ClockScreen {
public:
  static void create();
  static lv_obj_t *get();

private:
  static lv_obj_t *screen;

  static lv_obj_t *labelTime;
  static lv_obj_t *labelDate;
  static lv_obj_t *btnCamera;
  static lv_obj_t *btnRecordings;
  static lv_obj_t *btnUnlock;
  static lv_obj_t *btnService;
  static lv_obj_t *muteIcon;
};