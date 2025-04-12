#pragma once

#include "log/logger.hpp"

#include "lvgl/lvgl.h"

#include "lv_drivers/display/fbdev.h"

#define DISP_BUF_SIZE (LV_HOR_RES_MAX * 4 * LV_VER_RES_MAX)
static lv_disp_buf_t disp_buf;
static lv_color_t buf1[DISP_BUF_SIZE];

void lv_port_disp_init();
