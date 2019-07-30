#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*
interrupt_led.c
LEDy pod³¹czony do pinu PD5
Przycisk na pinie PD2 (INT0) - pullup
KRÓL 2019
*/

int main(void)
{
	EICRA = _BV(ISC01);	//Przerwanie na zbpczu opadaj¹cym
	EIMSK = _BV(INT0);	//W³¹cz przerwanie INT0 (PD2)
	DDRD = 0b11111011;
	PORTD = 0;
	sei();
	while(1)
	{
		PIND = _BV(PD5);
		_delay_ms(500);
	}
}

ISR(INT0_vect)			//Obs³uga przerwania INT0
{
	PIND = _BV(PD5);
	_delay_ms(2000);
}