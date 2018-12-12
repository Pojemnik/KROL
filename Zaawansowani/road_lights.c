#include <avr/io.h>
#include <util/delay.h>

/*
road_lights.c
LEDy pod³¹czone do pinów PD7-5
guzik pod³¹czony do pinu PD4
KRÓL 2018
*/


int main(void)
{
	//wszystkie piny portu D oprócz PD4 na wyjœcia
	DDRD = 0b11101111;
	PORTD = _BV(PD7); // Czerwone
    while (1) 
    {
		if(!(PIND & _BV(PD4))) // Gdy na PD4 jest stan niski
		{
			_delay_ms(1000);
			PORTD |= _BV(PD6); // Zapalamy jeszcze ¿ó³te
			// Zwróæ uwagê na | (bitowe or)
			_delay_ms(1000);
			PORTD = _BV(PD5); // Gasimy pozosta³e i zapalamy zielone
			_delay_ms(1000);
			PORTD = _BV(PD6); // Gasimy zielone i zapalamy ¿ó³te
			_delay_ms(1000);
			PORTD = _BV(PD7); // Czerwone
		}
    }
}

