/*
 * COMMANDS_program.c
 *
 *  Created on: Jul 4, 2021
 *      Author: ahmed
 */

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PWM0/PWM0_interface.h"
#include "../../MCAL/PWM2/PWM2_interface.h"
#include "../../MCAL/USART/USART_interface.h"
#include "../../HAL/MOTORS/MOTORS_interface.h"
#include "../../HAL/LED/LED_interface.h"

#include "COMMANDS_interface.h"

u8 Return_Command = '0';
u8 Speed = 0;
u8 Direction = MOTOR_STOP;

u8 COMMANDS_u8Check(u8 * Copy_u8ptrCommandStringRx, u8 Copy_u8Speed) {

	if (Copy_u8ptrCommandStringRx[0] == 'M') {

		/*Check Back MOTOR*/
		if (Copy_u8ptrCommandStringRx[1] == '2') {

			/*Motors Speed Commands*/
			switch (Copy_u8ptrCommandStringRx[2]) {
			case 'V':
					/*Set Speed */
					Speed = Copy_u8ptrCommandStringRx[3];
					USART_voidTransmitterString((u8 *) "M2V-OK\n");
					MOTOR_BACK_voidDirection_Speed(Direction, Speed);
					Return_Command = '9';
					return Return_Command;
				break;

				/*Motors Directions Commands*/
			case 'F':
				USART_voidTransmitterString((u8 *) "M2F-OK\n");
				MOTOR_BACK_voidDirection_Speed(MOTOR_FROWARD, Copy_u8Speed);
				Direction = MOTOR_FROWARD;
				Return_Command = '5';
				return Return_Command;
			case 'B':
				USART_voidTransmitterString((u8 *) "M2B-OK\n");
				MOTOR_BACK_voidDirection_Speed(MOTOR_BACK, Copy_u8Speed);
				Direction = MOTOR_BACK;
				Return_Command = '6';
				return Return_Command;
			case 'S':
				USART_voidTransmitterString((u8 *) "M2S-OK\n");
				MOTOR_BACK_voidDirection_Speed(MOTOR_STOP, 0);
				Return_Command = '7';
				return Return_Command;
			case 'X':
				USART_voidTransmitterString((u8 *) "M2X-OK\n");
				MOTOR_BACK_voidDirection_Speed(MOTOR_BREAK, 255);
				Return_Command = '8';
				return Return_Command;
			default:
				USART_voidTransmitterString((u8 *) "NOT-OK\n");
				Return_Command = '0';
				return Return_Command;
			}

		}

		/*Check Front MOTOR*/
		else if (Copy_u8ptrCommandStringRx[1] == '1') {
			switch (Copy_u8ptrCommandStringRx[2]) {

			case 'R':
				USART_voidTransmitterString((u8 *) "M1R-OK\n");
				MOTOR_FRONT_voidDirection_Speed(MOTOR_RIGHT, Copy_u8Speed);
				Return_Command = '1';
				return Return_Command;

			case 'L':
				USART_voidTransmitterString((u8 *) "M1L-OK\n");
				MOTOR_FRONT_voidDirection_Speed(MOTOR_LEFT, Copy_u8Speed);
				Return_Command = '2';
				return Return_Command;

			case 'S':
				USART_voidTransmitterString((u8 *) "M1S-OK\n");
				MOTOR_FRONT_voidDirection_Speed(MOTOR_STOP, 0);
				Return_Command = '3';
				return Return_Command;

			case 'X':
				USART_voidTransmitterString((u8 *) "M1X-OK\n");
				MOTOR_FRONT_voidDirection_Speed(MOTOR_BREAK, 255);
				Return_Command = '4';
				return Return_Command;

			case 'D':
				if (Copy_u8ptrCommandStringRx[3] == '?') {
					switch (Return_Command) {
					case '1':
						USART_voidTransmitterString((u8 *) "M1D?-R\n");
						break;
					case '2':
						USART_voidTransmitterString((u8 *) "M1D?-L\n");
						break;
					case '3':
						USART_voidTransmitterString((u8 *) "M1D?-S\n");
						break;
					case '4':
						USART_voidTransmitterString((u8 *) "M1D?-X\n");
						break;

					default:
						USART_voidTransmitterString((u8 *) "NOT-OK\n");
						break;
					}
				}
				break;

			default:
				USART_voidTransmitterString((u8 *) "NOT-OK\n");
				Return_Command = '0';
				return Return_Command;

			}
		} else {
			USART_voidTransmitterString((u8 *) "NOT-OK\n");
			Return_Command = '0';
			return Return_Command;
		}
	}

	else if (Copy_u8ptrCommandStringRx[0] == 'C') {
		if (Copy_u8ptrCommandStringRx[1] == 'O') {
			switch (Copy_u8ptrCommandStringRx[2]) {
			case 'F':
				USART_voidTransmitterString((u8 *) "COF-OK\n");
				LED_voidFlashOFF();
				Return_Command = 'A';
				return Return_Command;
				break;
			case 'N':
				USART_voidTransmitterString((u8 *) "CON-OK\n");
				LED_voidFlashON();
				Return_Command = 'B';
				return Return_Command;
				break;
			default:
				USART_voidTransmitterString((u8 *) "NOT-OK\n");
				Return_Command = '0';
				return Return_Command;
				break;
			}

		} else {
			USART_voidTransmitterString((u8 *) "NOT-OK\n");
			Return_Command = '0';
			return Return_Command;
		}
	}


	else if (Copy_u8ptrCommandStringRx[0] == 'L') {
		if (Copy_u8ptrCommandStringRx[1] == 'F') {
			if (Copy_u8ptrCommandStringRx[3] == 'O') {
				switch (Copy_u8ptrCommandStringRx[2]) {
				case 'R':
					LED_voidON_ONE(LED_FRONT_R);
					Return_Command = '0';
					return Return_Command;
					break;
				case 'L':
					LED_voidON_ONE(LED_FRONT_L);
					Return_Command = '0';
					return Return_Command;
					break;
				default:
					USART_voidTransmitterString((u8 *) "NOT-OK\n");
					Return_Command = '0';
					return Return_Command;
					break;
				}
			} else if (Copy_u8ptrCommandStringRx[3] == 'F') {
				switch (Copy_u8ptrCommandStringRx[2]) {
				case 'R':
					LED_voidOFF_ONE(LED_FRONT_R);
					Return_Command = '0';
					return Return_Command;
					break;
				case 'L':
					LED_voidOFF_ONE(LED_FRONT_L);
					Return_Command = '0';
					return Return_Command;
					break;
				default:
					USART_voidTransmitterString((u8 *) "NOT-OK\n");
					Return_Command = '0';
					return Return_Command;
					break;
				}
			}
		}

		else if (Copy_u8ptrCommandStringRx[1] == 'B') {
			if (Copy_u8ptrCommandStringRx[3] == 'O') {
				switch (Copy_u8ptrCommandStringRx[2]) {
				case 'R':
					LED_voidON_ONE(LED_BACK_R);
					Return_Command = '0';
					return Return_Command;
					break;
				case 'L':
					LED_voidON_ONE(LED_BACK_L);
					Return_Command = '0';
					return Return_Command;
					break;
				default:
					USART_voidTransmitterString((u8 *) "NOT-OK\n");
					Return_Command = '0';
					return Return_Command;
					break;
				}
			} else if (Copy_u8ptrCommandStringRx[3] == 'F') {
				switch (Copy_u8ptrCommandStringRx[2]) {
				case 'R':
					LED_voidOFF_ONE(LED_BACK_R);
					Return_Command = '0';
					return Return_Command;
					break;
				case 'L':
					LED_voidOFF_ONE(LED_BACK_L);
					Return_Command = '0';
					return Return_Command;
					break;
				default:
					USART_voidTransmitterString((u8 *) "NOT-OK\n");
					Return_Command = '0';
					return Return_Command;
					break;
				}
			}
		}

		else {
			USART_voidTransmitterString((u8 *) "NOT-OK\n");
			Return_Command = '0';
			return Return_Command;
		}
	} else {
		USART_voidTransmitterString((u8 *) "NOT-OK\n");
		Return_Command = '0';
		return Return_Command;
	}
	USART_voidTransmitterString((u8 *) "NOT-OK\n");
	Return_Command = '0';
	return Return_Command;

}

