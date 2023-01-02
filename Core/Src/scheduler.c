/*
 * scheduler.c
 *
 *  Created on: Dec 31, 2022
 *      Author: Minh Duc Quach
 */

#include "scheduler.h"

/******** STRUCT & LIST IMPLEMENTATION ********/

#define	SCH_MAX_TASKS	10

//char str[50];

typedef struct {
	void 		(*pTask)(void);
	uint32_t 	delay;
	uint32_t 	period;
	uint8_t 	runFlag;
	uint32_t 	taskID;
} Task;

Task taskQueue[SCH_MAX_TASKS + 1];

uint32_t queueSize = 0;

void initQueue(){
	Task newEle;
	newEle.pTask = NULL;
	newEle.delay = 0;
	newEle.period = 0;
	newEle.runFlag = 0;
	newEle.taskID = 0;
	for (uint32_t i = 0; i < SCH_MAX_TASKS; i++){
		taskQueue[i] = newEle;
	}
}

uint32_t findPos(uint32_t id){
	for (uint32_t i = 0; i < SCH_MAX_TASKS; i++){
		if (taskQueue[i].taskID == id) return i;
	}
	return -1;
}

uint32_t removeElement(uint32_t pos){
	if (queueSize == 0) return -1;
	for (uint32_t i = pos; i < SCH_MAX_TASKS - 1; i++){
		taskQueue[i] = taskQueue[i+1];
	}
	queueSize--;
	return 0;
}

uint32_t removeFront(){
	if (queueSize == 0) return -1;
	for (uint32_t i = 0; i < SCH_MAX_TASKS - 1; i++){
		taskQueue[i] = taskQueue[i+1];
	}
	queueSize--;
	return 0;
}

uint32_t addElement(Task ele){
	if (queueSize == SCH_MAX_TASKS) return -1;
	else {
		uint32_t pos;
		uint32_t accumDelay = 0;
		for (pos = 0; pos < SCH_MAX_TASKS; pos++){
			if (taskQueue[pos].pTask == NULL) break;
			if (taskQueue[pos].delay + accumDelay > ele.delay) break;
			else {
				accumDelay += taskQueue[pos].delay;
			}
		}
		ele.delay -= accumDelay;
		for (uint32_t i = SCH_MAX_TASKS - 1; i > pos; i--){
			taskQueue[i] = taskQueue[i-1];
		}
		taskQueue[pos] = ele;
		if (pos + 1 != SCH_MAX_TASKS && taskQueue[pos + 1].pTask != NULL) taskQueue[pos + 1].delay -= ele.delay;
		queueSize++;
		return 0;
	}
}

/**********************************************/

/********** SCHEDULER IMPLEMENTATION **********/

void SCH_Init(){
	initQueue();
}

uint32_t SCH_Add_Task(void(*pFunction)(), uint32_t delay, uint32_t period){
	Task newEle;
	newEle.pTask = pFunction;
	newEle.delay = delay;
	newEle.period = period;
	newEle.runFlag = 0;
	newEle.taskID = (uint32_t) pFunction;

	return addElement(newEle);
}


uint32_t SCH_Delete_Task(uint32_t taskID){
	uint32_t pos = findPos(taskID);
	return removeElement(pos);
}

void SCH_Update(){
	if (queueSize != 0){
		if (taskQueue[0].delay > 0){
			taskQueue[0].delay--;
		}
		else {
			taskQueue[0].runFlag = 1;
			if (taskQueue[0].period != 0){
				taskQueue[0].delay = taskQueue[0].period;
			}
		}
	}
}

void SCH_Dispatch_Tasks(){
	for (uint32_t i = 0; i < SCH_MAX_TASKS; i++){
		if (taskQueue[i].runFlag > 0){
			(*taskQueue[i].pTask)();
			taskQueue[i].runFlag -= 1;
			Task current = taskQueue[i];
			removeFront();
			if (current.period != 0){
				uint32_t add = addElement(current);
			}
		}
	}
}
/**********************************************/
