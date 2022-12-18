/*
 * buzzer.c
 *
 *  Created on: Dec 18, 2022
 *      Author: Minh Duc Quach
 */

#include "buzzer.h"

void FSM_Buzzer(){
	/* If Pedestrian button is pressed */
	if(FSM_Pedestrian_State == WORK && FSM_Traffic_Light_State_Row == AUTO_RED){
		switch (FSM_Buzzer_State){
		case ON:
			/* Turn on Buzzer */
			if(timer4Flag == 1){
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, Increase_Duty_Cycle);
				Increase_Duty_Cycle += 50;
				if(Increase_Duty_Cycle >= 999){
					Increase_Duty_Cycle = 989;
				}
				FSM_Buzzer_State = OFF;
				/* Set time on */
				setTimer4(DURATION_ON_TIME * TICK);
			}
			break;
		case OFF:
			/* Turn off Buzzer */
			if(timer4Flag == 1){
				FSM_Buzzer_State = ON;
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
				if(red_time*TICK*100 <= Increase_Speed){
					setTimer4(1*TICK);
					break;
				}
				Increase_Speed += 4;
				/* Set time off */
				setTimer4(red_time*TICK*100/Increase_Speed);
			}
			break;
		default:
			break;
		}
	}
	else if(FSM_Pedestrian_State == WORK && FSM_Traffic_Light_State_Row != AUTO_RED){
		/* Reset all */
		Increase_Duty_Cycle = 99;
		Increase_Speed = red_time;
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	}
	else{
		Increase_Duty_Cycle = 99;
		Increase_Speed = red_time;
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	}
}
