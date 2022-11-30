/*
 * scheduler.c
 *
 *  Created on: Nov 13, 2022
 *      Author: tamqu
 */

#include "scheduler.h"
#include "main.h"

uint8_t SCH_Delete_Task(uint32_t taskID) {
	if (taskID < 0 || taskID >= SCH_MAX_TASKS) return 0;
	SCH_tasks_G[taskID].pTask = 0x0000;
	SCH_tasks_G[taskID].Delay = 0;
	SCH_tasks_G[taskID].Period =  0;
	SCH_tasks_G[taskID].RunMe = 0;

	numberOfCurrentTasks--;

	return 1;
}

void SCH_Init(void){
	unsigned char i;
	for (i; i<SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i); //to make sure
	}
	current_index_task = 0;
}

uint32_t SCH_Add_Task( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	uint32_t index = 0;
	while(SCH_tasks_G[index].pTask != 0x0000 && index < SCH_MAX_TASKS){
		index++;
	}
	if(index == SCH_MAX_TASKS) return -1;

	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = DELAY;
	SCH_tasks_G[index].Period = PERIOD;
	SCH_tasks_G[index].RunMe = 0;
	return index;
}

void SCH_Update(void){
	unsigned char index;
	for(index=0; index<SCH_MAX_TASKS; index++){
		if(SCH_tasks_G[index].pTask != 0x0000){
			if(SCH_tasks_G[index].Delay == 0){
				SCH_tasks_G[index].RunMe = 1;
				if(SCH_tasks_G[index].Period > 0){
					SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
				}
			} else {
				SCH_tasks_G[index].Delay--;
			}
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			//if this is a one-shot task, then remove it from they array
			if (SCH_tasks_G[i].Period == 0) {
				SCH_Delete_Task(i);
			}
		}
	}
}


