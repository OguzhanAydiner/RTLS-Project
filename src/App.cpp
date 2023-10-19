#include"App.h"




BOOL MessageSendHandler ( TimeStamp_t *dataPtr , MemoryConfig_t *memPtr)
{
  BOOL retVal = FALSE;

  esp_err_t result = esp_now_send((const uint8_t *)&(memPtr->mac) , (const uint8_t *)dataPtr, sizeof(TimeStamp_t));
  
  if (result == ESP_OK) 
  {
        Serial.println("Sent with success");
        retVal = TRUE;
  }
  else 
  { 
        Serial.println("Error sending the data");
        retVal = FALSE;
  }

  return retVal;
}


void DataSentCallBack(const uint8_t * mac_addr, esp_now_send_status_t status) 
{
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}





  
 

  
    
