#include "App.h"
#include "Notation.h"
#include "Memory.h"

esp_now_peer_info_t     peerInfo;
MemoryConfig_t          g_devMemoryConfig;
MacAddress_t            g_macList[3];
TimeStamp_t             Data;


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
    memcpy(peerInfo.peer_addr,(const U8* ) &g_devMemoryConfig.mac, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
  
    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
        Serial.println("Failed to add peer");
        return;
    }
    Data.retVal = 111222333444;
    Data.retVal = TRUE;
}


void loop()
{

  esp_err_t result = esp_now_send((uint8_t *)&g_devMemoryConfig.mac, (uint8_t *) &Data, sizeof(Data));
   
  if (result == ESP_OK) 
  {
        Serial.println("Sent with success");
  }
  else 
  {
        Serial.println("Error sending the data");
  }
    delay(1000);

}



 
