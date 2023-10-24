#include "app.h"
#include "notation.h"
#include "memory.h"
#include "swTimer.h"
#include "freertos/queue.h"

esp_now_peer_info_t     peerInfo;

MacAddress_t            g_macList[3];


QueueHandle_t packetQueue;
QueueHandle_t responseQueue;
void transmitterTask(void *pvParameters);
void receiverTask(void *pvParameters);


void setup()
{

  Serial.begin(115200);
 
  WiFi.mode(WIFI_STA);

  MemoryInit();

  if (esp_now_init() != ESP_OK)
  {
      Serial.println("Error initializing ESP-NOW");
      return;
    } 



    memcpy(peerInfo.peer_addr,(const U8 *) &g_devMemoryConfig[TAG_DEVICE].mac, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
  
    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
        Serial.println("Failed to add peer");
        return;
    }
    g_sendPacket.timeStamp = 2222;
    g_sendPacket.retVal    = TRUE;

    SwTimerEnable(&TwrTimer,2000);

    esp_now_register_send_cb(DataSentCallBack); 
    esp_now_register_recv_cb(OnDataRecv);

    packetQueue = xQueueCreate(10, sizeof(TimeStamp_t));
    responseQueue = xQueueCreate(10, sizeof(TimeStamp_t));
    //xTaskCreate(transmitterTask, "TransmitterTask", 2048, NULL, 5, NULL);
   // xTaskCreate(receiverTask, "ReceiverTask", 2048, NULL, 5, NULL);
}


void loop()
{

    

    


}



void transmitterTask(void *pvParameters) {
    while (1) {
        // Create a packet
        TimeStamp_t packet;
        packet.timeStamp = 42;

        // Send the packet to the message queue
        xQueueSend(packetQueue, &packet, portMAX_DELAY);

        // Wait for a response
        TimeStamp_t response;
        if (xQueueReceive(responseQueue, &response, pdMS_TO_TICKS(1000))) {
            // Process the response
            Serial.printf("Received Response: %d\n", response.timeStamp);
        }

        vTaskDelay(pdMS_TO_TICKS(100)); // Send the next packet after 100 ms
    }
}

void receiverTask(void *pvParameters) {
    while (1) {
        // Receive packets from the message queue
        TimeStamp_t receivedPacket;
        if (xQueueReceive(packetQueue, &receivedPacket, pdMS_TO_TICKS(100))) {
            // Process the received packet
            printf("Received Packet: %d\n", receivedPacket.timeStamp);
            
            // Send a response
            TimeStamp_t response;
            response.timeStamp = 99;
            xQueueSend(responseQueue, &response, portMAX_DELAY);
        }
    }
}

 
