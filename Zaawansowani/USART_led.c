#include <avr/io.h>
#include <util/delay.h>

/*
USART_led.c
LEDy pod³¹czone do pinów PD5-7
Przycisk na pinie PD4
KRÓL 2018
*/


int main(void)
{
	//wszystkie piny portu D oprócz PD4 na wyjœcia
	DDRD = 0b11101111;
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);		// W³¹czamy odbiornik i nadajnik
	UBRR0L = 103;							// Baud rate (wartoœæ z datasheetu)
	PORTD = 0;
    while (1) 
    {
		if(UCSR0A & _BV(RXC0))				// Gdy coœ odbierzemy
		{
			char x = UDR0;
			switch(x)
			{
				case '1':
				PIND |= _BV(PD7);			// Zapis do rejestru PINx zmienia stan wyjœcia na przeciwny
				break;
				case '2':
				PIND |= _BV(PD6);
				break;
				case '3':
				PIND |= _BV(PD5);
				break;
			}
			while(!(UCSR0A & _BV(UDRE0)));
			UDR0 = x;						// Odeœlij to, co dosta³eœ
		}
		if(!(PIND & _BV(PD4)))				// Gdy coœ odbierzemy
		{
			while(!(UCSR0A & _BV(UDRE0)));
			UDR0 = '1';						// Wysy³amy jedynke z pozdrowieniami
		}
    }
}

