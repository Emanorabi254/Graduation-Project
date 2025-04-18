/*
 * UART_Program.c
 *
 * Created: 4/15/2025 1:57:48 AM
 *  Author: Eman Orabi
 */ 

#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "UART_Interface.h"
#include "TIMER_Private.h"

// UART Initialization
void UART_init(u16 baud) {
	u16 ubrr = F_CPU / 16 / baud - 1;
	UBRRH = (u8)(ubrr >> 8);
	UBRRL = (u8)ubrr;
	// Enable receiver and transmitter
	UCSRB = (1 << UCSRB_RXEN) | (1 << UCSRB_TXEN);
	UCSRC = (1 << UCSRC_URSEL) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);  // Set frame format: 8 data bits, 1 stop bit
}

// Send String via UART
void UART_sendString(const u8* data) {
	while (*data) {
		while (!(UCSRA & (1 << UCSRA_UDRE)));  // Wait until buffer is empty
			// Put data into buffer, sends the data
		UDR_InputOutput = *data++;
	}
}

// Show OCR values and movement direction
void ShowingTheValue(u8 movement) {
	u8 buffer[60];
	sprintf(buffer, "[%c] OCR1A: %u , OCR1B: %u \n\n", movement, OCR1A, OCR1B);
	UART_sendString(buffer);
}
u8 UART_Receive(void) {
	// Wait for data to be received
	while (!(UCSRA & (1 << UCSRA_RXC)));
	// Get and return received data from buffer
	return (UDR_InputOutput);
}