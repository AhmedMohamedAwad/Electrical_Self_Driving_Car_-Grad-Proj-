/*
 * PWM2_private.h
 *
 *  Created on: Jun 28, 2021
 *      Author: ahmed
 */

#ifndef MCAL_PWM2_PWM2_PRIVATE_H_
#define MCAL_PWM2_PWM2_PRIVATE_H_

#define TCCR2	*((volatile u8 *) 0x45)
#define TCNT2	*((volatile u8 *) 0x44)
#define OCR2	*((volatile u8 *) 0x43)


#endif /* MCAL_PWM2_PWM2_PRIVATE_H_ */
