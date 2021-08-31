
#ifndef _LEDS_H_
#define _LEDS_H_

#include "stdint.h"
#include "stdbool.h"

void LedsInit(uint16_t* puerto);
void LedsTurnOn(uint16_t leds);
void LedsTurnOff(uint16_t leds);
void AllLedsTurnOn(void);
void AllLedsTurnOff(void);
bool LedIsOn(uint16_t led);

#endif