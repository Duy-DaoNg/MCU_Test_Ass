/*
 * timer.c
 *
 *  Created on: Dec 7, 2022
 *      Author: LENOVO
 */


#include "timer.h"

void setTimer1(int duration){
	timer1Counter = duration/TICK;
	timer1Flag = 0;
}
void setTimer2(int duration){
	timer2Counter = duration/TICK;
	timer2Flag = 0;
}
void setTimer3(int duration){
	timer3Counter = duration/TICK;
	timer3Flag = 0;
}
void setTimer4(int duration){
	timer4Counter = duration/TICK;
	timer4Flag = 0;
}
void setTimer5(int duration){
	timer5Counter = duration/TICK;
	timer5Flag = 0;
}
void timerRun(){
	if(timer1Counter > 0){
		timer1Counter--;
		if(timer1Counter <= 0){
			timer1Flag = 1;
		}
	}
	if(timer2Counter > 0){
		timer2Counter--;
		if(timer2Counter <= 0){
			timer2Flag = 1;
		}
	}
	if(timer3Counter > 0){
		timer3Counter--;
		if(timer3Counter <= 0){
			timer3Flag = 1;
		}
	}
	if(timer4Counter > 0){
		timer4Counter--;
		if(timer4Counter <= 0){
			timer4Flag = 1;
		}
	}
	if(timer5Counter > 0){
		timer5Counter--;
		if(timer5Counter <= 0){
			timer5Flag = 1;
		}
	}
}
