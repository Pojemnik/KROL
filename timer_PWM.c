#include <avr/io.h>
#include <util/delay.h>

/*
timer_PWM.c
LED podłączony do pinu PD3
KRÓL 2019
*/

int main(void)
{
	DDRD = 0xFF;
	TCCR2A = _BV(WGM21) | _BV(COM2B1) | _BV(WGM20);	//Konfiguracja timera: Tryb fast PWM, wyjście
	TCCR2B = _BV(CS22);								//Prescaler
	OCR2B = 255;
    while (1) 
    {
		for(uint8_t i = 0; i < 5; i++)
		{
			OCR2B = i*50;							//Wypełnienie PWM
			_delay_ms(100);
		}
    }
}
