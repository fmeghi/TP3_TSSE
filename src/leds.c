#include "leds.h"

#define LEDS_ALL_OFF 0x0000
#define LEDS_INDEX_OFFSET 1
#define LEDS_STATE_ON 1

static uint16_t* puerto_leds;

static uint16_t LedsIndexToMask(int leds)
{
    return (LEDS_STATE_ON << (leds - LEDS_INDEX_OFFSET));
}

void LedsInit(uint16_t* puerto)
{
    *puerto = LEDS_ALL_OFF;
    puerto_leds = puerto;
}

void LedsTurnOn(uint16_t leds)
{
    *puerto_leds = *puerto_leds | LedsIndexToMask(leds);
}

void LedsTurnOff(uint16_t leds)
{
    *puerto_leds = *puerto_leds & ~LedsIndexToMask(leds);
}

void AllLedsTurnOn(void)
{
    *puerto_leds = 0xFFFF;
}

void AllLedsTurnOff(void)
{
    *puerto_leds = 0x0000;
}

bool LedIsOn(uint16_t led)
{
    return (*puerto_leds & LedsIndexToMask(led));
}