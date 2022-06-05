/*
 * Switch.c
 *
 *  Created on: Apr 25, 2022
 *      Author: Ahmed-Yehia
 */

#include "Utils/Std_types.h"

#include "Dio.h"
#include "Switch.h"
#include "Switch_prv.h"
#include "Switch_cfg.h"


static Switch_enutState Switch_au8SwitchState[Switch_count];

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
void Switch_vidGetState(u8 Copy_u8Switch, pu8 Copy_pu8State)
{
    if (Switch_au8SwitchState[Copy_u8Switch] == Switch_enuNotPressed || Switch_au8SwitchState[Copy_u8Switch] == Switch_enuPrePressed)
    {
        *Copy_pu8State = 0; 
    }
    else
    {
        *Copy_pu8State = 1;
    }
}

/*
* the following function is by the scheduler to 
    update the state of every switch configured
    (every 20ms)
    note: IT CANNOT BE CALLED BY THE USER 
* Args:         None
* Return:       None
* example:
		------
*/
void Switch_vidTask(void)
{
    u8 Loc_u8State;
    for (u8 Loc_u8Index = 0; Loc_u8Index < Switch_count; Loc_u8Index++)
    {
        Dio_enuReadChannel(Switch_au8PinConfig[Loc_u8Index], &Loc_u8State);
        switch (Switch_au8SwitchState[Loc_u8Index])
        {
        case Switch_enuNotPressed:
            if (Loc_u8State == 0)
            {
                Switch_au8SwitchState[Loc_u8Index] = Switch_enuNotPressed;
            }
            else
            {
                Switch_au8SwitchState[Loc_u8Index] = Switch_enuPrePressed;
            }
            break;

        case Switch_enuPrePressed:
            if (Loc_u8State == 0)
            {
                Switch_au8SwitchState[Loc_u8Index] = Switch_enuNotPressed;
            }
            else
            {
                Switch_au8SwitchState[Loc_u8Index] = Switch_enuPressed;
            }
            break;
            
        case Switch_enuPressed:
            if (Loc_u8State == 0)
            {
                Switch_au8SwitchState[Loc_u8Index] = Switch_enuPostPressed;
            }
            else
            {
                Switch_au8SwitchState[Loc_u8Index] = Switch_enuPressed;
            }
            break;
        case Switch_enuPostPressed:
            if (Loc_u8State == 0)
            {
                Switch_au8SwitchState[Loc_u8Index] = Switch_enuNotPressed;
            }
            else
            {
                Switch_au8SwitchState[Loc_u8Index] = Switch_enuPressed;
            }
            break;
        }
    }
}
