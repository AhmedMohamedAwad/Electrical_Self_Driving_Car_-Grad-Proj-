/*
 * Pins_Connections.h
 *
 *  Created on: Jun 29, 2021
 *      Author: ahmed
 */

Pins :
/*
Port A:


Port B:

B0,1	---> Legs Motor_Front
B3		---> PWM Motor_Front
B4,5	---> Legs Motor_Back


Port C:

C0 		---> Motor_Front_Led_R
C1		---> Motor_Front_Led_L
C2 		---> Motor_Back_Led_R
C3		---> Motor_Back_Led_L


Port D:

D0		---> Rx UART
D1		---> Tx UART

D7		---> PWM Motor_Back


*/

MOTORs:

/*
 * Front:
 * B0,1	---> Legs Motor_Front
 * B3	---> PWM Motor_Front
 * 
 * BACK:
 * B4,5	---> Legs Motor_Back
 * D7		---> PWM Motor_Back
 * 
 */

MOTORs_LEDs:

/*
 * Front:
 * C0	---> LED_Front_R
 * C1	---> LED_Front_L
 * 
 * BACK:
 * C2	---> LED_Back_R
 * C3	---> LED_Back_L
 * 
 */
 
 
UART:

/*
 * 
 * 9600 BaudRate
 * 1 Stop Bit
 * No parity
 * Data Size 8 Bits
 * Async
 * 
 */