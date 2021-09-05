/*
 * PWM2_interface.h
 *
 *  Created on: Jun 28, 2021
 *      Author: ahmed
 */

#ifndef MCAL_PWM2_PWM2_INTERFACE_H_
#define MCAL_PWM2_PWM2_INTERFACE_H_

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "PWM2_config.h"
#include "PWM2_private.h"

void PWM2_voidInit(void);
void PWM2_voidSpeed(u8 Copy_u8Speed);

#endif /* MCAL_PWM2_PWM2_INTERFACE_H_ */
