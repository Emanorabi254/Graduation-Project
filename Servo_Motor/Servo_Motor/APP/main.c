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
#include "ADC_Interface.h"

int main() {
	PWM_init();
	UART_init(9600);
	Motor_init();
	ADC_Init();

	while (1) {
		u16 x = ADC_Read(0); // Read X-axis
		u16 y = ADC_Read(1); // Read Y-axis
			char buffer[20];
			sprintf(buffer, "X=%d Y=%d\n", x, y);
			
			if (y > 600) {
				MoveBackward();
				ShowingTheValue('B');
			}
			else if (y < 400) {
				MoveForward();
				ShowingTheValue('F');
			}
			else if (x < 400) {
				MoveLeft();
				ShowingTheValue('L');
			}
			else if (x > 600) {
				MoveRight();
				ShowingTheValue('R');
			}
			else {
				Stop();
				ShowingTheValue('S');
			}

			_delay_ms(300);
	}
}
