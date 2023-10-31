#ifndef NOTATION_H
#define NOTATION_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <esp_now.h>
#include <WiFi.h>
#include <NTPClient.h>
#include "freertos/timers.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define U8 uint8_t
#define U16 uint16_t
#define U32 uint32_t
#define I8 unsigned char
#define BOOL bool
#define TRUE true
#define FALSE false

typedef enum
{
    TAG_DEVICE = 0x00,
    ANCHOR_DEVICE_ONE = 0x01,
    ANCHOR_DEVICE_TWO = 0x02,
    MAX_DEVICE

} DevType_t;

typedef struct
{
    U8 mac[6];
} MacAddress_t;

typedef struct
{
    U32 timeStamp;
    BOOL retVal;
} TimeStamp_t;

typedef struct
{
    MacAddress_t mac;

} MemoryConfig_t;

typedef struct
{
    DevType_t DevType;

} MessagingParams_t;

typedef struct
{
    TickType_t startTime;
    TickType_t timeout;
    TickType_t lastTime;
    BOOL enabled;
} SwTimer_t;

#endif
