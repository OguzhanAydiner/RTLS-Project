#include "app.h"

esp_now_peer_info_t peerInfo;

MacAddress_t g_macList[3];

esp_now_peer_info_t peer1;
esp_now_peer_info_t peer2;


BOOL MessageSendHandler(TimeStamp_t *dataPtr, MemoryConfig_t *memPtr, DevType_t device)
{
    BOOL retVal = FALSE;

    esp_err_t result = esp_now_send((const uint8_t *)&memPtr[device].mac, (const uint8_t *)dataPtr, sizeof(TimeStamp_t));

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

void DataSentCallBack(const uint8_t *mac_addr, esp_now_send_status_t status)
{
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
    memcpy(&g_receivedPacket, incomingData, sizeof(g_receivedPacket));
    Serial.print("Bytes received: ");
    Serial.println(len);
    Serial.print("TimeStamp: ");
    Serial.println(g_receivedPacket.timeStamp);
    Serial.print("Bool: ");
    Serial.println(g_receivedPacket.retVal);
    Serial.println();
    
}

/*BOOL TwrHandler(DevType_t Device)
{
    BOOL retVal = FALSE;

    if (IsTimeout(&g_twrTimer))
    {

        if (MessageSendHandler(&g_sendPacket, g_devMemoryConfig, Device))
        {
            //ReceivedFlag = FALSE;
            SwTimerEnable(&g_twrTimer, 3000);
        }
    }
    return retVal;
}*/

void Esp32NowInit()
{

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    memcpy(peer1.peer_addr, (const U8 *)&g_devMemoryConfig[ANCHOR_DEVICE_ONE].mac, 6);
    memcpy(peer2.peer_addr, (const U8 *)&g_devMemoryConfig[ANCHOR_DEVICE_TWO].mac, 6);

    peer1.channel = 0;
    peer2.channel = 0;
    peer1.encrypt = false;
    peer2.encrypt = false;

    if (esp_now_add_peer(&peer1) != ESP_OK)
    {
        Serial.println("Failed to add peer1");
        return;
    }

    if (esp_now_add_peer(&peer2) != ESP_OK)
    {
        Serial.println("Failed to add peer2");
        return;
    }

    esp_now_register_send_cb(DataSentCallBack);
    esp_now_register_recv_cb(OnDataRecv);
}