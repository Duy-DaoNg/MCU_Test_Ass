/*
 * buzzer.c
 *
 *  Created on: Dec 18, 2022
 *      Author: Minh Duc Quach
 */

#include "buzzer.h"

void FSM_Buzzer(){
	/* If Pedestrian button is pressed and the pedestrian is allowed to cross the road */
	if(FSM_Pedestrian_State == WORK && FSM_Traffic_Light_State_Row == AUTO_RED){
		switch (FSM_Buzzer_State){
		case ON:
			/* Turn on Buzzer */
			if(timer4Flag == 1){
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, Increase_Duty_Cycle);		// set buzzer volume
				Increase_Duty_Cycle += 50;
				if(Increase_Duty_Cycle >= 999){											// 999 is the maximum period
					Increase_Duty_Cycle = 989;
				}
				FSM_Buzzer_State = OFF;
				/* The buzzer is ON for DURATION_ON_TIME * TICK ms */
				setTimer4(DURATION_ON_TIME * TICK);
			}
			break;
		case OFF:
			if(timer4Flag == 1){
				FSM_Buzzer_State = ON;
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);						// turn off buzzer
				/* If the OFF duration is small enough, stop decreasing OFF duration and keep it at TICK ms */
				if(red_time*TICK*100 <= Increase_Speed){
					setTimer4(1*TICK);
					break;
				}
				Increase_Speed += 4;
				/* Increase the beeping frequency by decreasing buzzer's OFF duration */
				setTimer4(red_time*TICK*100/Increase_Speed);
			}
			break;
		default:
			break;
		}
	}
	/* If Pedestrian button is pressed and the pedestrian is not allowed to cross the road */
	else if(FSM_Pedestrian_State == WORK && FSM_Traffic_Light_State_Row != AUTO_RED){
		/* Reset all */
		Increase_Duty_Cycle = 99;		// initial volume
		Increase_Speed = red_time;
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	}
	/* Other cases */
	else{
		Increase_Duty_Cycle = 99;		// initial volume
		Increase_Speed = red_time;
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	}
}
