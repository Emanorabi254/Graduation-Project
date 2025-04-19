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
#include "MainApp.h"



int main() {
	PWM_init();
	UART_init(9600);
	Motor_init();
	ADC_Init();
	setup_modes_pins();
	
	while (1) {
		u8 Chosen_Mode = get_mode();

		switch (Chosen_Mode) {
			case 0:
			JoyStick_Mode();
			break;

			case 1:
			MobileApp_Mode();
			break;

			case 2:
			Voice_Mode();
			break;

			case 3:
			EyeTracking_Mode();
			break;

			default:
			UART_sendString("No Mode Selected!\n");
			break;
		}
	}

}
