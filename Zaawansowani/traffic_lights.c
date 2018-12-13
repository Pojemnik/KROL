#include <avr/io.h>
#include <util/delay.h>

/*
traffic_lights.c (Dzięki Janek)
LEDy podłączone do pinów PD7-5
guzik podłączony do pinu PD4
KRÓL 2018
*/


int main(void)
{
	//wszystkie piny portu D oprócz PD4 na wyjścia
	DDRD = 0b11101111;
	PORTD = _BV(PD7); // Czerwone
    while (1) 
    {
		if(!(PIND & _BV(PD4))) // Gdy na PD4 jest stan niski
		{
			_delay_ms(1000);
			PORTD |= _BV(PD6); // Zapalamy jeszcze żółte
			// Zwróć uwagę na | (bitowe or)
			_delay_ms(1000);
			PORTD = _BV(PD5); // Gasimy pozostałe i zapalamy zielone
			_delay_ms(1000);
			PORTD = _BV(PD6); // Gasimy zielone i zapalamy żółte
			_delay_ms(1000);
			PORTD = _BV(PD7); // Czerwone
		}
    }
}

