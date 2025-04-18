/*
 * DIO_Interface.h
 *
 * Created: 1/23/2025 4:59:18 PM
 *  Author: Eman Orabi
 */ 

#include "STD_TYPES.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Function Prototypes that deals with pins */

void DIO_SetPinDirection(u8 PortName,u8 PinNumber,u8 PinDirection);
void DIO_SetPinValue(u8 PortName,u8 PinNumber,u8 PinValue);
u8   DIO_GetPinValue(u8 Portname,u8 PinNumber);

/* Function Prototypes that deals with pins */

void DIO_SetPortDirection(u8 Portname,u8 PortDirection);
void DIO_SetPortValue(u8 Portname,u8 PortValue);

/* Macros For Pins used */

#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7

#define PORT_A      1
#define PORT_B      2
#define PORT_C      3
#define PORT_D      4

#define PIN_HIGH    1
#define PIN_LOW     0

#define PIN_OUTPUT  1
#define PIN_INPUT   0

#define PORT_OUTPUT 1
#define PORT_INPUT  0
#define PORT_LOW    0
#define PORT_HIGH   1

#endif /* DIO_INTERFACE_H_ */