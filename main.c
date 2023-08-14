#include <stdio.h>
#include <avr/io.h>
#include <avr/delay.h>

void main(void)
{
	int i;
	int seven_seg[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
	DDRA = 0b00000111; //pins A0, A1, A2: output for LEDS
	DDRC = 0b01111111; //pins C0 - C6: output for left 7-seg
	DDRD = 0b01111111; //pins D0 - D6: output for right 7-seg

	while(1)
	{
		// green
		PORTA = 0b00000100; // green LED
		PORTC = seven_seg[1];
		PORTD = seven_seg[0]; // 7-seg displays 10
		_delay_ms(1000);
		PORTC = seven_seg[0]; // left 7-seg displays 0
		for (i = 9; i > 0; i--)
		{
			PORTD = seven_seg[i]; // right 7-seg changes over time
			_delay_ms(1000);
		}

		// yellow
		PORTA = 0b00000010; // yellow LED
		PORTC = seven_seg[0]; // 7-seg displays 03, left 7-seg displays 0
		for (i = 3; i > 0; i--)
		{
			PORTD = seven_seg[i]; // right 7-seg changes over time
			_delay_ms(1000);
		}

		// red
		PORTA = 0b00000001; // red LED
		PORTC = seven_seg[1];
		PORTD = seven_seg[0]; // 7-seg displays 10
		_delay_ms(1000);
		PORTC = seven_seg[0]; // left 7-seg displays 0
		for (i = 9; i > 0; i--)
		{
			PORTD = seven_seg[i]; // right 7-seg changes over time
			_delay_ms(1000);
		}

	}
	while(1);
}
