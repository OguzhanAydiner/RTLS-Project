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







