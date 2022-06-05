/*
 * Dio.c
 *
 *  Created on: Mar 5, 2022
 *      Author: Ahmed Yehia
 */

#include "Utils/Std_types.h"
#include "Utils/Bit_utils.h"

#include "Dio.h"
#include "Dio_prv.h"
#include "Dio_cfg.h"

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
Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8Level)
{
    Dio_tenuPortId Loc_u8Port;
    u8 Loc_u8Pin;
    Dio_tenuErrorStatus Loc_enuStatus = Dio_enuOK;
    if (Copy_u8ChannelId >= Dio_u8NumOfPins)
    {
        Loc_enuStatus = Dio_enuPinError;
    }
    else
    {
        Loc_u8Port = Copy_u8ChannelId / Dio_u8PortSize;
        Loc_u8Pin = Copy_u8ChannelId % Dio_u8PortSize;
        switch (Loc_u8Port)
        {
        case Dio_enuPortAId:
            if (GET_BIT(DDRA,Loc_u8Pin) == 1)
            {
                CLR_BIT(PORTA,Loc_u8Pin);
                PORTA |= ((Copy_u8Level&1)<<Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError; 
            break;
                   
        case Dio_enuPortBId:
            if (GET_BIT(DDRB,Loc_u8Pin) == 1)
            {
                CLR_BIT(PORTB,Loc_u8Pin);
                PORTB |= ((Copy_u8Level&1)<<Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError; 
            break;
                   
        case Dio_enuPortCId:
            if (GET_BIT(DDRC,Loc_u8Pin) == 1)
            {
                CLR_BIT(PORTC,Loc_u8Pin);
                PORTC |= ((Copy_u8Level&1)<<Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError; 
            break;
                   
        case Dio_enuPortDId:
            if (GET_BIT(DDRD,Loc_u8Pin) == 1)
            {
                CLR_BIT(PORTD,Loc_u8Pin);
                PORTD |= ((Copy_u8Level&1)<<Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError; 
            break;
                   
        default:
            /* MISRA */
            break;
        }
    }
    return Loc_enuStatus;
}

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
Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId, pu8 Add_pu8Level)
{
    Dio_tenuPortId Loc_u8Port;
    u8 Loc_u8Pin,Loc_u8Val;
    Dio_tenuErrorStatus Loc_enuStatus = Dio_enuOK;
    if (Copy_u8ChannelId >= Dio_u8NumOfPins)
    {
        Loc_enuStatus = Dio_enuPinError;
    }
    else
    {
        Loc_u8Port = Copy_u8ChannelId / Dio_u8PortSize;
        Loc_u8Pin = Copy_u8ChannelId % Dio_u8PortSize;
        switch (Loc_u8Port)
        {
        case Dio_enuPortAId:
            if (GET_BIT(DDRA,Loc_u8Pin) == 0)
            {
                Loc_u8Val = GET_BIT(PINA,Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError;
            break;

        case Dio_enuPortBId:
            if (GET_BIT(DDRB,Loc_u8Pin) == 0)
            {
            	Loc_u8Val = GET_BIT(PINB,Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError;
            break;

        case Dio_enuPortCId:
            if (GET_BIT(DDRC,Loc_u8Pin) == 0)
            {
            	Loc_u8Val = GET_BIT(PINC,Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError;
            break;

        case Dio_enuPortDId:
//            if (GET_BIT(DDRD,Loc_u8Pin) == 0)
//            {
            	Loc_u8Val = GET_BIT(PIND,Loc_u8Pin);
//            }
//            else
//                Loc_enuStatus = Dio_enuPermError;
            break;

        default:
            /* MISRA */
            break;
        }
    }
    *Add_pu8Level = Loc_u8Val;
    return Loc_enuStatus;
}

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
Dio_tenuErrorStatus Dio_enuFlipChannel(u8 Copy_u8ChannelId)
{
    Dio_tenuPortId Loc_u8Port;
    u8 Loc_u8Pin;
    Dio_tenuErrorStatus Loc_enuStatus = Dio_enuOK;
    if (Copy_u8ChannelId >= Dio_u8NumOfPins)
    {
        Loc_enuStatus = Dio_enuPinError;
    }
    else
    {
        Loc_u8Port = Copy_u8ChannelId / Dio_u8PortSize;
        Loc_u8Pin = Copy_u8ChannelId % Dio_u8PortSize;
        switch (Loc_u8Port)
        {
        case Dio_enuPortAId:
            if (GET_BIT(DDRA,Loc_u8Pin) == 1)
            {
                TGL_BIT(PORTA,Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError; 
            break;
                   
        case Dio_enuPortBId:
            if (GET_BIT(DDRB,Loc_u8Pin) == 1)
            {
                TGL_BIT(PORTB,Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError; 
            break;
                   
        case Dio_enuPortCId:
            if (GET_BIT(DDRC,Loc_u8Pin) == 1)
            {
                TGL_BIT(PORTC,Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError; 
            break;
                   
        case Dio_enuPortDId:
            if (GET_BIT(DDRD,Loc_u8Pin) == 1)
            {
                TGL_BIT(PORTD,Loc_u8Pin);
            }
            else
                Loc_enuStatus = Dio_enuPermError; 
            break;
                   
        default:
            /* MISRA */
            break;
        }
    }
    return Loc_enuStatus;
}

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
		Dio_tenuErrorStatus status = Dio_enuWritePort(Dio_enuPortAId, 0x0F);
*/
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId, u8 Copy_u8Value)
{
    Dio_tenuPortId Loc_u8PortNum = Copy_u8PortId;
    Dio_tenuErrorStatus Loc_enuStatus = Dio_enuOK;
    switch (Loc_u8PortNum)
    {
    case Dio_enuPortAId:
        if (DDRA == 0xFF)
            PORTA = Copy_u8Value;
        else
            Loc_enuStatus = Dio_enuPermError;
        break;

    case Dio_enuPortBId:
        if (DDRB == 0xFF)
            PORTB = Copy_u8Value;
        else
            Loc_enuStatus = Dio_enuPermError;
        break;

    case Dio_enuPortCId:
        if (DDRC == 0xFF)
            PORTC = Copy_u8Value;
        else
            Loc_enuStatus = Dio_enuPermError;
        break;

    case Dio_enuPortDId:
        if (DDRD == 0xFF)
            PORTD = Copy_u8Value;
        else
            Loc_enuStatus = Dio_enuPermError;
        break;

    default:
        Loc_enuStatus = Dio_enuPortError;
        break;
    }
    return Loc_enuStatus;
}

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
		Dio_tenuErrorStatus status = Dio_enuWritePort(Dio_enuPortAId, &Loc_u8portValue);
*/
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId, pu8 Add_pu8Value)
{
    Dio_tenuPortId Loc_u8PortNum = Copy_u8PortId;
    Dio_tenuErrorStatus Loc_enuStatus = Dio_enuOK;
    switch (Loc_u8PortNum)
    {
    case Dio_enuPortAId:
        if (DDRA == 0x00)
            *Add_pu8Value = PINA;
        else
            Loc_enuStatus = Dio_enuPermError;
        break;

    case Dio_enuPortBId:
        if (DDRB == 0x00)
            *Add_pu8Value = PINB;
        else
            Loc_enuStatus = Dio_enuPermError;
        break;

    case Dio_enuPortCId:
        if (DDRC == 0x00)
            *Add_pu8Value = PINC;
        else
            Loc_enuStatus = Dio_enuPermError;
        break;

    case Dio_enuPortDId:
        if (DDRD == 0x00)
            *Add_pu8Value = PIND;
        else
            Loc_enuStatus = Dio_enuPermError;
        break;

    default:
        Loc_enuStatus = Dio_enuPortError;
        break;
    }
    return Loc_enuStatus;
}
