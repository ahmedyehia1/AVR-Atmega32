/*
 * sevenSegment.c
 *
 *  Created on: Mar 27, 2022
 *      Author: Ahmed-Yehia
 */


#include "Utils/Bit_utils.h"
#include "Utils/Std_types.h"
#include "Dio.h"

#include "sevenSegment.h"
#include "sevenSegment_prv.h"
#include "sevenSegment_cfg.h"


extern SevenSeg_strtSegConfig SevenSeg_strPinsConfig[SEVSEG_u8NUM_OF_SEGMENTS];
static SevenSeg_strtSegment SevenSeg_au8SegmentControl[SEVSEG_u8NUM_OF_SEGMENTS];
static const u8 Loc_au8All_Digits[] = {
    SEVSEG_u8NUM_0,
    SEVSEG_u8NUM_1,
    SEVSEG_u8NUM_2,
    SEVSEG_u8NUM_3,
    SEVSEG_u8NUM_4,
    SEVSEG_u8NUM_5,
    SEVSEG_u8NUM_6,
    SEVSEG_u8NUM_7,
    SEVSEG_u8NUM_8,
    SEVSEG_u8NUM_9,
};

/*
* the following function is used to display the 
    given number on seven segment
* Args:         Copy_u32Number:         displayed number
* Return:       sevSeg_tenuErrorStatus: return status
* example:
		sevSeg_enuDisplayNumber(124);
*/
void sevSeg_vidInit(void)
{
    for (u8 Loc_u8Index = 1; Loc_u8Index <= SEVSEG_u8NUM_OF_SEGMENTS; Loc_u8Index++)
    {
        SevenSeg_au8SegmentControl[SEVSEG_u8NUM_OF_SEGMENTS-Loc_u8Index].state = SEVSEG_u8ON;
        SevenSeg_au8SegmentControl[SEVSEG_u8NUM_OF_SEGMENTS-Loc_u8Index].toggle = SEVSEG_u8OFF;
    }
}

sevSeg_tenuErrorStatus sevSeg_enuDisplayNumber(u32 Copy_u32Number)
{
	Dio_enuFlipChannel(DIO_u8PIN15);
    sevSeg_tenuErrorStatus Loc_enuReturnStatus = sevSeg_enuOK;
    for (u8 Loc_u8Index = 1; Loc_u8Index <= SEVSEG_u8NUM_OF_SEGMENTS; Loc_u8Index++)
    {
        SevenSeg_au8SegmentControl[SEVSEG_u8NUM_OF_SEGMENTS-Loc_u8Index].value = Copy_u32Number % 10;
		Copy_u32Number /= 10;
    }
    if (Copy_u32Number > 0)
    {
        Loc_enuReturnStatus = sevSeg_enuError;
    }

    return Loc_enuReturnStatus;
}

/*
* the following function is used to toggle a given 
    seven segment on and off periodically based on 
    the passed delay 
* Args:         Copy_u8Segment:         identifier of the selected seven segment
                Copy_u16ToggleDelay:    toggle delay in milliseconds 
* Return:       sevSeg_tenuErrorStatus: return status
* example:
		sevSeg_enuToggleSegment(0, 100);
*/
sevSeg_tenuErrorStatus sevSeg_enuToggleSegment(u8 Copy_u8Segment, u16 Copy_u16ToggleDelay)
{
    sevSeg_tenuErrorStatus Loc_enuReturnStatus = sevSeg_enuOK;
    if (Copy_u8Segment >= SEVSEG_u8NUM_OF_SEGMENTS)
    {
        Loc_enuReturnStatus = sevSeg_enuError;
    }
    else
    {
        SevenSeg_au8SegmentControl[Copy_u8Segment].toggle = SEVSEG_u8ON;
        SevenSeg_au8SegmentControl[Copy_u8Segment].toggle_period = Copy_u16ToggleDelay;
        SevenSeg_au8SegmentControl[Copy_u8Segment].toggle_elapsed = 0;
    }

    return Loc_enuReturnStatus;
}

/*
* the following function is used to fix a given 
    seven segment from toggling on and off
* Args:         Copy_u8Segment:         identifier of the selected seven segment
* Return:       sevSeg_tenuErrorStatus: return status
* example:
		sevSeg_enuToggleSegment(0);
*/
sevSeg_tenuErrorStatus sevSeg_enuFixSegment(u8 Copy_u8Segment)
{
    sevSeg_tenuErrorStatus Loc_enuReturnStatus = sevSeg_enuOK;
    if (Copy_u8Segment >= SEVSEG_u8NUM_OF_SEGMENTS)
    {
        Loc_enuReturnStatus = sevSeg_enuError;
    }
    else
    {
        SevenSeg_au8SegmentControl[Copy_u8Segment].toggle = SEVSEG_u8OFF;
        SevenSeg_au8SegmentControl[Copy_u8Segment].state = SEVSEG_u8ON;
    }
    
    return Loc_enuReturnStatus;
}

