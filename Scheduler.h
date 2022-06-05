/*
 * Scheduler.h
 *
 *  Created on: Apr 24, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef DRIVERS_SCHEDULER_H_
#define DRIVERS_SCHEDULER_H_


typedef struct {
    void (*procedure)(void);
    u16 first_delay;
    u16 period;
    u8 state;
} Scheduler_strtTaskType;

enum{
    SCHEDULER_TASK_INACTIVE,
    SCHEDULER_TASK_ACTIVE,
};

/*
* the following enum type definition is used
 	as a returned error status from every 
	function
*/
typedef enum{
    Scheduler_enuOK,
    Scheduler_enuNullPointerError,
    Scheduler_enuInvalidPriorityError,
} Scheduler_tenuErrorStatus;

/*
* the following function is used to initialize the 
	Scheduler using the configured options
* Args:         None
* Return:       None
* example:
		Scheduler_vidInit();
*/
extern void Scheduler_vidInit(void);

/*
* the following function is used to start the 
	Scheduler operation
* Args:         None
* Return:       None
* example:
		Scheduler_vidStart();
*/
extern void Scheduler_vidStart(void);

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
Scheduler_tenuErrorStatus Scheduler_enuRegisterTask(Scheduler_strtTaskType* Copy_pstrTask, u8 Copy_u8Priority);

#endif /* DRIVERS_SCHEDULER_H_ */
