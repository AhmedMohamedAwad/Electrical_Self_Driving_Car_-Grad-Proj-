/*
 * main.c
 *
 *  Created on: Feb 10, 2021
 *      Author: ahmed
 */

#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/PWM0/PWM0_interface.h"
#include "../MCAL/PWM2/PWM2_interface.h"
#include "../HAL/MOTORS/MOTORS_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/RGB/RGB_interface.h"
#include "COMMANDS/COMMANDS_interface.h"

#include <util/delay.h>

int main(void) {

	USART_voidInit();
	PWM0_voidInit();
	PWM2_voidInit();
	MOTORS_voidInit();
	LED_voidInit();
	RGB_voidInit();


	RGB_Balnking();

	u8 * DataStringRx = USART_u8ptrReceivedString();
	/*
	 while (1) {

	 DataStringRx = USART_u8ptrReceivedString();
	 //	CLCD_voidSetPosition(1, 1);
	 //	CLCD_voidSendString(DataStringRx);
	 if (DataStringRx[4] == 'd') {
	 DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);
	 DIO_enumSetPinValue(DIO_PORTD, DIO_PIN7, DIO_HIGH);
	 }

	 */
	u8 x = 0;
	while (1) {
		//LED_voidON_ONE(LED_FRONT_L);
		DataStringRx = USART_u8ptrReceivedString();
		x = COMMANDS_u8Check((u8 *) DataStringRx, 20);

	}

	return 0;

}
