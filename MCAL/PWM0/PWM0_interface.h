/*
 * PWM0_interface.h
 *
 *  Created on: Apr 4, 2021
 *      Author: ahmed
 */

#ifndef MCAL_PWM0_PWM0_INTERFACE_H_
#define MCAL_PWM0_PWM0_INTERFACE_H_

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "PWM0_config.h"
#include "PWM0_private.h"

void PWM0_voidInit(void);
void PWM0_voidSpeed(u8 Copy_u8Speed);

#endif /* MCAL_PWM0_PWM0_INTERFACE_H_ */
