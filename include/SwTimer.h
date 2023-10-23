#ifndef SWTIMER_H
#define SWTIMER_H

<<<<<<< HEAD
#include "notation.h"
=======
#include "Notation.h"
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445
#include "freertos/timers.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define MS_TO_TICKS(ms) ((ms) / portTICK_PERIOD_MS)
<<<<<<< HEAD

    typedef struct {
        TickType_t      startTime;
        TickType_t      timeout;
        BOOL            enabled;
    } SwTimer;



 extern SwTimer TwrTimer;

=======
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445

void timerTask(void *pvParameters);

<<<<<<< HEAD
BOOL Timer(U8 Time, TickType_t *lastTime);
void SwTimerKill(SwTimer *timer);
void SwTimerEnable(SwTimer *timer, TickType_t timeout);

#endif 
=======
#endif
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445
