#include "swTimer.h"

SwTimer_t TwrTimer;

BOOL IsTimeout(SwTimer_t *timer) {

    BOOL retVal = FALSE;
    const TickType_t currentTime = xTaskGetTickCount();
    const TickType_t timeDifference = currentTime - (timer->lastTime);
    
    if ( timer->enabled && timeDifference >= pdMS_TO_TICKS(timer->timeout)) {
        timer->lastTime = currentTime;
        retVal = TRUE;
    }

    return retVal;
}

void SwTimerKill(SwTimer_t *timer) {
    timer->enabled = FALSE;
}

void SwTimerEnable(SwTimer_t *timer, TickType_t timeout) {
    timer->startTime  = xTaskGetTickCount();
    timer->timeout    = timeout;
    timer->lastTime   = timer->startTime;
    timer->enabled    = TRUE;
}
