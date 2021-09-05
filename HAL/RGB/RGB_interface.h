/*
 * RGB_interface.h
 *
 *  Created on: Jul 8, 2021
 *      Author: ahmed
 */

#ifndef HAL_RGB_RGB_INTERFACE_H_
#define HAL_RGB_RGB_INTERFACE_H_

#include "RGB_private.h"
#include "RGB_config.h"

void RGB_voidInit(void);

void RGB_voidRGB_ON(u8 Copy_u8R, u8 Copy_u8G,u8 Copy_u8B);

void RGB_voidRGB_OFF(void);

void RGB_Balnking(void);

#endif /* HAL_RGB_RGB_INTERFACE_H_ */
