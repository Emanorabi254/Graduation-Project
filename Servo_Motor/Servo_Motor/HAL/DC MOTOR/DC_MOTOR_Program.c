/*
 * DC_MOTOR_Program.c
 *
 * Created: 4/15/2025 1:36:18 AM
 *  Author: Eman Orabi
 */ 

#include "DIO_Interface.h"
#include "TIMER_Private.h"

// PWM Initialization
void PWM_init() {
	
	DIO_SetPinDirection(PORT_C,PIN4,PIN_OUTPUT); //Output pins OCR1B (PD4)
	DIO_SetPinDirection(PORT_C,PIN5,PIN_OUTPUT); //Output pins OCR1A (PD5)
	
	// Fast PWM Mode 14, Non-inverting
	TTCR1A = (1 << TTCR1A_COM1A1) | (1 << TTCR1A_COM1B1) | (1 << TTCR1A_WGM11);
	TTCR1B = (1 << TTCR1B_WGM12) | (1 << TTCR1B_WGM13) | (1 << TTCR1B_CS11);  // Prescaler = 8

	ICR1 = 255;  // PWM 8-bit
}

// Direction control via L298N (Connected to PORTC)

void Motor_init() {
	DIO_SetPinDirection(PORT_C,PIN0,PIN_OUTPUT); //Output pins IN1 (PC0)
	DIO_SetPinDirection(PORT_C,PIN1,PIN_OUTPUT); //Output pins IN2 (PC1)
	DIO_SetPinDirection(PORT_C,PIN2,PIN_OUTPUT); //Output pins IN3 (PC2)
	DIO_SetPinDirection(PORT_C,PIN3,PIN_OUTPUT); //Output pins IN4 (PC3)
}

void MoveForward() {
	OCR1A=191;   // Left
	OCR1B=191;   // Right
	
	DIO_SetPinValue(PORT_C,PIN0,PIN_HIGH);
	DIO_SetPinValue(PORT_C,PIN2,PIN_HIGH);
	DIO_SetPinValue(PORT_C,PIN1,PIN_LOW);
	DIO_SetPinValue(PORT_C,PIN3,PIN_LOW);
}

void MoveBackward() {
	OCR1A=191;
	OCR1B=191;

	DIO_SetPinValue(PORT_C,PIN1,PIN_HIGH);
	DIO_SetPinValue(PORT_C,PIN3,PIN_HIGH);
	DIO_SetPinValue(PORT_C,PIN0,PIN_LOW);
	DIO_SetPinValue(PORT_C,PIN2,PIN_LOW);
}

void MoveRight() {
	OCR1A=191;
	OCR1B=0;

	DIO_SetPinValue(PORT_C,PIN0,PIN_HIGH);  // Left Motor Forward
	DIO_SetPinValue(PORT_C,PIN1,PIN_LOW);
	DIO_SetPinValue(PORT_C,PIN2,PIN_LOW);  // Right Motor Stop
	DIO_SetPinValue(PORT_C,PIN3,PIN_LOW);

}

void MoveLeft() {
	OCR1A=0;
	OCR1B=191;
	
	DIO_SetPinValue(PORT_C,PIN2,PIN_HIGH);  // Right Motor Forward
	DIO_SetPinValue(PORT_C,PIN3,PIN_LOW);
	DIO_SetPinValue(PORT_C,PIN0,PIN_LOW);  // Left Motor Stop
	DIO_SetPinValue(PORT_C,PIN1,PIN_LOW);
}

void Stop() {
	OCR1A=0;
	OCR1B=0;
	// All motors stop
	DIO_SetPinValue(PORT_C,PIN0,PIN_LOW);
	DIO_SetPinValue(PORT_C,PIN1,PIN_LOW);
	DIO_SetPinValue(PORT_C,PIN2,PIN_LOW);
	DIO_SetPinValue(PORT_C,PIN3,PIN_LOW);
}



