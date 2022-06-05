/*
 * Lcd.c
 *
 *  Created on: Mar 15, 2022
 *      Author: Ahmed-Yehia
 */


#include <util/delay.h>
#include "Utils/Std_types.h"
#include "Utils/Bit_utils.h"

#include "Dio.h"

#include "Lcd.h"
#include "Lcd_prv.h"
#include "Lcd_cfg.h" 


/*
* the following function is used to initialize the 
	LCD on the 8 bit mode
* Args:         None
* Return:       None
*/
void Lcd_vidInit(void)
{
    /* note: there is no need for delay as Lcd_enuSend() 
            function waits for 2ms internally
    */
   
    // waits for 30 ms until the internal MCU is initialized
    _delay_ms(30);
   
    // set the initial lcd mode (default: 8 bit, 2 line, 5x7 font)   !!error if the provided mode is 4 bits!!
    Lcd_enuSend(LCD_u8SEND_TYPE_CMD, LCD_u8MODE_CFG);
    
    // set the initial display mode (default: display on, cusror off) 
    Lcd_enuSend(LCD_u8SEND_TYPE_CMD, LCD_u8DIPLAY_CFG);
     
    // clear the screen
    Lcd_enuSend(LCD_u8SEND_TYPE_CMD, LCD_u8CMD__CLR_SCRN_CFG);

    // set the initial display and cursor mode (default: cursor moves right, no display shift) 
    Lcd_enuSend(LCD_u8SEND_TYPE_CMD, LCD_u8CURSOR_AND_SHIFT_CFG);
    
}

/*
*   Lcd_enuSend()
        sends commands or data to be displayed based
        on the passed parameter mask
* Args:         Copy_u8SendType: the type of sent data
                Copy_u8Cmd: the sent data
* Return:       error status
*/
Lcd_tenuErrorStatus Lcd_enuSend(u8 Copy_u8SendType, u8 Copy_u8Cmd)
{
    Lcd_tenuErrorStatus Loc_enuStatus = Lcd_enuOK;

        Dio_enuWriteChannel(LCD_u8EN_PIN, 0);
        Dio_enuWriteChannel(LCD_u8RS_PIN, 0b1&(Copy_u8SendType>>1));
        Dio_enuWriteChannel(LCD_u8RW_PIN, 0b1&(Copy_u8SendType>>0));
        Dio_enuWriteChannel(LCD_u8D7_PIN, 0b1&(Copy_u8Cmd>>7));
        Dio_enuWriteChannel(LCD_u8D6_PIN, 0b1&(Copy_u8Cmd>>6));
        Dio_enuWriteChannel(LCD_u8D5_PIN, 0b1&(Copy_u8Cmd>>5));
        Dio_enuWriteChannel(LCD_u8D4_PIN, 0b1&(Copy_u8Cmd>>4));
        Dio_enuWriteChannel(LCD_u8D3_PIN, 0b1&(Copy_u8Cmd>>3));
        Dio_enuWriteChannel(LCD_u8D2_PIN, 0b1&(Copy_u8Cmd>>2));
        Dio_enuWriteChannel(LCD_u8D1_PIN, 0b1&(Copy_u8Cmd>>1));
        Dio_enuWriteChannel(LCD_u8D0_PIN, 0b1&(Copy_u8Cmd>>0));
        Dio_enuWriteChannel(LCD_u8EN_PIN, 1);
        _delay_ms(2);
        Dio_enuWriteChannel(LCD_u8EN_PIN, 0);

    return Loc_enuStatus;
}

