#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // Configure PD6 (OC0A) as output.
  DDRD |= (1 << PD6);
  // Setup Timer0 in Fast PWM mode with non-inverting output on OC0A.
  TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
  // No prescaler (full speed).
  TCCR0B |= (1 << CS00);
  while(1) {
    for (int i = 0; i <= 255; i++) {
      OCR0A = i;
      _delay_ms(50);
    }
    for (int i = 255; i >= 0; i--) {
      OCR0A = i;
      _delay_ms(50);
    }
  }
  return 0;
}
