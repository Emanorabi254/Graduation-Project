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
#include "JoyStick_Interface.h"
int main() {
	PWM_init();
	UART_init(9600);
	Motor_init();
	ADC_Init();

	while (1) {
		
		JoyStick_Mode();
		
			}
}
