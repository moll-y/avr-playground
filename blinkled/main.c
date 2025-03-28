#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  /* Data Direction Register B: writing a one to the bit enables output. */
  DDRB |= 0b00000001;

  while (1) {
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b00000000;
    _delay_ms(1000);
  }

  return 0;
}
