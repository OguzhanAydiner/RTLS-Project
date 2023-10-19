#ifndef SWTIMER_H
#define SWTIMER_H

#include "Notation.h"
#include "freertos/timers.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define MS_TO_TICKS(ms) ((ms) / portTICK_PERIOD_MS)

void timerTask(void *pvParameters);

#endif