#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	//ustawiamy ca³y port D jako wyjœcia
	DDRD = 0xFF; //11111111
    while (1) 
    {
		PORTD = _BV(PD0); //Zapalamy bit PD0 w rejestrze PIND
		_delay_ms(1000); //Czekamy 1s
		PORTD = ~_BV(PD0); //Gasimy bit PD0 w rejestrze PIND
		_delay_ms(1000);
    }
}
