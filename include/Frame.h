#ifndef FRAME_H
#define FRAME_H

#include "Notation.h"

typedef enum
{
    TWR_START_MESSAGE = 0x00,
    TWR_RESPONSE_MESSAGE = 0x01,
    TWR_FINAL_MESSAGE = 0x02,
    TWR_MAX_MESSAGE
} MessageType_t;

typedef struct
{
    MacAddress_t sourceAdd;
    MacAddress_t destinationAdd;
} AddressBlock;

typedef struct
{
    char startFrame;
    U8 messageID;
    AddressBlock address;
    U64 crc;
    const char endFrame;
} MessagingParams_t;

//void FrameCreater(TimeStamp_t g_sendPacket, DevType_t source, DevType_t destination);

#endif