/*
*   Lcd_enuGoto()
        move cusor to specified position 
* Args:         Copy_u8XPos: horizontal position/offset
                Copy_u8YPos: vertical position/offset
* Return:       error status
*/
Lcd_tenuErrorStatus Lcd_enuGoto(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	Lcd_tenuErrorStatus Loc_enuStatus = Lcd_enuOK;
	// check if the position is correct
    #if                                                             \
    LCD_u8MODE_CFG == LCD_u8CMD__MODE_4_BIT_1_LINE_5_7_FONT     ||  \
    LCD_u8MODE_CFG == LCD_u8CMD__MODE_4_BIT_1_LINE_5_10_FONT    ||  \
    LCD_u8MODE_CFG == LCD_u8CMD__MODE_8_BIT_1_LINE_5_7_FONT     ||  \
    LCD_u8MODE_CFG == LCD_u8CMD__MODE_8_BIT_1_LINE_5_10_FONT
        #define LOC_MAX_X   80
        #define LOC_MAX_Y   1
    #elif                                                           \
    LCD_u8MODE_CFG == LCD_u8CMD__MODE_4_BIT_2_LINE_5_7_FONT     ||  \
    LCD_u8MODE_CFG == LCD_u8CMD__MODE_4_BIT_2_LINE_5_10_FONT    ||  \
    LCD_u8MODE_CFG == LCD_u8CMD__MODE_8_BIT_2_LINE_5_7_FONT     ||  \
    LCD_u8MODE_CFG == LCD_u8CMD__MODE_8_BIT_2_LINE_5_10_FONT
        #define LOC_MAX_X   40
        #define LOC_MAX_Y   2
    #endif
    if (Copy_u8XPos >= LOC_MAX_X)
    {
        Loc_enuStatus = Lcd_enuInvalidCmdError;
    }
    else if (Copy_u8YPos >= LOC_MAX_Y)
    {
        Loc_enuStatus = Lcd_enuInvalidCmdError;
    }
    else
    {
	    Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_CMD, 0x80+0x40*Copy_u8YPos+Copy_u8XPos);
    }
    #undef LOC_MAX_X
    #undef LOC_MAX_Y
	return Loc_enuStatus;
}

/*
*   Lcd_enuDisplayNumber()
        print number on screen 
* Args:         Copy_u8Num: number value
* Return:       error status
*/
Lcd_tenuErrorStatus Lcd_enuDisplayNumber(s32 Copy_s32Num)
{
	Lcd_tenuErrorStatus Loc_enuStatus = Lcd_enuOK;
	s32 Loc_s32Val;
    u8 Loc_u8Itr;
	static u8 Loc_au8AllDigits[11]; // from -2 Billion to 2 Billion (1 bit sign and 10 bits number)
    // Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_DATA, Loc_u32Val % 10 + LCD_u8DATA__XX_RAM_DATA_ASCII_0);
	if (Copy_s32Num >= 0)
		Loc_s32Val = Copy_s32Num;
	else
		Loc_s32Val = -Copy_s32Num;
	for (Loc_u8Itr = 10; Loc_u8Itr >= 0 && Loc_s32Val; Loc_u8Itr--)
    {
        Loc_au8AllDigits[Loc_u8Itr] = Loc_s32Val % 10 + LCD_u8DATA__XX_RAM_DATA_ASCII_0; // store digits in ascii
        Loc_s32Val /= 10;
    }
    if (Copy_s32Num < 0)
    {
        Loc_au8AllDigits[Loc_u8Itr] = '-';
    }
    else
    {
        Loc_u8Itr++;
    }
	for (; Loc_u8Itr < 11; Loc_u8Itr++)
    {
        Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_DATA, Loc_au8AllDigits[Loc_u8Itr]);
    }
	return Loc_enuStatus;
}

/*
*   Lcd_enuDisplayNumberR2L()
        print number on screen from Right to Left 
* Args:         Copy_u8Num: number value
* Return:       error status
*/
Lcd_tenuErrorStatus Lcd_enuDisplayNumberR2L(u32 Copy_u32Num)
{

    Lcd_tenuErrorStatus Loc_enuStatus = Lcd_enuOK;
	u32 Loc_u32Val = Copy_u32Num;
	Lcd_enuSend(LCD_u8SEND_TYPE_CMD, LCD_u8CMD__CURSOR_DEC_SCEERN_SHIFT_OFF);
	if (Loc_u32Val)
	{
		while (Loc_u32Val)
		{
			Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_DATA, Loc_u32Val % 10 + LCD_u8DATA__XX_RAM_DATA_ASCII_0);
			Loc_u32Val /= 10;
		}
	}
	else
	{
		Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_DATA, LCD_u8DATA__XX_RAM_DATA_ASCII_0);
	}

	Lcd_enuSend(LCD_u8SEND_TYPE_CMD, LCD_u8CMD__CURSOR_INC_SCEERN_SHIFT_OFF);

	return Loc_enuStatus;

}

