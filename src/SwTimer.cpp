#include "swTimer.h"

SwTimer TwrTimer;

BOOL IsTimeout(SwTimer *timer) {

    const TickType_t currentTime = xTaskGetTickCount();
    const TickType_t timeDifference = currentTime - (timer->lastTime);

    if (timeDifference >= pdMS_TO_TICKS(timer->timeout)) {
        timer->lastTime = currentTime; // Update the last time
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
    timer->lastTime = timer->startTime;
    timer->enabled    = TRUE;
}







