#include <avr/io.h>
#include <util/delay.h>

/*
ADC_USART.c
Wejœcie potencjometru na pinie PC2
KRÓL 2019
*/


int main(void)
{
	DDRC = 0;
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);		// W³¹czamy odbiornik i nadajnik
	UBRR0L = 103;							// Baud rate (wartoœæ z datasheetu)
	ADMUX = _BV(MUX1) | _BV(ADLAR) | _BV(REFS0);	// Kana³ 2, przesuniêcie do lewej, napiêcie odniesienia
	ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);	// W³¹czamy ADC, prescaler
	while (1)
	{
		ADCSRA |= _BV(ADSC);
		_delay_ms(1000);
		while(!(UCSR0A & _BV(UDRE0)));
		UDR0 = ADCH;
	}
}

