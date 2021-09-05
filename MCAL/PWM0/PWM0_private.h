/*
 * PWM0_private.h
 *
 *  Created on: Apr 4, 2021
 *      Author: ahmed
 */

#ifndef MCAL_PWM0_PWM0_PRIVATE_H_
#define MCAL_PWM0_PWM0_PRIVATE_H_

#define TCCR0	*((volatile u8 *) 0x53)
#define TCNT0	*((volatile u8 *) 0x52)
#define OCR0	*((volatile u8 *) 0x5C)
#define TIMSK	*((volatile u8 *) 0x59)
#define TIFR	*((volatile u8 *) 0x58)

#endif /* MCAL_PWM0_PWM0_PRIVATE_H_ */
