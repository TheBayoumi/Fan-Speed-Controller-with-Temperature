/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: Application file for Fan Speed Controller with Temperature(Duty cycle increase proportionally.
 *
 * Author: The Bayoumi
 *
 *******************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "DC_Motor.h"

uint8 map(uint64 x , uint64 inMin , uint64 inMax , uint64 outMin , uint64 outMax){

	return ((x - inMin) * (outMax - outMin) / inMax - inMin) + outMin;
}

int main (void)
{
	uint8 temp,duty;

	ADC_ConfigType Config={INTERNAL,F_CPU8};

	LCD_init(); /* initialize LCD driver */

	ADC_init(&Config); /* initialize ADC driver */

	DcMotor_init();/* initialize DC Motor driver */

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayStringRowColumn(0,1," Temp =   C");

	/* Display this string "Fan is   " only once on LCD at the Second row */
	LCD_displayStringRowColumn(1,1,"Fan");
	while(1)
	{
		temp = LM35_getTemperature();
		duty = map(temp,0,150,0,100);
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

		if (temp >= 0 && temp <30){
			DcMotor_Rotate(Motor_CW,0);
			LCD_displayStringRowColumn(1,5,"OFF");
			LCD_displayStringRowColumn(1,11,"0");
			LCD_displayCharacter('\0');
			LCD_displayStringRowColumn(1,15,"%");
		}
		else if(temp >= 30 && temp < 60){
			DcMotor_Rotate(Motor_CW,duty);
			LCD_displayStringRowColumn(1,5," ON");
			LCD_moveCursor(1,11);
			LCD_intgerToString(duty);
			LCD_displayCharacter('\0');
			LCD_displayStringRowColumn(1,15,"%");
		}
		else if (temp >= 60 && temp < 90){
			DcMotor_Rotate(Motor_CW,duty);
			LCD_displayStringRowColumn(1,5," ON");
			LCD_moveCursor(1,11);
			LCD_intgerToString(duty);
			LCD_displayCharacter('\0');
			LCD_displayStringRowColumn(1,15,"%");
		}
		else if (temp >= 90 && temp < 120 ){
			DcMotor_Rotate(Motor_CW,duty);
			LCD_displayStringRowColumn(1,5," ON");
			LCD_moveCursor(1,11);
			LCD_intgerToString(duty);
			LCD_displayCharacter('\0');
			LCD_displayStringRowColumn(1,15,"%");
		}
		else if (temp >= 120 && temp <= 150 ){
			DcMotor_Rotate(Motor_CW,duty);
			LCD_displayStringRowColumn(1,5," ON");
			LCD_moveCursor(1,11);
			LCD_intgerToString(duty);
			LCD_displayCharacter('\0');
			LCD_displayStringRowColumn(1,15,"%");
		}
	}
}
