#include "app.h"


TimeStamp_t             g_sendPacket;
TimeStamp_t             g_receivedPacket;

volatile BOOL packetReceived = FALSE;

BOOL MessageSendHandler ( TimeStamp_t *dataPtr , MemoryConfig_t  *memPtr , DevType_t device)
{
  BOOL retVal = FALSE;

  esp_err_t result = esp_now_send((const uint8_t *)&memPtr[device].mac , (const uint8_t *)dataPtr, sizeof(TimeStamp_t));
  
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

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&g_receivedPacket, incomingData, sizeof(g_receivedPacket));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("TimeStamp: ");
  Serial.println(g_receivedPacket.timeStamp);
  Serial.print("Bool: ");
  Serial.println(g_receivedPacket.retVal);
  Serial.println();
  packetReceived = TRUE;
}



  
 

  
    
