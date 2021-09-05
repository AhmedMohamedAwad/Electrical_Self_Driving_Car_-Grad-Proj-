/*
 * LED_program.c
 *
 *  Created on: Jul 6, 2021
 *      Author: ahmed
 */

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "util/delay.h"

#include "LED_interface.h"

void LED_voidInit(void) {
	DIO_enumSetPinDirection(LED_PORT, LED_FRONT_R, DIO_OUTPUT);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);

	DIO_enumSetPinDirection(LED_PORT, LED_FRONT_L, DIO_OUTPUT);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);

	DIO_enumSetPinDirection(LED_PORT, LED_BACK_R, DIO_OUTPUT);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);

	DIO_enumSetPinDirection(LED_PORT, LED_BACK_L, DIO_OUTPUT);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);

}

void LED_voidFlashON(void) {

	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);
	_delay_ms(200);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);
	_delay_ms(200);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);
	_delay_ms(200);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);
}

void LED_voidFlashOFF(void) {
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);
	_delay_ms(200);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);
	_delay_ms(200);

	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);
	_delay_ms(100);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);
	_delay_ms(100);

	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);
	_delay_ms(50);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);
	_delay_ms(50);

}

void LED_voidOFF_All(void) {
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);
}

void LED_voidON_ONE(u8 Copy_u8LED) {
	DIO_enumSetPinValue(LED_PORT, Copy_u8LED, DIO_HIGH);
}

void LED_voidOFF_ONE(u8 Copy_u8LED) {
	DIO_enumSetPinValue(LED_PORT, Copy_u8LED, DIO_LOW);
}
