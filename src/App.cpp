#include "app.h"
#include "swTimer.h"
#include "network.h"
#include "memory.h"

esp_now_peer_info_t peerInfo;

RssiPacket_t g_sendPacket;
RssiPacket_t g_receivedPacket;

BOOL MessageSendHandler(RssiPacket_t *dataPtr, DevType_t device)
{
    BOOL retVal = FALSE;
    esp_err_t result = esp_now_send((const uint8_t *)&g_devMemoryConfig[device].mac, (const uint8_t *)dataPtr, sizeof(RssiPacket_t));
    return retVal;
}

void Esp32NowInit()
{

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    if (DEVICE_TYPE == ANCHOR_DEVICE_ONE)
    {
        memcpy(peerInfo.peer_addr, (const void *)&g_devMemoryConfig[ANCHOR_DEVICE_TWO].mac, sizeof(peerInfo.peer_addr));
    }

    else if (DEVICE_TYPE == ANCHOR_DEVICE_TWO)
    {
        memcpy(peerInfo.peer_addr, (const void *)&g_devMemoryConfig[ANCHOR_DEVICE_ONE].mac, sizeof(peerInfo.peer_addr));
    }

    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    if (esp_now_is_peer_exist(peerInfo.peer_addr))
    {
        esp_now_del_peer(peerInfo.peer_addr); // Optionally remove the existing peer
    }
    esp_err_t result = esp_now_add_peer(&peerInfo);

    if (result != ESP_OK)
    {
        Serial.println("Failed to add peer");
        printf("Error (0x%x): %s\n", result, esp_err_to_name(result));
    }

    result = esp_now_register_send_cb(SentCB);

    if (result != ESP_OK)
    {
        Serial.println("Failed to register SentCB");
        printf("Error (0x%x): %s\n", result, esp_err_to_name(result));
    }
    result = esp_now_register_recv_cb(ReceiveCB);

    if (result != ESP_OK)
    {
        Serial.println("Failed to register Receive");
        printf("Error (0x%x): %s\n", result, esp_err_to_name(result));
    }
}

/*
void RSSIHandler(void *pvParameters)
{
    TimerHandle_t rssiGetTime = xTimerCreate("RSSI Get", pdMS_TO_TICKS(50), pdTRUE, 0, RssiGetCB);
    TimerHandle_t rssiPrintTime = xTimerCreate("RSSI Print", pdMS_TO_TICKS(500), pdTRUE, 0, RssiPrintCB);

    if (rssiGetTime == NULL)
    {
        Serial.println("Timer creation failed!(Get)");
    }
    else
    {
        if (xTimerStart(rssiGetTime, 0) != pdPASS)
        {
            Serial.println("Timer start failed!(Get)");
        }
    }
    if (rssiPrintTime == NULL)
    {
        Serial.println("Timer creation failed!(print)");
    }
    else
    {
        if (xTimerStart(rssiPrintTime, 0) != pdPASS)
        {
            Serial.println("Timer start failed!(print)");
        }
    }
}
*/

double RssiBasedCalculation(int8_t rssi)
{
    double distance;
    /*
        if (rssi < -60)
        {
            distance = exp(-0.06059435 * (rssi + 23));
        }

        else
        {
            distance = exp(-0.082232 * (rssi + 23));
        }
        */
    // double distance = 0.09831667 * exp(-0.065788 * rssi);

    // distance = exp(-0.06059435 * (rssi + 22.0));
    distance = pow(10, ((rssi + 26) / -25.12));
    distance = roundf(distance * 100) / 100;

    return distance;
}

/////////////////////////////   CALLBACK FUNCTIONS  //////////////////////////////////

void SentCB(const uint8_t *mac_addr, esp_now_send_status_t status)
{
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void ReceiveCB(const uint8_t *mac, const uint8_t *incomingData, int len)
{
    memcpy(&g_receivedPacket, incomingData, sizeof(g_receivedPacket));
    Serial.printf("Received Rssi Value:");
    Serial.println(g_receivedPacket.rssi);
}
