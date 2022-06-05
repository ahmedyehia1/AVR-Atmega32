/*
 * EXT_I.c
 *
 *  Created on: Apr 12, 2022
 *      Author: Ahmed-Yehia
 */

#include "Utils/Bit_utils.h"
#include "Utils/Std_types.h"

#include "EXT_I.h"
#include "EXT_I_prv.h"
#include "EXT_I_cfg.h"


/*
* the following function is used to set
 	the initial configuration of the 
    external interrupt pins 
* Args:		none
* Return:	none
* example:
		EXT_I_vidInit();
*/
void EXT_I_vidInit()
{
    u8 Loc_u8GICR,Loc_u8MCUCR, Loc_u8MCUCSR;

    Loc_u8GICR = GICR;
    Loc_u8GICR &= EXT_I_ENABLE_MASK;
    #ifndef EXT_I_ENABLED_INT
        #define EXT_I_ENABLED_INT       EXT_I_INT_0 & EXT_I_INT_1 & EXT_I_INT_2
        #warning "no external interrupt enable configuration is selected, all interrupts is enabled"
    #endif
    Loc_u8GICR |= ~(EXT_I_ENABLED_INT);
    GICR = Loc_u8GICR;

    Loc_u8MCUCR = MCUCR;
    Loc_u8MCUCSR = MCUCSR;
    #if ((EXT_I_ENABLED_INT) & EXT_I_INT_0) == (EXT_I_ENABLED_INT)   // external interrupt 0 is included
        #ifndef EXT_I_INT_0_CTRL
            #define EXT_I_INT_0_CTRL       EXT_I_RISING_EDGE
            #warning "no  detection type for external interrupt 0, rising edge detection is seleceted"
        #endif
        Loc_u8MCUCR &= EXT_I_INT_0_CTRL_MASK;
        Loc_u8MCUCR |= (EXT_I_INT_0_CTRL << EXT_I_INT_0_CTRL_OFFSET);
    #endif
    #if ((EXT_I_ENABLED_INT) & EXT_I_INT_1) == (EXT_I_ENABLED_INT)   // external interrupt 1 is included
        #ifndef EXT_I_INT_1_CTRL
            #define EXT_I_INT_1_CTRL       EXT_I_RISING_EDGE
            #warning "no  detection type for external interrupt 1, rising edge detection is seleceted"
        #endif
        Loc_u8MCUCR &= EXT_I_INT_1_CTRL_MASK;
        Loc_u8MCUCR |= (EXT_I_INT_1_CTRL << EXT_I_INT_1_CTRL_OFFSET);
    #endif
    #if ((EXT_I_ENABLED_INT) & EXT_I_INT_2) == (EXT_I_ENABLED_INT)   // external interrupt 2 is included
        #ifndef EXT_I_INT_2_CTRL
            #define EXT_I_INT_2_CTRL       EXT_I_RISING_EDGE
            #warning "no  detection type for external interrupt 2, rising edge detection is seleceted"
        #endif
        #if EXT_I_INT_2_CTRL == EXT_I_CHANGE_LEVEL ||		\
            EXT_I_INT_2_CTRL == EXT_I_LOW_LEVEL
            #error "external interrupt 2 only supports rising edge and falling edge detection"
        #endif
        Loc_u8MCUCSR &= EXT_I_INT_2_CTRL_MASK;
        Loc_u8MCUCSR |= ((EXT_I_INT_2_CTRL & 0b01) << EXT_I_INT_2_CTRL_OFFSET);
    #endif
    MCUCR = Loc_u8MCUCR;
    MCUCSR = Loc_u8MCUCSR;
}

/*
* the following function is used to change the 
    configured external interrupt control 
    (low/change level in case of INT0, INT1 and
    rising/falling edge in case of any INT)
* Args:		u8 Copy_u8IntId:    external interrupt identifier
                (EXT_I_INT_0, EXT_I_INT_1, EXT_I_INT_2,
                EXT_I_INT_0 & EXT_I_INT_1, .... , 
                EXT_I_INT_0 & EXT_I_INT_1 & EXT_I_INT_2)
	        u8 Copy_u8IntCtrl:  new control value 
                (EXT_I_RISING_EDGE,
                EXT_I_FALLING_EDGE,
                EXT_I_CHANGE_LEVEL,
                EXT_I_LOW_LEVEL)
* Return:   none
* example:
		EXT_I_vidCtrlChange(EXT_I_INT_0 & EXT_I_INT_2, EXT_I_FALLING_EDGE);
*/
void EXT_I_vidCtrlChange(u8 Copy_u8IntId, u8 Copy_u8IntCtrl)
{
    u8 Loc_u8MCUCR, Loc_u8MCUCSR;

    if((Copy_u8IntId & EXT_I_ENABLED_INT) == (EXT_I_ENABLED_INT))   // is a valid interrupt identifier
    {
		Loc_u8MCUCR = MCUCR;
		Loc_u8MCUCSR = MCUCSR;
		if(((Copy_u8IntId >> 6) & 0b01) == 0)   // external interrupt 0 is included
		{
			Loc_u8MCUCR &= EXT_I_INT_0_CTRL_MASK;
			Loc_u8MCUCR |= (Copy_u8IntCtrl << EXT_I_INT_0_CTRL_OFFSET);
		}
		if(((Copy_u8IntId >> 7) & 0b01) == 0)   // external interrupt 1 is included
		{
			Loc_u8MCUCR &= EXT_I_INT_1_CTRL_MASK;
			Loc_u8MCUCR |= (Copy_u8IntCtrl << EXT_I_INT_1_CTRL_OFFSET);
		}
		if(((Copy_u8IntId >> 5) & 0b01) == 0)   // external interrupt 1 is included
		{
			Loc_u8MCUCSR &= EXT_I_INT_2_CTRL_MASK;
			Loc_u8MCUCSR |= ((Copy_u8IntCtrl << EXT_I_INT_2_CTRL_OFFSET) & (~EXT_I_INT_2_CTRL_MASK));
		}
		MCUCR = Loc_u8MCUCR;
		MCUCSR = Loc_u8MCUCSR;
    }
}

/*
* the following function is used to check if 
    the given interrupt is fired or not
* Args:		u8 Copy_u8IntId:    external interrupt identifier
                (EXT_I_INT_0, EXT_I_INT_1, EXT_I_INT_2)
	        pu8 Copy_pu8Flag:  pointer to a variable to 
                read the flag value
* Return:   none
* example:
		u8 Loc_u8Flag;
        void EXT_I_vidIsFired(EXT_I_INT_0, & Loc_u8Flag);
*/
void EXT_I_vidIsFired(u8 Copy_u8IntId, pu8 Copy_pu8Flag)
{
    if (Copy_pu8Flag != NULL)
    {
        if (GIFR & (~Copy_u8IntId))
        {
            *Copy_pu8Flag = 1;
        }
        else
        {
            *Copy_pu8Flag = 0;
        }
    }
}
