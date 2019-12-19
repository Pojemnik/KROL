#include <avr/io.h>
#include <avr/interrupt.h>

//* program
//  sprawia ze dwie diody zapalaja sie i gasna za pomoca timer 

//* podlaczenie 
//  dwa ledy jednen do PC5 drugi do PC4

volatile uint8_t var_time;

int main(void)
{
	DDRC = 0xFF; // ustawienie wszystkich portów na wyjscie 
	
	TCCR0A = (1 << WGM01) | (1 << COM0A1); // ustawienie trubu zegara na CTC (Clear Timer on Comper)
	TCCR0B = (1 << CS02) | (1 << CS00); // prescaler 1024
	
	OCR0A = 78; // troche matmy ---> 8 000 000 Hz / 1024 = 7 812,5 Hz (zegar dla timer - 7812,5 cykli na sekunde) ---> 78,125 cykli na 0,01s
	// przerwanie wykona siê raz na ok 0,01s
	
	TIMSK0 |= (1 << OCIE0A);                // zezwolenie na przerwanie CompareMatch
	
	sei();                              //zezwolenie na prerwania globalne
	
    while (1) 
    {
		if(var_time >= 50) PORTC |= (1 << PC5);
		else PORTC &= ~(1 << PC5);
		
		if((var_time >= 0 && var_time <= 25) || (var_time >= 50 && var_time <= 75)) PORTC |= (1 << PC4);
		else PORTC &= ~(1 << PC4);
    }
}

ISR(TIMER0_COMPA_vect)
{	
	if(var_time >= 100) var_time = 0;
	else var_time++;
}

