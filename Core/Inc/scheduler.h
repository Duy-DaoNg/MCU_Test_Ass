/*
 * scheduler.h
 *
 *  Created on: Dec 31, 2022
 *      Author: Minh Duc Quach
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdlib.h>
#include <stdint.h>
#include "main.h"
#include "global.h"

void SCH_Init();
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t, uint32_t);
void SCH_Update();
uint32_t SCH_Delete_Task(uint32_t);
void SCH_Dispatch_Tasks();

#endif /* INC_SCHEDULER_H_ */
