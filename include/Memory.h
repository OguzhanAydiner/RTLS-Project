#ifndef MEMORY_H
#define MEMORY_H

#include "notation.h"

typedef struct
{
    MacAddress_t mac;

} MemoryConfig_t;

extern MemoryConfig_t g_devMemoryConfig[3];
extern TimeStamp_t g_sendPacket;
extern TimeStamp_t g_receivedPacket;
extern BOOL ReceivedFlag;

void MemoryInit();

#endif
