/*
 * MOTORS_config.h
 *
 *  Created on: Jun 28, 2021
 *      Author: ahmed
 */

#ifndef HAL_MOTORS_MOTORS_CONFIG_H_
#define HAL_MOTORS_MOTORS_CONFIG_H_

#include "../../MCAL/DIO/DIO_interface.h"

#define MOTOR_FRONT_PORT	DIO_PORTA
#define MOTOR_FRONT_PIN1	DIO_PIN3
#define MOTOR_FRONT_PIN2	DIO_PIN4


#define MOTOR_BACK_PORT		DIO_PORTB
#define MOTOR_BACK_PIN1		DIO_PIN0
#define MOTOR_BACK_PIN2		DIO_PIN1

#define MOTOR_RIGHT			1
#define MOTOR_LEFT			2
#define MOTOR_BREAK			3
#define MOTOR_STOP			0
#define MOTOR_FROWARD		1
#define MOTOR_BACK			2



#endif /* HAL_MOTORS_MOTORS_CONFIG_H_ */
