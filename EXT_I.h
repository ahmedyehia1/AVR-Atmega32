/*
 * EXT_I.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef DRIVERS_EXT_I_H_
#define DRIVERS_EXT_I_H_

#define EXT_I_INT_0                     0xBF
#define EXT_I_INT_1                     0x7F
#define EXT_I_INT_2                     0xDF

#define EXT_I_RISING_EDGE               0b11
#define EXT_I_FALLING_EDGE              0b10
#define EXT_I_CHANGE_LEVEL              0b01
#define EXT_I_LOW_LEVEL                 0b00

/*
* the following function is used to set
 	the initial configuration of the 
    external interrupt pins 
* Args:		none
* Return:	none
* example:
		EXT_I_vidInit();
*/
void EXT_I_vidInit();

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
void EXT_I_vidCtrlChange(u8 Copy_u8IntId, u8 Copy_u8IntCtrl);

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
void EXT_I_vidIsFired(u8 Copy_u8IntId, pu8 Copy_pu8Flag);

#endif /* DRIVERS_EXT_I_H_ */
