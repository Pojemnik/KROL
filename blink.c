#include <avr/io.h>
#include <util/delay.h>

/*
blink.c
LED podłączony do pinu PD0
KRÓL 2018
*/


int main(void)
{
	//ustawiamy cały port D jako wyjœcia
	DDRD = 0xFF; //11111111
    while (1) 
    {
		PORTD = _BV(PD0); //Zapalamy bit PD0 w rejestrze PIND
		_delay_ms(1000); //Czekamy 1s
		PORTD = ~_BV(PD0); //Gasimy bit PD0 w rejestrze PIND
		_delay_ms(1000);
    }
}
