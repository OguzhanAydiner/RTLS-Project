#ifndef APP_H
#define APP_H

#include "notation.h"
#include "memory.h"
#include "swTimer.h"

/*                          Functions                                          */

BOOL MessageSendHandler(RssiPacket_t *dataPtr, DevType_t device);
void Esp32NowInit();
//void RSSIHandler(void *pvParameters);
double RssiBasedCalculation(int8_t rssi);
void SentCB(const uint8_t *mac_addr, esp_now_send_status_t status);
void ReceiveCB(const uint8_t *mac, const uint8_t *incomingData, int len);

extern esp_now_peer_info_t peerInfo;
extern RssiPacket_t g_sendPacket;
extern RssiPacket_t g_receivedPacket;

#endif