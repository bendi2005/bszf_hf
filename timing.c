#include "timing.h"
#include "sl_sleeptimer.h"
#include "em_emu.h"
#include <stddef.h>

static sl_sleeptimer_timer_handle_t timer;
static volatile bool tick_flag = false;

static void timer_callback(sl_sleeptimer_timer_handle_t *handle, void *data)
{
  (void)handle; 
  (void)data;
  tick_flag = true;
  return;
}

void Timing_InitTiming(void)
{
  sl_sleeptimer_init();
  tick_flag = false;
  return;
}

void Timing_StartPeriodicMs(uint32_t period_ms)
{
  tick_flag = false;
  sl_sleeptimer_start_periodic_timer_ms(&timer, period_ms, timer_callback, NULL, 0, 0);
  return;
}

bool Timing_ConsumeTick(void)
{
  if (!tick_flag) {
    return false;
  }
  tick_flag = false;
  return true;
}

void Timing_SleepEM1(void)
{
  EMU_EnterEM1();
  return;
}

void Timing_Delay(uint32_t ms)
{
  tick_flag = false;
  sl_sleeptimer_start_timer_ms(&timer, ms, timer_callback, NULL, 0, 0);

  while (!tick_flag) {
    EMU_EnterEM1();
  }
}
