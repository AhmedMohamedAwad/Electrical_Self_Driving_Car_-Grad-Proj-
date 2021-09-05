/*
 * MOTORS_interface.h
 *
 *  Created on: Jun 28, 2021
 *      Author: ahmed
 */

#ifndef HAL_MOTORS_MOTORS_INTERFACE_H_
#define HAL_MOTORS_MOTORS_INTERFACE_H_

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "MOTORS_config.h"
#include "MOTORS_private.h"

void MOTORS_voidInit(void);

void MOTOR_FRONT_voidDirection_Speed(u8 Copy_u8Direction, u8 Copy_u8Speed);
void MOTOR_BACK_voidDirection_Speed(u8 Copy_u8Direction, u8 Copy_u8Speed);




#endif /* HAL_MOTORS_MOTORS_INTERFACE_H_ */
