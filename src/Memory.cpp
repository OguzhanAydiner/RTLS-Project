#include "memory.h"

MemoryConfig_t          g_devMemoryConfig;

/*

void    FrameInit ()
{
<<<<<<< HEAD
    g_macList[TAG_DEVICE]        = {0x3C, 0xE9, 0x0E, 0x0B, 0x66, 0x5C}; 
    g_macList[ANCHOR_DEVICE_ONE] = {0x40, 0x22, 0xD8, 0x6B, 0x4C, 0x68}; 
    g_macList[ANCHOR_DEVICE_TWO] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};  
=======
    g_macList[TAG_DEVICE]        = {0x40, 0x22, 0xD8, 0x6B, 0x4C, 0x68};
    g_macList[ANCHOR_DEVICE_ONE] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    g_macList[ANCHOR_DEVICE_TWO] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445
}*/



void   MemoryInit ()
{
<<<<<<< HEAD
    memcpy((void *)&g_devMemoryConfig, 0, sizeof(MemoryConfig_t));
=======
    //memcpy(g_devMemoryConfig, 0, sizeof(MemoryConfig_t));
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445

    g_devMemoryConfig.devType = ANCHOR_DEVICE_ONE;
    g_devMemoryConfig.mac     = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    //{ 0x3C, 0xE9, 0x0E, 0x0B, 0x66, 0x5C}; 
<<<<<<< HEAD
} 

=======
} 
>>>>>>> b01286fff3327c1fe786982caa1a68524f336445
