/*
 * MainApp.c
 *
 * Created: 4/19/2025 12:47:39 AM
 *  Author: hp
 */ 

#include "DIO_Interface.h"
#include "MainApp.h"




void setup_modes_pins() {
	DIO_SetPinDirection(PORT_B, PIN0, PIN_INPUT);
	DIO_SetPinDirection(PORT_B, PIN1, PIN_INPUT);
	DIO_SetPinDirection(PORT_B, PIN2, PIN_INPUT);
	DIO_SetPinDirection(PORT_B, PIN3, PIN_INPUT);

	DIO_SetPinValue(PORT_B, PIN0, PIN_HIGH);
	DIO_SetPinValue(PORT_B, PIN1, PIN_HIGH);
	DIO_SetPinValue(PORT_B, PIN2, PIN_HIGH);
	DIO_SetPinValue(PORT_B, PIN3, PIN_HIGH);
}

u8 get_mode() {
	if (DIO_GetPinValue(PORT_B, PIN0) == PIN_LOW) return MODE_JOYSTICK; // Joystick
	if (DIO_GetPinValue(PORT_B, PIN1) == PIN_LOW) return MODE_MOBILE; // Mobile
	if (DIO_GetPinValue(PORT_B, PIN2) == PIN_LOW) return MODE_VOICE; // Voice
	if (DIO_GetPinValue(PORT_B, PIN3) == PIN_LOW) return MODE_EYE; // Eye
	return 255; // Undefined
}
