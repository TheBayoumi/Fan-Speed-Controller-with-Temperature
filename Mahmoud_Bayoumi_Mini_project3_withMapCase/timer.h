/******************************************************************************
 *
 * Module: Timer
 *
 * File Name: timer.h
 *
 * Description: Header file for the ATmega16 Timer driver
 *
 * Author: The Bayoumi
 *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "gpio.h"
#include <avr/io.h>
#include "std_types.h"
#include "common_macros.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* Configure of EN1 pin */

#define Timer_EN1_PORT_ID             PORTB_ID
#define Timer_EN1_PIN_ID              PIN3_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed be update the value in
 * The Compare Register
 */

void PWM_Timer0_Init(uint8 set_duty_cycle);

#endif /* TIMER_H_ */
