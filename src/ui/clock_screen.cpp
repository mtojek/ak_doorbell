#include "clock_screen.hpp"

namespace ui {

const char *ClockScreen::get_name() { return "Clock"; }

void ClockScreen::on_create(lv_obj_t *parent) {
  lv_obj_t *scr = parent;

  // Zegar
  lv_obj_t *labelTime = lv_label_create(scr, NULL);
  lv_label_set_text(labelTime, "12:34");
  lv_obj_align(labelTime, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);

  // Data
  lv_obj_t *labelDate = lv_label_create(scr, NULL);
  lv_label_set_text(labelDate, "Sobota, 3 Maja 2025");
  lv_obj_align(labelDate, NULL, LV_ALIGN_IN_TOP_MID, 0, 50);

  // Ikona wyciszenia (🔕)
  lv_obj_t *muteIcon = lv_label_create(scr, NULL);
  lv_label_set_text(muteIcon, "🔕");
  lv_obj_align(muteIcon, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10);

  // Przycisk "Podgląd kamery"
  lv_obj_t *btnCamera = lv_btn_create(scr, NULL);
  lv_obj_set_size(btnCamera, 80, 40);
  lv_obj_align(btnCamera, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 10, -10);
  lv_obj_t *labelCam = lv_label_create(btnCamera, NULL);
  lv_label_set_text(labelCam, "📷");

  // Przycisk "Nagrania"
  lv_obj_t *btnRecordings = lv_btn_create(scr, NULL);
  lv_obj_set_size(btnRecordings, 80, 40);
  lv_obj_align(btnRecordings, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -10);
  lv_obj_t *labelRec = lv_label_create(btnRecordings, NULL);
  lv_label_set_text(labelRec, "📁");

  // Przycisk "Otwórz drzwi"
  lv_obj_t *btnUnlock = lv_btn_create(scr, NULL);
  lv_obj_set_size(btnUnlock, 80, 40);
  lv_obj_align(btnUnlock, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -10, -10);
  lv_obj_t *labelUnlock = lv_label_create(btnUnlock, NULL);
  lv_label_set_text(labelUnlock, "🔓");

  // Przycisk "Serwis"
  lv_obj_t *btnService = lv_btn_create(scr, NULL);
  lv_obj_set_size(btnService, 50, 40);
  lv_obj_align(btnService, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
  lv_obj_t *labelService = lv_label_create(btnService, NULL);
  lv_label_set_text(labelService, "🛠");

  // Eventy
  /*lv_obj_set_event_cb(btnCamera, onCameraClicked);
  lv_obj_set_event_cb(btnRecordings, onRecordingsClicked);
  lv_obj_set_event_cb(btnUnlock, onUnlockClicked);
  lv_obj_set_event_cb(btnService, onServiceClicked);*/
}

void ClockScreen::on_loop() {}

void ClockScreen::on_destroy() {}

} // namespace ui