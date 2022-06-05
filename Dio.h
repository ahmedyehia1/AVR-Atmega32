/*
 * Dio.h
 *
 *  Created on: Mar 5, 2022
 *      Author: Ahmed Yehia
 */

#ifndef DIO_H_
#define DIO_H_

/*
* the following definitions are used to
	select a given pin to be accessed
	usage:
		- Dio_enuWriteChannel(DIO_u8PIN4,----)
		- Dio_enuReadChannel(DIO_u8PIN12,----)
		- Dio_enuFlipChannel(DIO_u8PIN23,----)
*/
#define DIO_u8PIN0             		0
#define DIO_u8PIN1             		1
#define DIO_u8PIN2             		2
#define DIO_u8PIN3             		3
#define DIO_u8PIN4             		4
#define DIO_u8PIN5             		5
#define DIO_u8PIN6             		6
#define DIO_u8PIN7             		7
#define DIO_u8PIN8             		8
#define DIO_u8PIN9             		9
#define DIO_u8PIN10            		10
#define DIO_u8PIN11            		11
#define DIO_u8PIN12            		12
#define DIO_u8PIN13            		13
#define DIO_u8PIN14            		14
#define DIO_u8PIN15            		15
#define DIO_u8PIN16            		16
#define DIO_u8PIN17            		17
#define DIO_u8PIN18            		18
#define DIO_u8PIN19            		19
#define DIO_u8PIN20            		20
#define DIO_u8PIN21            		21
#define DIO_u8PIN22            		22
#define DIO_u8PIN23            		23
#define DIO_u8PIN24            		24
#define DIO_u8PIN25            		25
#define DIO_u8PIN26            		26
#define DIO_u8PIN27            		27
#define DIO_u8PIN28            		28
#define DIO_u8PIN29            		29
#define DIO_u8PIN30            		30
#define DIO_u8PIN31            		31

/*
* the following enum type definition is used
 	as a returned error status from every 
	function usage:
		- Port_tenuErrorStatus status = Dio_enuWritePort(----,----)
*/
typedef enum{
    Dio_enuOK,
    Dio_enuPinError,
    Dio_enuPortError,
    Dio_enuPermError
} Dio_tenuErrorStatus;

/*
* the following enum type definition is used
 	as a parameter for port accessing functions 
	usage:
		- Dio_enuWritePort(Dio_enuPortCId,----)
		- Dio_enuReadPort(Dio_enuPortBId,----)
*/
typedef enum{
    Dio_enuPortAId,
    Dio_enuPortBId,
    Dio_enuPortCId,
    Dio_enuPortDId
} Dio_tenuPortId;

/*
* the following function is used to modify the 
	output level of a given pin
    note: error can be caused by one of the following:
    -the provided pin number is not available
    -the provided pin number is configured as read pin
* Args:
		u8 Copy_u8ChannelId:	given pin number
		u8 Copy_u8Level:	    specified pin level (0, 1)
* Return:
		Dio_tenuErrorStatus:    the Status of the function activity
* example:
		Dio_tenuErrorStatus status = Dio_enuWriteChannel(DIO_u8PIN24, 0);
*/
Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8Level);

/*
* the following function is used to read the 
	output level of a given pin
    note: error can be caused by one of the following:
    -the provided pin number is not available
    -the provided pin number is configured as write pin
* Args:
		u8 Copy_u8ChannelId:	given pin number
		pu8 Copy_pu8Level:	    pointer to a vriable that will hold the pin level
* Return:
		Dio_tenuErrorStatus:    the Status of the function activity
* example:
		Dio_tenuErrorStatus status = Dio_enuReadChannel(DIO_u8PIN20, &Loc_u8pinValue);
*/
Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId, pu8 Add_pu8Level);

/*
* the following function is used to flip/toggle the 
	output level of a given pin (from high to low 
    and vice verse)
    note: error can be caused by one of the following:
    -the provided pin number is not available
    -the provided pin number is configured as read pin
* Args:
		u8 Copy_u8ChannelId:	given pin number
* Return:
		Dio_tenuErrorStatus:    the Status of the function activity
* example:
		Dio_tenuErrorStatus status = Dio_enuWriteChannel(DIO_u8PIN13);
*/
Dio_tenuErrorStatus Dio_enuFlipChannel(u8 Copy_u8ChannelId);

/*
* the following function is used to modify the 
	output levels of all pins from a given port
    note: error can be caused by one of the following:
    -the provided port number is not available
    -the provided port has a pin which is configured as read pin
* Args:
		u8 Copy_u8PortId:	    given port identifier
		u8 Copy_u8Value:	    specified port value (0x00 : 0xFF)
* Return:
		Dio_tenuErrorStatus:    the Status of the function activity
* example:
		Dio_tenuErrorStatus status = Dio_enuWritePort(DIO_u8PORTA, 0x0F);
*/
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId, u8 Copy_u8Value);

/*
* the following function is used to read the 
	output levels of all pins of a given port
    note: error can be caused by one of the following:
    -the provided port number is not available
    -the provided port has a pin which is configured as write pin
* Args:
		u8 Copy_u8PortId:	    given port identifier
		pu8 Copy_pu8Value:	    pointer to a variable that will hold
                                the specified port value
* Return:
		Dio_tenuErrorStatus:    the Status of the function activity
* example:
		Dio_tenuErrorStatus status = Dio_enuWritePort(DIO_u8PORTA, &Loc_u8portValue);
*/
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId, pu8 Add_pu8Value);

#endif /* DIO_H_ */
