#ifndef APP_H
#define APP_H

#include "notation.h"
#include "memory.h"
#include "swTimer.h"


/*                          Functions                                          */

void DataSentCallBack(const uint8_t *mac_addr, esp_now_send_status_t status);
BOOL MessageSendHandler(TimeStamp_t *dataPtr, MemoryConfig_t *memPtr, DevType_t device);
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);
void Esp32NowInit();
BOOL TwrHandler(DevType_t Device);

#endif