<<<<<<< HEAD
#include "app.h"
#include "notation.h"
#include "memory.h"
#include "swTimer.h"
=======
#include "App.h"
#include "Notation.h"
#include "Memory.h"
#include "SwTimer.h"
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445

esp_now_peer_info_t     peerInfo;

MacAddress_t            g_macList[3];
TimeStamp_t             g_sendPacket;

volatile uint32_t timer_ms = 0;

<<<<<<< HEAD
=======
void timerTask(void *pvParameters);
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445

void setup()
{

  Serial.begin(115200);
 
  WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) 
    {
        Serial.println("Error initializing ESP-NOW");
        return;
    } 

    esp_now_register_send_cb(DataSentCallBack); 

    memcpy(peerInfo.peer_addr,(const U8 *) &g_devMemoryConfig.mac, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
  
    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
        Serial.println("Failed to add peer");
        return;
    }
    g_sendPacket.timeStamp = 112;
    g_sendPacket.retVal    = TRUE;

<<<<<<< HEAD
    SwTimerEnable(&TwrTimer,2000);
=======
  xTaskCreate(timerTask, "TimerTask", 2048, NULL, 5, NULL);  
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445
}


void loop()
{
<<<<<<< HEAD
    if(IsTimeout())

=======
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445
  
  

    MessageSendHandler(&g_sendPacket, &g_devMemoryConfig);

<<<<<<< HEAD
}


=======
    delay(300);
}

void timerTask(void *pvParameters) {

    while (1) {
        vTaskDelay(MS_TO_TICKS(1));  // Increment timer every 1 ms
        timer_ms++;
    }
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445
}


 
