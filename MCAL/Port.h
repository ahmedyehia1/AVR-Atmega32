/*
 * port.h
 *
 *  Created on: Mar 5, 2022
 *      Author: Ahmed Yehia
 */

#ifndef PORT_H_
#define PORT_H_

/*
* the following definitions are used to
	configure the direction of each pin
	usage:
		- Port_enuSetPinDirection(----,Port_u8INPUT)
*/
#define Port_u8INPUT 					0
#define Port_u8OUTPUT 					1

/*
* the following definitions are used to
	configure the direction and the mode 
	of each pin usage:
		- Port_enuSetPinMode(----,Port_u8OUTPUT_LOW)
*/
#define Port_u8INPUT_HIGH_IMP 			1
#define Port_u8INPUT_PULL_UP 			2
#define Port_u8OUTPUT_LOW 				3
#define Port_u8OUTPUT_HIGH 				4


#define Port_u8PIN0                   	0x00
#define Port_u8PIN1                   	0x01
#define Port_u8PIN2                   	0x02
#define Port_u8PIN3                   	0x03
#define Port_u8PIN4                   	0x04
#define Port_u8PIN5                   	0x05
#define Port_u8PIN6                   	0x06
#define Port_u8PIN7                   	0x07
#define Port_u8PIN8                   	0x08
#define Port_u8PIN9                   	0x09
#define Port_u8PIN10                  	0x0A
#define Port_u8PIN11                  	0x0B
#define Port_u8PIN12                  	0x0C
#define Port_u8PIN13                  	0x0D
#define Port_u8PIN14                  	0x0E
#define Port_u8PIN15                  	0x0F
#define Port_u8PIN16                  	0x10
#define Port_u8PIN17                  	0x11
#define Port_u8PIN18                  	0x12
#define Port_u8PIN19                  	0x13
#define Port_u8PIN20                  	0x14
#define Port_u8PIN21                  	0x15
#define Port_u8PIN22                  	0x16
#define Port_u8PIN23                  	0x17
#define Port_u8PIN24                  	0x18
#define Port_u8PIN25                  	0x19
#define Port_u8PIN26                  	0x1A
#define Port_u8PIN27                  	0x1B
#define Port_u8PIN28                  	0x1C
#define Port_u8PIN29                  	0x1D
#define Port_u8PIN30                  	0x1E
#define Port_u8PIN31                  	0x1F

/*
* the following definitions are used to
	concatenate bits in a binary representation
	used inside the following function:
		- Port_vidInit()
*/
#define CONC_PRV(a,b,c,d,e,f,g,h)	0b##a##b##c##d##e##f##g##h
#define CONC(a,b,c,d,e,f,g,h)		CONC_PRV(a,b,c,d,e,f,g,h)

/*
* the following enum type definition is used
 	as a returned error status from every 
	function usage:
		- Port_tenuErrorStatus status = Port_enuSetPinMode(----,----)
*/
typedef enum{
	Port_enuOK,
	Port_enuPinError,
	Port_enuDirectionError,
	Port_enuModeError
} Port_tenuErrorStatus;

/*
* the following function is used to set
 	the initial mode and direction of the
	 configured pins 
* Args:		none
* Return:	none
* example:
		Port_vidInit();
*/
void Port_vidInit(void);
/*
* the following function is used to set
 	the Direction of a given pin,
	note: that if the provided pin number
	is not available, the function will
	report that error on the returned 
	status
* Args:
		u8 Copy_u8PinNum:		targeted Pin number
		u8 Copy_u8PinDirection:	pin configuration direction
* Return:
		Port_tenuErrorStatus: the Status of the function activity
* example:
		Port_tenuErrorStatus status = Port_enuSetPinDirection(Port_u8PIN30, Port_u8OUTPUT);
*/
Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum, u8 Copy_u8PinDirection);
/*
* the following function is used to set
 	the Direction and the mode of a given
	pin
	note: that if the provided pin number
	is not available, the function will
	report that error on the returned 
	status
* Args:
		u8 Copy_u8PinNum:		targeted Pin number
		u8 Copy_u8PinMode:		pin configuration direction and mode
* Return:
		Port_tenuErrorStatus: the Status of the function activity
* example:
		Port_tenuErrorStatus status = Port_enuSetPinMode(Port_u8PIN25, Port_u8INPUT_PULL_UP);
*/
Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum, u8 Copy_u8PinMode);

#endif /* PORT_H_ */
