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

void PWM_Timer0_Init(uint8 set_duty_cycle);

#endif /* TIMER_H_ */
