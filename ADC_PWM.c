#include <avr/io.h>

int wartosc_z_ADC;
int pomocnicza;

int main(void)
{
	//ustawienia PWM (urzuchomienie, jak ma działać i inne takie)
	TCCR0A =
	(1 << COM0A1) | // ustawienia - wyczyść licznik, jeżeli jego wartość jest równa ustalonej wartości (wsystko jest w datasheetcie)
	(1 << WGM00) | (1 << WGM01); // tryb pracy (Wave Form Generation Mode) - generuj szybki PWM
	
	TCCR0B = 
	(1 << CS02); //dzieli gówny zegar przez 256 (wartości są stablicowane)
		
	//ustawienia ADC (to samo co wyżej)
	ADMUX = // I rejsetr z ustawieniami
	(1 << MUX0); // czutaj napięcie na nóżce z ADC1 (wartości są stabilcowane)
	ADCSRA = // II rejestr z ustawieniami
	(1 << ADEN) | // ADC enable (nie rozpoczynaj)
	(1 << ADSC); // ADC rozpocznij 
	
	
    while (1) 
    {
		pomocnicza = ADCH;
		wartosc_z_ADC = pomocnicza << 8;
		wartosc_z_ADC = ADCL;
		
		wartosc_z_ADC /= 4;
		
		OCR0A = wartosc_z_ADC;
   }
}
