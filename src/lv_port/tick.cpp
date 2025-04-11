#include "tick.hpp"

static void *tick_thread(void *arg) {
  (void)arg;
  while (true) {
    usleep(5000);
    lv_tick_inc(5);
  }
  return nullptr;
}

void lv_port_tick_init() {
  pthread_t thread_id;
  pthread_create(&thread_id, nullptr, tick_thread, nullptr);
  pthread_detach(thread_id);
}
