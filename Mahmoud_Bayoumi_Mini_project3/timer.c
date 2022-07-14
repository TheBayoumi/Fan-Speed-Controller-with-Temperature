/******************************************************************************
 *
 * Module: Timer
 *
 * File Name: timer.c
 *
 * Description: Source file for the ATmega16 Timer driver
 *
 * Author: The Bayoumi
 *
 *******************************************************************************/

#include "timer.h"

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed be update the value in
 * The Compare Register
 */

void PWM_Timer0_Init(uint8 set_duty_cycle)
{


	TCNT0 = 0; /* Set Timer Initial value = 0 */

	OCR0  = (set_duty_cycle*255)/100; /* Set Compare Value */

	GPIO_setupPinDirection(Timer_EN1_PORT_ID,Timer_EN1_PIN_ID,PIN_OUTPUT); /*set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.*/

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/256 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

