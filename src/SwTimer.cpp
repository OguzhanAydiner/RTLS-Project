<<<<<<< HEAD
#include "swTimer.h"

SwTimer TwrTimer;

BOOL IsTimeout(SwTimer *timer,TickType_t *lastTime) {

    const TickType_t currentTime = xTaskGetTickCount();
    const TickType_t timeDifference = currentTime - (*lastTime);

    if (timeDifference >= pdMS_TO_TICKS(Time)) {
        *lastTime = currentTime; // Update the last time
        return true;
    } 
    else {
        return false;
    }
}

void SwTimerKill(SwTimer *timer) {
    timer->enabled = FALSE;
}

void SwTimerEnable(SwTimer *timer, TickType_t timeout) {
    timer->startTime  = xTaskGetTickCount();
    timer->timeout    = timeout;
    timer->enabled    = TRUE;
}







=======
#include "SwTimer.h"



/*
void timerTask(void *pvParameters) {

    while (1) {
        vTaskDelay(MS_TO_TICKS(1));  // Increment timer every 1 ms
        timer_ms++;
    }
}
*/

void TimerHandler()
{




}
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445
