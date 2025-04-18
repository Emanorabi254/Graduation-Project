/*
 * JoyStick_Program.c
 *
 * Created: 4/18/2025 2:56:43 AM
 *  Author: Eman Orabi
 */ 

#include "avr/delay.h"
#include "STD_TYPES.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "JoyStick_Interface.h"

void JoyStick_Mode() {
	
	u16 x = ADC_Read(0); // Read X-axis
	u16 y = ADC_Read(1); // Read Y-axis
	char buffer[20];
	sprintf(buffer, "--> X: %d and Y: %d \r\n", x, y);
	
	if (y > 600) {
		MoveBackward();
		ShowingTheValue('B');
		UART_sendString(buffer);
	}
	else if (y < 400) {
		MoveForward();
		ShowingTheValue('F');
		UART_sendString(buffer);
	}
	else if (x < 400) {
		MoveLeft();
		ShowingTheValue('L');
		UART_sendString(buffer);
	}
	else if (x > 600) {
		MoveRight();
		ShowingTheValue('R');
		UART_sendString(buffer);
	}
	else {
		Stop();
		ShowingTheValue('S');
		UART_sendString(buffer);
	}

	_delay_ms(300);

}