#include "app.h"
#include "notation.h"
#include "memory.h"
#include "swTimer.h"
#include "network.h"








void setup()
{

     Serial.begin(115200);
     WiFi.mode(WIFI_STA);
     Esp32NowInit();
     MemoryInit();
     SwTimerEnable(&g_twrTimer, 2000);
     NTPInit();

}


void loop()
{
    TimeSyncHandler(); 

}



 
