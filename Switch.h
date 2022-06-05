/*
 * Switch.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef DRIVERS_SWITCH_H_
#define DRIVERS_SWITCH_H_

#include "Switch_cfg.h" // in order to use user created switch names


extern const u8 Switch_au8PinConfig[];

/*
* the following function is used to get the 
	state of a specific switch
* Args:         Copy_u8Switch:  switch identifier
                Copy_pu8State:  pointer to a variable
                    to store the retrieved state
* Return:       None
* example:
        u8 state;
		Switch_vidGetState(Switch_right_switch, &state);
*/
extern void Switch_vidGetState(u8 Copy_u8Switch, pu8 Copy_pu8State);

/*
* the following function is by the scheduler to 
    update the state of every switch configured
    note: IT CANNOT BE CALLED BY THE USER 
* Args:         None
* Return:       None
* example:
		------
*/
void Switch_vidTask(void);

#endif /* DRIVERS_SWITCH_H_ */