Lcd_tenuErrorStatus Lcd_enuDisplayFloatNumber(f32 Copy_f32Num, u32 Copy_u32Pre)
{
	Lcd_enuDisplayFloatNumberR2L(Copy_f32Num,Copy_u32Pre); // temporarily
}
Lcd_tenuErrorStatus Lcd_enuDisplayFloatNumberR2L(f32 Copy_f32Num, u32 Copy_u32Pre)
{
	// future update: make this function handles multi-digit numbers
	Lcd_tenuErrorStatus Loc_enuStatus = Lcd_enuOK;
	u32 Loc_u32Q = (u32)Copy_f32Num;
	u32 Loc_u32M = ((u32)(Copy_u32Pre*Copy_f32Num)) % Copy_u32Pre;
	Copy_u32Pre /= 10;
	Lcd_enuSend(LCD_u8SEND_TYPE_CMD, LCD_u8CMD__CURSOR_DEC_SCEERN_SHIFT_OFF);
	if (Loc_u32M)
	{
		while (Copy_u32Pre)
		{
			Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_DATA, Loc_u32M % 10 + LCD_u8DATA__XX_RAM_DATA_ASCII_0);
			Loc_u32M /= 10;
			Copy_u32Pre /= 10;
		}
	}
	else
	{
		Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_DATA, LCD_u8DATA__XX_RAM_DATA_ASCII_0);
	}
	Lcd_enuSend(LCD_u8SEND_TYPE_DATA, LCD_u8DATA__XX_RAM_DATA_DOT);
	if (Loc_u32Q)
	{
		while (Loc_u32Q)
		{
			Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_DATA, Loc_u32Q % 10 + LCD_u8DATA__XX_RAM_DATA_ASCII_0);
			Loc_u32Q /= 10;
		}
	}
	else
	{
		Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_DATA, LCD_u8DATA__XX_RAM_DATA_ASCII_0);
	}
	Lcd_enuSend(LCD_u8SEND_TYPE_CMD, LCD_u8CMD__CURSOR_INC_SCEERN_SHIFT_OFF);
//	}
	return Loc_enuStatus;
}

/*
*   Lcd_enuDisplayString()
        print string on screen
* Args:         Copy_au8String: string represented as an array of char to be displayed
* Return:       error status
*/
Lcd_tenuErrorStatus Lcd_enuDisplayString(u8 Copy_au8String[])
{
	//	checking \0 save us from using strlen() function from string.h library
	Lcd_tenuErrorStatus Loc_enuStatus = Lcd_enuOK;
	for (u8 Loc_u8Iterator = 0; Copy_au8String[Loc_u8Iterator] != '\0'; Loc_u8Iterator++)
	{
		Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_DATA, Copy_au8String[Loc_u8Iterator]);
	}
	return Loc_enuStatus;
}

/*
*   Lcd_enuCreateCustomCharacter()
        store customly generated character on CG RAM on the given index
        note: this function only creates the character, in order to display it
            Lcd_enuSend(LCD_u16XX_RAM_DATA_<index>)
            ex Copy_u8ShapeIndex = LCD_u16CG_RAM_SHAPE_0
* Args:         Copy_au8CharArray: array of char that reperesents the custom shape to be stored
                Copy_u8ShapeIndex: the custom shape index
* Return:       error status
*/
Lcd_tenuErrorStatus Lcd_enuCreateCustomCharacter(u8 Copy_au8CharArray[], u8 Copy_u8ShapeIndex)
{
    u8 Loc_u8Iterator = 0;    
    // move pointer to the targeted location
    Lcd_tenuErrorStatus Loc_enuStatus = Lcd_enuSend(LCD_u8SEND_TYPE_CMD, Copy_u8ShapeIndex);
    for(Loc_u8Iterator = 0; Loc_u8Iterator < 8; Loc_u8Iterator++)
    {
        Lcd_enuSend(LCD_u8SEND_TYPE_DATA, Copy_au8CharArray[Loc_u8Iterator]);
    }
    return Loc_enuStatus;
}
