/*
 * Module: mini_project_4
 *
 * File Name: mini_project_4.c
 *
 * Description: Source file for the Main application
 *
 * Created on: Oct 23, 2023
 *
 * Author: Fady Essam
 */

#include "lcd.h"
#include "std_types.h"
#include "ultrasonic.h"
#include <avr/io.h>

/*******************************************************************************
 *                                Main Function                                *
 *******************************************************************************/
int main (void)
{
	/* declare variable to count the distance*/
	uint16 distance;

	/* Initialize both the LCD and ULTRASONIC driver */
	Ultrasonic_init();
	LCD_init();

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	LCD_displayString("Distance = ");

	while(1)
	{
		LCD_moveCursor(0,11);
		distance = Ultrasonic_readDistance();
		if (distance > 99){

			LCD_intgerToString(distance);

		}
		else{
			LCD_intgerToString(distance);
			LCD_displayCharacter(' ');
		}
		LCD_displayString("cm ");

	}
	return 0;

}

