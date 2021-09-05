/*
 * PWM2_program.c
 *
 *  Created on: Jun 28, 2021
 *      Author: ahmed
 */

#include "PWM2_interface.h"

void PWM2_voidInit(void)
{
	/*Fast PWM Mode, No Prescaller, Non-Inverted */
	TCCR2 = 0b01101001;

	/*Duty Cycle = 127 */
	OCR2 = 127;


	TCNT2 = 0x0;

}

void PWM2_voidSpeed(u8 Copy_u8Speed)
{
	OCR2 = Copy_u8Speed;
}
