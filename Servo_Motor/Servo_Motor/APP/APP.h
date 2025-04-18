/*
 * main.h
 *
 * Created: 4/19/2025 12:19:53 AM
 *  Author: hp
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include "DIO_Interface.h"


#define MODE_JOYSTICK 0
#define MODE_MOBILE   1
#define MODE_VOICE    2
#define MODE_EYE      3

DIO_SetPinDirection(PORT_B, PIN0, PIN_INPUT);
DIO_SetPinDirection(PORT_B, PIN1, PIN_INPUT);
DIO_SetPinDirection(PORT_B, PIN2, PIN_INPUT);
DIO_SetPinDirection(PORT_B, PIN3, PIN_INPUT);

DIO_SetPinValue(PORT_B, PIN0, PIN_HIGH);
DIO_SetPinValue(PORT_B, PIN1, PIN_HIGH);
DIO_SetPinValue(PORT_B, PIN2, PIN_HIGH);
DIO_SetPinValue(PORT_B, PIN3, PIN_HIGH);

u8 get_mode() {
	if (DIO_GetPinValue(PORT_B, PIN0) == PIN_LOW) return MODE_JOYSTICK; // Joystick
	if (DIO_GetPinValue(PORT_B, PIN1) == PIN_LOW) return MODE_MOBILE; // Mobile
	if (DIO_GetPinValue(PORT_B, PIN2) == PIN_LOW) return MODE_VOICE; // Voice
	if (DIO_GetPinValue(PORT_B, PIN3) == PIN_LOW) return MODE_EYE; // Eye
	return 255; // Undefined
}


#endif /* MAIN_H_ */