/*
* the following function is by the scheduler to 
    perform one or more of the following actions:
        - refresh displayed number
        - toggle one or more segment(s)
    (every 1ms)
    note: IT CANNOT BE CALLED BY THE USER 
* Args:         None
* Return:       None
* example:
		------
*/
void sevSeg_vidTask(void)
{
    static u8 Loc_u8CurrentSegment = 0;
    u8 Loc_u8Data = Loc_au8All_Digits[SevenSeg_au8SegmentControl[Loc_u8CurrentSegment].value];
	for (u8 Loc_u8Index = 0; Loc_u8Index < SEVSEG_u8NUM_OF_SEGMENTS; Loc_u8Index++)
	{
		if (SevenSeg_au8SegmentControl[Loc_u8Index].toggle == SEVSEG_u8ON)
		{
			if(SevenSeg_au8SegmentControl[Loc_u8Index].toggle_elapsed >= SevenSeg_au8SegmentControl[Loc_u8Index].toggle_period)
			{
				SevenSeg_au8SegmentControl[Loc_u8Index].state ^= 1;
				SevenSeg_au8SegmentControl[Loc_u8Index].toggle_elapsed = 0;
			}
			SevenSeg_au8SegmentControl[Loc_u8Index].toggle_elapsed += (u16)SEVSEG_u8TaskPeriod_ms;
		}
	}
    if (SevenSeg_au8SegmentControl[Loc_u8CurrentSegment].state == SEVSEG_u8ON)
    {
        for (u8 Loc_u8Index = 0; Loc_u8Index < SEVSEG_u8NUM_OF_SEGMENTS; Loc_u8Index++)
        {
            if (Loc_u8Index == Loc_u8CurrentSegment)
            {
                Dio_enuWriteChannel(SevenSeg_strPinsConfig[Loc_u8Index].pin, SevenSeg_strPinsConfig[Loc_u8Index].type);
            }
            else
            {
                Dio_enuWriteChannel(SevenSeg_strPinsConfig[Loc_u8Index].pin, ~(SevenSeg_strPinsConfig[Loc_u8Index].type));
            }
        }

        Dio_enuWriteChannel(SEVSEG_u8PIN_A,   SevenSeg_strPinsConfig[Loc_u8CurrentSegment].type ^ (Loc_u8Data >> 7));
        Dio_enuWriteChannel(SEVSEG_u8PIN_B,   SevenSeg_strPinsConfig[Loc_u8CurrentSegment].type ^ (Loc_u8Data >> 6));
        Dio_enuWriteChannel(SEVSEG_u8PIN_C,   SevenSeg_strPinsConfig[Loc_u8CurrentSegment].type ^ (Loc_u8Data >> 5));
        Dio_enuWriteChannel(SEVSEG_u8PIN_D,   SevenSeg_strPinsConfig[Loc_u8CurrentSegment].type ^ (Loc_u8Data >> 4));
        Dio_enuWriteChannel(SEVSEG_u8PIN_E,   SevenSeg_strPinsConfig[Loc_u8CurrentSegment].type ^ (Loc_u8Data >> 3));
        Dio_enuWriteChannel(SEVSEG_u8PIN_F,   SevenSeg_strPinsConfig[Loc_u8CurrentSegment].type ^ (Loc_u8Data >> 2));
        Dio_enuWriteChannel(SEVSEG_u8PIN_G,   SevenSeg_strPinsConfig[Loc_u8CurrentSegment].type ^ (Loc_u8Data >> 1));
        Dio_enuWriteChannel(SEVSEG_u8PIN_DOT, SevenSeg_strPinsConfig[Loc_u8CurrentSegment].type ^ (Loc_u8Data >> 0));
    }
    else
    {
    	Dio_enuWriteChannel(SevenSeg_strPinsConfig[Loc_u8CurrentSegment].pin, ~(SevenSeg_strPinsConfig[Loc_u8CurrentSegment].type));
    }
    Loc_u8CurrentSegment = (Loc_u8CurrentSegment+1) % SEVSEG_u8NUM_OF_SEGMENTS;
}
