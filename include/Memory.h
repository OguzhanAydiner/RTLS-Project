#ifndef MEMORY_H
#define MEMORY_H

#include "notation.h"



typedef struct 
{
    DevType_t           devType;
    MacAddress_t        mac;
} MemoryConfig_t;


extern MemoryConfig_t          g_devMemoryConfig;


void MemoryInit();

#endif




