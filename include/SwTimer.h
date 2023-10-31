#ifndef SWTIMER_H
#define SWTIMER_H

#include "notation.h"


#define MS_TO_TICKS(ms) ((ms) / portTICK_PERIOD_MS)





extern SwTimer_t TwrTimer;



BOOL Timer(U8 Time, TickType_t *lastTime);
void SwTimerKill(SwTimer_t *timer);
void SwTimerEnable(SwTimer_t *timer, TickType_t timeout);
BOOL IsTimeout(SwTimer_t *timer);




#endif 
