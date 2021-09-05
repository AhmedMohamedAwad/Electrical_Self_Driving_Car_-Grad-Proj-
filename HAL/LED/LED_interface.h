/*
 * LED_interface.h
 *
 *  Created on: Jul 6, 2021
 *      Author: ahmed
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "LED_config.h"
#include "LED_private.h"

void LED_voidInit(void);
void LED_voidFlashON(void);
void LED_voidFlashOFF(void);
void LED_voidOFF_All(void);

void LED_voidON_ONE(u8 Copy_u8LED);
void LED_voidOFF_ONE(u8 Copy_u8LED);

#endif /* HAL_LED_LED_INTERFACE_H_ */
