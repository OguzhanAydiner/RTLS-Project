#ifndef APP_H
#define APP_H


#include "notation.h"
#include "memory.h"
#include "swTimer.h"



typedef struct {
	U32				timeStamp;
	BOOL			retVal;
} TimeStamp_t;


extern TimeStamp_t             g_sendPacket;
extern TimeStamp_t             g_receivedPacket;
extern volatile BOOL 		   packetReceived;

/*                          Functions                                          */

void DataSentCallBack(const uint8_t *mac_addr, esp_now_send_status_t status);
BOOL MessageSendHandler(TimeStamp_t *dataPtr, MemoryConfig_t *memPtr, DevType_t device);
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);

#endif

