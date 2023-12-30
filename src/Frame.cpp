#include "Frame.h"

//MessagingParams_t SendPacket;
static U8 *MessageID = 0;
const char *startFrame = "<<<";
const char *endFrame = ">>>";
/*
void FrameCreater(TimeStamp_t g_sendPacket, DevType_t source, DevType_t destination)
{
    MEMCPY((void *)SendPacket.startFrame, (void *)startFrame, sizeof(startFrame));
    MEMCPY(&SendPacket.timeStamp, MessageID, sizeof(MessageID));
    MEMCPY(&SendPacket.timeStamp, &g_sendPacket, sizeof(g_sendPacket));
    MEMCPY(&SendPacket.address.sourceAdd, &g_sendPacket, sizeof(g_sendPacket));
    MEMCPY(&SendPacket.timeStamp, &g_sendPacket, sizeof(g_sendPacket));
    MEMCPY((void *)SendPacket.startFrame, (void *)startFrame, sizeof(endFrame));

    Serial.println(SendPacket.startFrame);
    Serial.println(SendPacket.messageID);
    Serial.println(SendPacket.timeStamp.timeStamp);
    Serial.println(SendPacket.messageID);
}*/