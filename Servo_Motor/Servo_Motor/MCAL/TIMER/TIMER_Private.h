/*
 * TIMER0_Private.h
 *
 * Created: 1/29/2025 1:33:52 PM
 *  Author: Eman Orabi
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#include "STD_TYPES.h"

//Timer0
#define TCCR0       *((volatile  u8*) 0x53)
#define TCNT0       *((volatile  u8*) 0x52)
#define OCR0        *((volatile  u8*) 0x5C)
#define TIMSK       *((volatile  u8*) 0x59)
#define TIFR        *((volatile  u8*) 0x58)
// Timer1

#define TTCR1A       *((volatile  u8*) 0x4F)

#define TTCR1A_COM1A1    7
#define TTCR1A_COM1B1    5
#define TTCR1A_WGM11     1

#define TTCR1B       *((volatile  u8*) 0x4E)

#define TTCR1B_WGM12     3
#define TTCR1B_WGM13     4
#define TTCR1B_CS11      1

#define OCR1A       *((volatile  u16*) 0x4B)
#define OCR1B       *((volatile  u16*) 0x49)
#define ICR1		*((volatile  u16*) 0x47)



#endif /* TIMER0_PRIVATE_H_ */