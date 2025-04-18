/*
 * ADC_Program.c
 *
 * Created: 1/28/2025 1:18:45 PM
 *  Author: Original
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"



void ADC_Init() {
	ADMUX = (1<<ADMUX_REFS0);
	ADCSRA = (1<<ADCSRA_ADEN)|(1<<ADCSRA_ADPS2)|(1<<ADCSRA_ADPS1);
}

u16 ADC_Read(u8 channel) {
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	ADCSRA |= (1<< ADCSRA_ADSC);
	while(ADCSRA & (1<< ADCSRA_ADSC));
	return ADC_OUTPUT;
}

