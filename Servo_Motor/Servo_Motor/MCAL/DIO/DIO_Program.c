/*
 * DIO_Program.c
 *
 * Created: 1/23/2025 5:15:09 PM
 *  Author: Eman Orabi
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

/* Function definitions that deals with pins */

void DIO_SetPinDirection(u8 PortName,u8 PinNumber,u8 PinDirection)
{
	if(PinDirection==PIN_OUTPUT)
	{
		switch(PortName)
		{	case PORT_A: SET_BIT(DDRA,PinNumber);
			break;
			case PORT_B: SET_BIT(DDRB,PinNumber);
			break;
			case PORT_C: SET_BIT(DDRC,PinNumber);
			break;
			case PORT_D: SET_BIT(DDRD,PinNumber);
			break;
		}
	}
	else if(PinDirection==PIN_INPUT)
	{
		switch(PortName)
		{	case PORT_A: CLR_BIT(DDRA,PinNumber);
			break;
			case PORT_B: CLR_BIT(DDRB,PinNumber);
			break;
			case PORT_C: CLR_BIT(DDRC,PinNumber);
			break;
			case PORT_D: CLR_BIT(DDRD,PinNumber);
			break;
		}
	}
}
void DIO_SetPinValue(u8 PortName,u8 PinNumber,u8 PinValue)
{
		if(PinValue==PIN_HIGH)
		{
			switch(PortName)
			{	case PORT_A: SET_BIT(PORTA,PinNumber);
				break;
				case PORT_B: SET_BIT(PORTB,PinNumber);
				break;
				case PORT_C: SET_BIT(PORTC,PinNumber);
				break;
				case PORT_D: SET_BIT(PORTD,PinNumber);
				break;
			}
		}
		else if(PinValue==PIN_LOW)
		{
			switch(PortName)
			{	case PORT_A: CLR_BIT(PORTA,PinNumber);
				break;
				case PORT_B: CLR_BIT(PORTB,PinNumber);
				break;
				case PORT_C: CLR_BIT(PORTC,PinNumber);
				break;
				case PORT_D: CLR_BIT(PORTD,PinNumber);
				break;
			}
		}
}
u8   DIO_GetPinValue(u8 Portname,u8 PinNumber)
{
	u8 PinState;
	switch(Portname)
	{
		case PORT_A:PinState=GET_BIT(PINA,PinNumber);
		break;
		case PORT_B:PinState=GET_BIT(PINB,PinNumber);
		break;
		case PORT_C:PinState=GET_BIT(PINC,PinNumber);
		break;
		case PORT_D:PinState=GET_BIT(PIND,PinNumber);
		break;
	}
	return PinState;	
}

/* Function definitions that deals with pins */

void DIO_SetPortDirection(u8 Portname,u8 PortDirection)
{
	switch(Portname)
	{
		case PORT_A: DDRA=PortDirection;
		break;
		case PORT_B: DDRB=PortDirection;
		break;
		case PORT_C: DDRC=PortDirection;
		break;
		case PORT_D: DDRD=PortDirection;
		break;
	}
}
void DIO_SetPortValue(u8 Portname,u8 PortValue)
{
	switch(Portname)
	{
		case PORT_A: PORTA=PortValue;
		break;
		case PORT_B: PORTB=PortValue;
		break;
		case PORT_C: PORTC=PortValue;
		break;
		case PORT_D: PORTD=PortValue;
		break;
	}
}
