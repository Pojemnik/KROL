#include <avr/io.h>
#include <util/delay.h>

/*
blink_bit_shift.c
LEDy pod³¹czone do pinów PD7-5
KRÓL 2018
*/


int main(void)
{
	//wszystkie piny portu D na wyjœcia
	DDRD = 0xFF;
    while (1) 
    {
		PORTD = _BV(PD7); // PORTD = 1000 0000 - dziêki spacji lepiej widaæ 
		_delay_ms(100);
		PORTD = (PORTD >> 1); // PORTD = 0100 0000 
		_delay_ms(100);
		PORTD = (PORTD >> 1); // PORTD = 0010 0000 
		_delay_ms(100);
		PORTD = (PORTD >> 1); // PORTD = 0001 0000
		_delay_ms(100);
    }
}

