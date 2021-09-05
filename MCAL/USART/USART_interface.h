/*
 * USART_interface.h
 *
 *  Created on: Apr 9, 2021
 *      Author: ahmed
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

#include "USART_private.h"
#include "USART_config.h"

void USART_voidInit (void);
u8 USART_u8Received (void);
u8 *  USART_u8ptrReceivedString(void);
void USART_voidTransmitter (u8 Copy_u8Data);
void USART_voidTransmitterString (u8 * Copy_u8ptrString);



#endif /* MCAL_USART_USART_INTERFACE_H_ */
