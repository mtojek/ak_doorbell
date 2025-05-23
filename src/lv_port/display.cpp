#include "display.hpp"

void lv_port_disp_init() {
  log::debug("lv_port_disp_init", "Initialize display.");

  log::debug("lv_port_disp_init", "Call ak_tde_open()");
  int r = ak_tde_open();
  if (r != ERROR_TYPE_NO_ERROR) {
    log::error("lv_port_disp_init", "ak_tde_open failed with code: " + r);
    return;
  }

  log::debug("lv_port_disp_init", "Call fbdev_init()");
  fbdev_init();

  lv_disp_buf_init(&disp_buf, buf1, nullptr, DISP_BUF_SIZE);
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.buffer = &disp_buf;
  disp_drv.flush_cb = fbdev_flush;
  lv_disp_drv_register(&disp_drv);

  log::debug("lv_port_disp_init", "Display initialized.");
}
