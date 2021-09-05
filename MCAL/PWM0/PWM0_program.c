/*
 * PWM0_program.c
 *
 *  Created on: Apr 4, 2021
 *      Author: ahmed
 */



#include "PWM0_interface.h"
#include "PWM0_private.h"
#include "PWM0_config.h"


void PWM0_voidInit(void)
{
	/*Fast PWM Mode, No Prescaller, Non-Inverted, Clear OC0 @ Compare match & Set @ Top */
	TCCR0 = 0b01101001;

	/*Duty Cycle = 127 */

	OCR0 = 127;


	TCNT0 = 0x0;
	TIFR = 0x0;
	TCNT0 = 0x0;
}

void PWM0_voidSpeed(u8 Copy_u8Speed)
{
	OCR0 = Copy_u8Speed;
}
