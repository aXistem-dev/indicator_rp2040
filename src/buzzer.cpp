#include "buzzer.h"

uint32_t buzz_off = 0;

void beep_init(void) { pinMode(BUZZER_GPIO, OUTPUT); }
void beep_off(void) { digitalWrite(BUZZER_GPIO, LOW); }
void beep_on(uint32_t duration) {
  noTone(BUZZER_GPIO); // a tone and the beep PWM must not drive the pin together
  analogWrite(BUZZER_GPIO, 127);
  buzz_off = millis() + duration;
  if (buzz_off == 0) // 0 means inactive, don't let the beep stick on
    buzz_off = 1;
}
void tone_play(uint32_t frequency, uint32_t duration) {
  buzz_off = 0; // a running beep gives way to the tone
  noTone(BUZZER_GPIO);
  if (frequency == 0) {
    beep_off();
    return;
  }
  if (duration == 0)
    tone(BUZZER_GPIO, frequency);
  else
    tone(BUZZER_GPIO, frequency, duration);
}
