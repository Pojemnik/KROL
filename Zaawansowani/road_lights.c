#include <avr/io.h>
#include <util/delay.h>

/*
road_lights.c
LEDy pod��czone do pin�w PD7-5
guzik pod��czony do pinu PD4
KR�L 2018
*/


int main(void)
{
	//wszystkie piny portu D opr�cz PD4 na wyj�cia
	DDRD = 0b11101111;
	PORTD = _BV(PD7); // Czerwone
    while (1) 
    {
		if(!(PIND & _BV(PD4))) // Gdy na PD4 jest stan niski
		{
			_delay_ms(1000);
			PORTD |= _BV(PD6); // Zapalamy jeszcze ��te
			// Zwr�� uwag� na | (bitowe or)
			_delay_ms(1000);
			PORTD = _BV(PD5); // Gasimy pozosta�e i zapalamy zielone
			_delay_ms(1000);
			PORTD = _BV(PD6); // Gasimy zielone i zapalamy ��te
			_delay_ms(1000);
			PORTD = _BV(PD7); // Czerwone
		}
    }
}

