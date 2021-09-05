/*
 * USART_program.c
 *
 *  Created on: Apr 9, 2021
 *      Author: ahmed
 */

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "USART_interface.h"

/*
 *
 * Tx, Rx : Enable
 * 9600 BaudRate
 * 1 Stop Bit
 * No parity
 * Data Size 8 Bits
 * Asynch
 *
 */
void USART_voidInit(void) {
	/* Rx Pin D0*/
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_INPUT);

	/* Tx Pin D1*/
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_OUTPUT);

	/* Claer All Flags */
	UCSRA = 0b00000000;

	/* Close All INT, EN TX & RX, Char size 8 Bit ,using 8 Bits only */
	UCSRB = 0b00011000;

	/* EN for Write, Asynchronous, Disable Parity, 1 Stop Bit, 8 Bit Size of Char */
	UCSRC = 0b10000110;

	/*For Baud Rate Need 51 @ UBRRL & H*/
	UBRRLL = 51;
	UBRRLH = 0;

}

u8 USART_u8Received(void) {

	/*Check if Received Data, Wait until Received*/
	while (GET_BIT(UCSRA , 7) == 0)
		;
	return UDR;

}

/*
 u8 x ;
 u8 * StringData =&x;

 u8 * USART_u8ptrReceivedString(void) {

 u8 Iterator = 0;
 u8 c = 0;

 while ( (c = USART_u8Received()) != 13) {
 StringData[Iterator] = c;
 Iterator++;
 }
 StringData[Iterator] = '\0';
 return StringData;
 }
 */

u8 StringData[Length_String];

u8 * USART_u8ptrReceivedString(void) {

	u8 Iterator = 0;
	u8 x = 0;

	/*Check until user Perss Enter Key */
	 /* 13 ---> ASCII For Enter Key */
	while ((x = USART_u8Received()) != 13) {

		/*Save RX Data in StringData Array*/

		StringData[Iterator] = x;
		Iterator++;
	}

	/*array of char end with Null */
	StringData[Iterator] = '\0';
	return StringData;
}

void USART_voidTransmitter(u8 Copy_u8Data) {
	UDR = Copy_u8Data;

	/*Chaeck if Data Send, wait until Sended*/
	while (GET_BIT(UCSRA , 5) == 0)
		;
}

void USART_voidTransmitterString(u8 * Copy_u8ptrString) {
	u8 Iterator = 0;
	while (Copy_u8ptrString[Iterator] != '\0') {
		UDR = Copy_u8ptrString[Iterator];
		while (GET_BIT(UCSRA , 5) == 0)
			;
		Iterator++;
	}
}
