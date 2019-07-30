#include <avr/io.h>
#include <util/delay.h>

/*
blink_button.c
LED pod��czony do pinu PD7
guzik pod��czony do pinu PD4
KR�L 2018
*/


int main(void)
{
	//wszystkie piny portu D opr�cz PD4 na wyj�cia
	DDRD = 0b11101111;
	PORTD = 0; // Zero bo czemu nie
    while (1) 
    {
		if(!(PIND & _BV(PD4))) // Gdy na PD4 jest stan niski
		{
			PORTD = _BV(PD7);
			_delay_ms(1000);
			PORTD = 0; // R�wnie� czemu nie
			_delay_ms(1000);
			PORTD = _BV(PD7);
			_delay_ms(1000);
			PORTD = 0; // I tu te�
		}
    }
}

