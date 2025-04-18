/*
 * Servo_and_Motor.c
 *
 * Date: 13/2/2025
 * Author : Eman Orabi
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdio.h>
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "DC_MOTOR_Interface.h"

int main() {
	PWM_init();
	UART_init(9600);
	Motor_init();

	while (1) {
		// Right
		MoveRight();
		ShowingTheValue('R');
		_delay_ms(2000);

		// Left

		MoveLeft();
		ShowingTheValue('L');
		_delay_ms(2000);

		// Forward

		MoveForward();
		ShowingTheValue('F');
		_delay_ms(2000);

		// Backward

		MoveBackward();
		ShowingTheValue('B');
		_delay_ms(2000);

		// Stop
		Stop();
		ShowingTheValue('S');
		_delay_ms(2000);
	}
}
