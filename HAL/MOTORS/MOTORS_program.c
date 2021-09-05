/*
 * MOTORS_program.c
 *
 *  Created on: Jun 28, 2021
 *      Author: ahmed
 */

/*
 *
 * MOTOR_FRONT:	 PWM0 --> B3 , - + ---> B0, B1
 * MOTOR_BACK: 	 PWM2 --> D7 , - + ---> B4, B5
 *
 */

#include "MOTORS_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include  "../../MCAL/PWM0/PWM0_interface.h"
#include  "../../MCAL/PWM2/PWM2_interface.h"
#include "../../HAL/LED/LED_interface.h"


void MOTORS_voidInit(void) {

	/* Set Ports for Motors ---> O/P & LOW */
	DIO_enumSetPinDirection(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN1, DIO_OUTPUT);
	DIO_enumSetPinDirection(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN2, DIO_OUTPUT);

	DIO_enumSetPinDirection(MOTOR_BACK_PORT, MOTOR_BACK_PIN1, DIO_OUTPUT);
	DIO_enumSetPinDirection(MOTOR_BACK_PORT, MOTOR_BACK_PIN2, DIO_OUTPUT);

	DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN1, DIO_LOW);
	DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN2, DIO_LOW);

	DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN1, DIO_LOW);
	DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN1, DIO_LOW);

	/* Set PWM for Front Motor : DC 50%*/
	PWM2_voidInit();
	PWM2_voidSpeed(0);

	/* Set PWM for Back Motor : DC 50%*/
	PWM0_voidInit();
	PWM0_voidSpeed(0);

	/* Set Pins of PWM O/P */
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);

	/* Set Pins For LEDs */
	DIO_enumSetPinDirection(LED_PORT, LED_FRONT_R, DIO_OUTPUT);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_HIGH);
	DIO_enumSetPinDirection(LED_PORT, LED_FRONT_L, DIO_OUTPUT);
	DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_HIGH);
	DIO_enumSetPinDirection(LED_PORT, LED_BACK_R, DIO_OUTPUT);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
	DIO_enumSetPinDirection(LED_PORT, LED_BACK_L, DIO_OUTPUT);
	DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);
}

void MOTOR_FRONT_voidDirection_Speed(u8 Copy_u8Direction, u8 Copy_u8Speed) {

	switch (Copy_u8Direction) {
	case MOTOR_STOP:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);

		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN1, DIO_LOW);
		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN2, DIO_LOW);
		PWM2_voidSpeed(0);
		break;

	case MOTOR_RIGHT:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_HIGH);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);

		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN1, DIO_HIGH);
		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN2, DIO_LOW);
		PWM2_voidSpeed(Copy_u8Speed);
		break;

	case MOTOR_LEFT:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_HIGH);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);

		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN1, DIO_LOW);
		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN2, DIO_HIGH);
		PWM2_voidSpeed(Copy_u8Speed);
		break;

	case MOTOR_BREAK:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);

		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN1, DIO_HIGH);
		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN2, DIO_HIGH);
		PWM2_voidSpeed(255);
		break;

	default:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);

		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN1, DIO_LOW);
		DIO_enumSetPinValue(MOTOR_FRONT_PORT, MOTOR_FRONT_PIN2, DIO_LOW);
		PWM2_voidSpeed(0);
		break;

	}

}

void MOTOR_BACK_voidDirection_Speed(u8 Copy_u8Direction, u8 Copy_u8Speed) {
	switch (Copy_u8Direction) {
	case MOTOR_STOP:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);

		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN1, DIO_LOW);
		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN2, DIO_LOW);
		PWM0_voidSpeed(0);
		break;

	case MOTOR_FROWARD:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_HIGH);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_HIGH);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);

		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN1, DIO_HIGH);
		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN2, DIO_LOW);
		PWM0_voidSpeed(Copy_u8Speed);
		break;

	case MOTOR_BACK:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);

		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN1, DIO_LOW);
		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN2, DIO_HIGH);
		PWM0_voidSpeed(Copy_u8Speed);
		break;

	case MOTOR_BREAK:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_HIGH);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_HIGH);

		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN1, DIO_HIGH);
		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN2, DIO_HIGH);
		PWM0_voidSpeed(255);
		break;

	default:
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_FRONT_L, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_R, DIO_LOW);
		DIO_enumSetPinValue(LED_PORT, LED_BACK_L, DIO_LOW);
		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN1, DIO_LOW);
		DIO_enumSetPinValue(MOTOR_BACK_PORT, MOTOR_BACK_PIN2, DIO_LOW);
		PWM0_voidSpeed(0);
		break;

	}
}
