/*
 * USART_private.h
 *
 *  Created on: Apr 9, 2021
 *      Author: ahmed
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_


#define UCSRA	*((volatile u8 *)0x2B)
#define UCSRB	*((volatile u8 *)0x2A)
#define UCSRC	*((volatile u8 *)0x40)
#define UBRRLH	*((volatile u8 *)0x40)
#define UBRRLL	*((volatile u8 *)0x29)
#define UDR		*((volatile u8 *)0x2C)

#define NULL		0


#endif /* MCAL_USART_USART_PRIVATE_H_ */
