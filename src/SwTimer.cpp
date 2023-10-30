#include "swTimer.h"
#include "network.h"

SwTimer g_twrTimer;

BOOL IsTimeout(SwTimer *timer)
{

    const TickType_t currentTime = xTaskGetTickCount();
    const TickType_t timeDifference = currentTime - (timer->lastTime);

    if (timeDifference >= pdMS_TO_TICKS(timer->timeout))
    {
        timer->lastTime = currentTime; // Update the last time
        return true;
    }
    else
    {
        return false;
    }
}

void SwTimerKill(SwTimer *timer)
{
    timer->enabled = FALSE;
}

void SwTimerEnable(SwTimer *timer, TickType_t timeout)
{
    timer->startTime = xTaskGetTickCount();
    timer->timeout = timeout;
    timer->lastTime = timer->startTime;
    timer->enabled = TRUE;
}



void TimeSyncHandler()
{
    static unsigned long lastTimeSync = 0;
    const long interval = 5000; // Interval for time sync (60 seconds)

    if (millis() - lastTimeSync > interval)
    {
        lastTimeSync = millis();
        SyncTime();
    }
}