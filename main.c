#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0;
	DDRD = 0xFF;
	
	//set u pwm
	TCCR2A = _BV(WGM21) | _BV(COM2B1) | _BV(WGM20);	//Konfiguracja timera: Tryb fast PWM, wyjœcie
	TCCR2B = _BV(CS22);								//Prescaler
	
	//set up adc
	ADMUX = _BV(MUX1) | _BV(ADLAR) | _BV(REFS0);	// Kana³ 2, przesuniêcie do lewej, napiêcie odniesienia
	ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
	
	OCR2B = 255;
	
    while (1) 
    {
		ADCSRA |= _BV(ADSC);
		_delay_ms(1000);
		OCR2B = ADCH;
    }
}

