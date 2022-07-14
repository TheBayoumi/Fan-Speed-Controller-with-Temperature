/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DC_Mototr.c
 *
 * Description: Source file for the ATmega16 Motor driver
 *
 * Author: The Bayoumi
 *
 *******************************************************************************/

#include "DC_Motor.h"
#include "Timer.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the DC Motor
 * 1. Setup the DC Motor pins directions by use the GPIO driver.
 * 2. Setup the DC Motor state ( STOP - CLOCKWISE - COUNTER CLOCKWISE)
 */

void DcMotor_init(void)
{
	/* Configure the direction for IN1 and IN2 pins as output pins */
	GPIO_setupPinDirection(DcMotor_IN1_PORT_ID,DcMotor_IN1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DcMotor_IN2_PORT_ID,DcMotor_IN2_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(DcMotor_IN1_PORT_ID,DcMotor_IN1_PIN_ID,LOGIC_LOW);
	GPIO_writePin(DcMotor_IN2_PORT_ID,DcMotor_IN2_PIN_ID,LOGIC_LOW);
}

/*
 * Description :
 * Function responsible for rotate the DC Motor CLOCKWISE or COUNTER CLOCKWISE or STOP the motor based on the state input state value.
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state == Motor_STOP){
		GPIO_writePin(DcMotor_IN1_PORT_ID,DcMotor_IN1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DcMotor_IN2_PORT_ID,DcMotor_IN2_PIN_ID,LOGIC_LOW);
		PWM_Timer0_Init(speed); /* Send the speed to control to duty cycle of PWM driver. */
	}
	else if (state == Motor_CW)
	{
		GPIO_writePin(DcMotor_IN1_PORT_ID,DcMotor_IN1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DcMotor_IN2_PORT_ID,DcMotor_IN2_PIN_ID,LOGIC_HIGH);
		PWM_Timer0_Init(speed); /* Send the speed to control to duty cycle of PWM driver. */
	}
	else if (state == Motor_C_CW)
		{
			GPIO_writePin(DcMotor_IN1_PORT_ID,DcMotor_IN1_PIN_ID,LOGIC_HIGH);
			GPIO_writePin(DcMotor_IN2_PORT_ID,DcMotor_IN2_PIN_ID,LOGIC_LOW);
			PWM_Timer0_Init(speed); /* Send the speed to control to duty cycle of PWM driver. */
		}
}

