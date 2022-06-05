/*
 * Scheduler.c
 *
 *  Created on: Apr 24, 2022
 *      Author: Ahmed-Yehia
 */

#include "Utils/Std_types.h"

#include "Gpt.h"

#include "Scheduler.h"
#include "Scheduler_prv.h"
#include "Scheduler_cfg.h"

static Scheduler_strtTaskType* Scheduler_apstrTasks[SCHEDULER_TASK_COUNT];

/*
* the following function is registered to the 
    timer callback function 
	note: IT CAN'T BE USED BY THE USER
* Args:         None
* Return:       None
* example:
		--------
*/
void Scheduler_vidSchedule(void);

/*
* the following function is used to initialize the 
	Scheduler using the configured options
* Args:         None
* Return:       None
* example:
		Scheduler_vidInit();
*/
void Scheduler_vidInit(void)
{
    Gpt_ConfigType cfg = {
		.channel = SCHEDULER_GPT_CHANNEL,
		.mode = GPT_MODE_NORMAL,
		.prescaler = GPT_INTERNAL_CLK_PRESCALER_VAL_8,
		.compareOutputMode = GPT_COMPARE_OUTPUT_MODE_OFF,
		.comparators = GPT_COMPARATOR_A
	};
    Gpt_Init(&cfg);
    Gpt_registerNotification(SCHEDULER_GPT_CHANNEL, Scheduler_vidSchedule);
}

/*
* the following function is used to start the 
	Scheduler operation
* Args:         None
* Return:       None
* example:
		Scheduler_vidStart();
*/
void Scheduler_vidStart(void)
{
    Gpt_StartTimer(SCHEDULER_GPT_CHANNEL, SCHEDULER_TASK_TIME_MS);
    while(1);
}

/*
* the following function is used to register new
    tasks to the scheduler and their priorities
* Args:         Copy_strTask:               the task to be scheduled
                Copy_u8Priority:            the task priority
* Return:       Scheduler_tenuErrorStatus:  return status
* example:
        Scheduler_strtTaskType task = {
            .procedure = CBF;
            .first_delay = 5;
            .period = 2;
            .state = SCHEDULER_TASK_ACTIVE;
        }
		Scheduler_enuRegisterTask(task, 0);
*/
Scheduler_tenuErrorStatus Scheduler_enuRegisterTask(Scheduler_strtTaskType* Copy_pstrTask, u8 Copy_u8Priority)
{
    Scheduler_tenuErrorStatus Loc_enuStatus = Scheduler_enuOK;
    if ( Copy_u8Priority >= SCHEDULER_TASK_COUNT)
    {
        Loc_enuStatus = Scheduler_enuInvalidPriorityError;
    }
    else if (Copy_pstrTask == NULL)
    {
        Loc_enuStatus = Scheduler_enuNullPointerError;
    }
    else
    {
        Scheduler_apstrTasks[Copy_u8Priority] = Copy_pstrTask;
    }
    
    return Loc_enuStatus;
}

/*
* the following function is registered to the 
    timer callback function 
	note: IT CAN'T BE USED BY THE USER
* Args:         None
* Return:       None
* example:
		--------
*/
void Scheduler_vidSchedule(void)
{
    for (u8 Loc_u8Index = 0; Loc_u8Index < SCHEDULER_TASK_COUNT; Loc_u8Index++)
    {
        if (Scheduler_apstrTasks[Loc_u8Index] != NULL && Scheduler_apstrTasks[Loc_u8Index]->state == SCHEDULER_TASK_ACTIVE)
        {
            if (Scheduler_apstrTasks[Loc_u8Index]->first_delay == 0)
            {
                Scheduler_apstrTasks[Loc_u8Index]->procedure();
                Scheduler_apstrTasks[Loc_u8Index]->first_delay = Scheduler_apstrTasks[Loc_u8Index]->period;
            }
            Scheduler_apstrTasks[Loc_u8Index]->first_delay--;
        }
    }
}
