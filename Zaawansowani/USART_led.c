#include <avr/io.h>
#include <util/delay.h>

/*
USART_led.c
LEDy pod��czone do pin�w PD5-7
Przycisk na pinie PD4
KR�L 2018
*/


int main(void)
{
	//wszystkie piny portu D opr�cz PD4 na wyj�cia
	DDRD = 0b11101111;
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);		// W��czamy odbiornik i nadajnik
	UBRR0L = 103;							// Baud rate (warto�� z datasheetu)
	PORTD = 0;
    while (1) 
    {
		if(UCSR0A & _BV(RXC0))				// Gdy co� odbierzemy
		{
			char x = UDR0;
			switch(x)
			{
				case '1':
				PIND |= _BV(PD7);			// Zapis do rejestru PINx zmienia stan wyj�cia na przeciwny
				break;
				case '2':
				PIND |= _BV(PD6);
				break;
				case '3':
				PIND |= _BV(PD5);
				break;
			}
			while(!(UCSR0A & _BV(UDRE0)));
			UDR0 = x;						// Ode�lij to, co dosta�e�
		}
		if(!(PIND & _BV(PD4)))				// Gdy co� odbierzemy
		{
			while(!(UCSR0A & _BV(UDRE0)));
			UDR0 = '1';						// Wysy�amy jedynke z pozdrowieniami
		}
    }
}

