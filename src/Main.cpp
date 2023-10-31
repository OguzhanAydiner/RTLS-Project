#include "notation.h"
#include <app.h>
#include <frame.h>
#include <swTimer.h>
#include <network.h>

SwTimer_t g_twrTimer;

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

