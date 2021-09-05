#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/USART/USART_interface.h"

#include "util/delay.h"

#include "RGB_interface.h"

void RGB_voidInit(void) {
	DIO_enumSetPinDirection(RGB_Port, RGB_R_Pin, DIO_OUTPUT);
	DIO_enumSetPinDirection(RGB_Port, RGB_G_Pin, DIO_OUTPUT);
	DIO_enumSetPinDirection(RGB_Port, RGB_B_Pin, DIO_OUTPUT);

	DIO_enumSetPinValue(RGB_Port, RGB_R_Pin, DIO_LOW);
	DIO_enumSetPinValue(RGB_Port, RGB_G_Pin, DIO_LOW);
	DIO_enumSetPinValue(RGB_Port, RGB_B_Pin, DIO_LOW);
}


void RGB_voidRGB_ON(u8 Copy_u8R, u8 Copy_u8G, u8 Copy_u8B) {

	DIO_enumSetPinValue(RGB_Port, RGB_R_Pin, Copy_u8R);
	DIO_enumSetPinValue(RGB_Port, RGB_G_Pin, Copy_u8G);
	DIO_enumSetPinValue(RGB_Port, RGB_B_Pin, Copy_u8B);

}

void RGB_voidRGB_OFF(void) {

	DIO_enumSetPinValue(RGB_Port, RGB_R_Pin, DIO_LOW);
	DIO_enumSetPinValue(RGB_Port, RGB_G_Pin, DIO_LOW);
	DIO_enumSetPinValue(RGB_Port, RGB_B_Pin, DIO_LOW);

}


void RGB_Balnking(void)
{
	RGB_voidRGB_ON(RGB_R_HIGH, RGB_G_LOW, RGB_B_LOW);
	_delay_ms(500);

	RGB_voidRGB_ON(RGB_R_LOW, RGB_G_HIGH, RGB_B_LOW);
	_delay_ms(500);

	RGB_voidRGB_ON(RGB_R_LOW, RGB_G_LOW, RGB_B_HIGH);
	_delay_ms(500);

	RGB_voidRGB_ON(RGB_R_LOW, RGB_G_LOW, RGB_B_LOW);
	_delay_ms(500);
}
