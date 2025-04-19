/*
 * MainApp.c
 *
 * Created: 4/19/2025 12:47:39 AM
 *  Author: hp
 */ 

#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "MainApp.h"
#include "avr/delay.h"



void setup_modes_pins() {
	DIO_SetPinDirection(PORT_B, PIN0, PIN_INPUT);
	DIO_SetPinDirection(PORT_B, PIN1, PIN_INPUT);
	DIO_SetPinDirection(PORT_B, PIN2, PIN_INPUT);
	DIO_SetPinDirection(PORT_B, PIN3, PIN_INPUT);
	
	DIO_SetPinDirection(PORT_C,PIN4,PIN_OUTPUT);  // for the Select pin in the Mux
	
	DIO_SetPinValue(PORT_B, PIN0, PIN_HIGH);
	DIO_SetPinValue(PORT_B, PIN1, PIN_HIGH);
	DIO_SetPinValue(PORT_B, PIN2, PIN_HIGH);
	DIO_SetPinValue(PORT_B, PIN3, PIN_HIGH);
	
	DIO_SetPinValue(PORT_C, PIN4, PIN_LOW);  // default for Raspberry Pi

}

u8 get_mode() {
	if (DIO_GetPinValue(PORT_B, PIN0) == PIN_LOW) return MODE_JOYSTICK; // Joystick
	if (DIO_GetPinValue(PORT_B, PIN1) == PIN_LOW) return MODE_MOBILE; // Mobile
	if (DIO_GetPinValue(PORT_B, PIN2) == PIN_LOW) return MODE_VOICE; // Voice
	if (DIO_GetPinValue(PORT_B, PIN3) == PIN_LOW) return MODE_EYE; // Eye
	return 255; // Undefined
}

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

	_delay_ms(200);

}

void MobileApp_Mode() {
	char command = UART_Receive(); // Receive from ESP
	switch(command) {
		case 'f': MoveForward(); ShowingTheValue('F'); break;
		case 'b': MoveBackward(); ShowingTheValue('B'); break;
		case 'l': MoveLeft(); ShowingTheValue('L'); break;
		case 'r': MoveRight(); ShowingTheValue('R'); break;
		case 's': Stop(); ShowingTheValue('S'); break;
		default: UART_sendString("Invalid Command\n"); break;
	}
	_delay_ms(200);
}


void Voice_Mode() {
	char command = UART_Receive();  //Receive from raspberry  Pi 
	switch(command) {
		case 'f': MoveForward(); ShowingTheValue('F'); break;
		case 'b': MoveBackward(); ShowingTheValue('B'); break;
		case 'l': MoveLeft(); ShowingTheValue('L'); break;
		case 'r': MoveRight(); ShowingTheValue('R'); break;
		case 's': Stop(); ShowingTheValue('S'); break;
		default: UART_sendString("Invalid Command\n"); break;
	}
	_delay_ms(200);
}

void EyeTracking_Mode() {
	
	char direction = UART_Receive();  //Receive from raspberry  Pi 
	switch(direction) {
		case 'f': MoveForward(); ShowingTheValue('F'); break;
		case 'b': MoveBackward(); ShowingTheValue('B'); break;
		case 'l': MoveLeft(); ShowingTheValue('L'); break;
		case 'r': MoveRight(); ShowingTheValue('R'); break;
		case 's': Stop(); ShowingTheValue('S'); break;
		default: UART_sendString("Invalid Command\n"); break;
	}
	_delay_ms(200);
}
