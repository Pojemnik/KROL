#include <avr/io.h>
#include <util/delay.h>

/*
blink_bit_shift.c
LEDy podłączone do pinów PD7-5
KRÓL 2018
*/

int main(void)
{
	DDRD = 0xFF; //wszystkie piny portu D na wyjścia
    while (1) 
    {
		PORTD = _BV(PD7); 		// PORTD = 10000000 
		_delay_ms(100);
		PORTD = (PORTD >> 1); 	// PORTD = 01000000 
		_delay_ms(100);
		PORTD = (PORTD >> 1); 	// PORTD = 00100000 
		_delay_ms(100);
		PORTD = (PORTD >> 1); 	// PORTD = 00010000
		_delay_ms(100);
    }
}

