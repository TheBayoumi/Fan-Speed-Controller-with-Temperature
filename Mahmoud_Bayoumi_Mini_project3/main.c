/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: Application file for Fan Speed Controller with Temperature
 *
 * Author: The Bayoumi
 *
 *******************************************************************************/
#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "DC_Motor.h"

int main (void)
{
	uint8 temp;

	ADC_ConfigType Config={INTERNAL,F_CPU8};

	LCD_init(); /* initialize LCD driver */

	ADC_init(&Config); /* initialize ADC driver */

	DcMotor_init(); /* initialize DC Motor driver */

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_moveCursor(0,1);

	LCD_displayString("Temp =    C");

	LCD_moveCursor(0,7);

	/* Display this string "Fan is   " only once on LCD at the Second row */
	LCD_displayStringRowColumn(1,1,"Fan is");

	while(1)
	{
		temp = LM35_getTemperature();
		LCD_moveCursor(0,7);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

			if (temp >= 0 && temp <30)
			{
				DcMotor_Rotate(Motor_CW,0);
				LCD_displayStringRowColumn(1,8,"OFF");
			}
			else if(temp >= 30 && temp < 60)
			{
				DcMotor_Rotate(Motor_CW,25);
				LCD_displayStringRowColumn(1,8,"ON ");
			}
			else if (temp >= 60 && temp < 90)
			{
				DcMotor_Rotate(Motor_CW,50);
				LCD_displayStringRowColumn(1,8,"ON ");
			}
			else if (temp >= 90 && temp < 120 )
			{
				DcMotor_Rotate(Motor_CW,75);
				LCD_displayStringRowColumn(1,8,"ON ");
			}
			else if (temp >= 120 && temp <= 150 )
			{
				DcMotor_Rotate(Motor_CW,100);
				LCD_displayStringRowColumn(1,8,"ON ");
			}
	}
}
