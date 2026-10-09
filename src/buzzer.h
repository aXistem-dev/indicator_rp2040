#pragma once

#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER_GPIO 19

#include <Arduino.h>

extern uint32_t buzz_off;

void beep_init(void);
void beep_off(void);
void beep_on(uint32_t duration);
// A tone of the given frequency; duration 0 plays until the next tone or beep,
// frequency 0 stops whatever the buzzer is playing
void tone_play(uint32_t frequency, uint32_t duration);

#endif // BUZZER_H