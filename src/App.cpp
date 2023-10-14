#include"App.h"



/*
BOOL TimeStampHandler ( struct_message myData)
{
    BOOL retVal = TRUE;  

    esp_err_t result = esp_now_send((uint8_t *)&g_devMemoryConfig.mac, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) 
  {
        Serial.println("Sent with success");
  }
  else 
  {
        Serial.println("Error sending the data");
  }

    return retVal;
}
*/

void DataSentCallBack(const uint8_t * mac_addr, esp_now_send_status_t status) 
{
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}





  
 

  
    
