#ifndef SWTIMER_H
#define SWTIMER_H

#include "notation.h"
#include "freertos/timers.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define MS_TO_TICKS(ms) ((ms) / portTICK_PERIOD_MS)

typedef struct
{
    TickType_t startTime;
    TickType_t timeout;
    TickType_t lastTime;
    BOOL enabled;
} SwTimer;

extern SwTimer g_twrTimer;

BOOL Timer(U8 Time, TickType_t *lastTime);
void SwTimerKill(SwTimer *timer);
void SwTimerEnable(SwTimer *timer, TickType_t timeout);
BOOL IsTimeout(SwTimer *timer);
void TimeSyncHandler();

#endif
