/*
 * UART_Interface.h
 *
 * Created: 4/15/2025 1:57:29 AM
 *  Author: Eman Orabi
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define UBRRH       *((volatile  u8*) 0x40)
#define UBRRL       *((volatile  u8*) 0x29)
#define UCSRA       *((volatile  u8*) 0x2B)

#define UCSRA_UDRE   5
#define UCSRA_RXC    7 

#define UCSRB       *((volatile  u8*) 0x2A)

#define UCSRB_TXEN   3
#define UCSRB_RXEN   4

#define UCSRC       *((volatile  u8*) 0x40)

#define UCSRC_UCSZ0   1
#define UCSRC_UCSZ1   2
#define UCSRC_URSEL   7



#define UDR_InputOutput    *((volatile  u8*) 0x2C)


void UART_init(u16 baud);
void UART_sendString(const u8* str);
void ShowingTheValue(u8 movement);
u8 UART_Receive(void);
void UART_Flush(void);

#endif /* UART_INTERFACE_H_ */