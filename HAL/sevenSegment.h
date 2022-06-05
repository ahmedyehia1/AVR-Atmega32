/*
 * sevenSegment.h
 *
 *  Created on: Mar 27, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

typedef enum{
    sevSeg_enuOK,
    sevSeg_enuError,
} sevSeg_tenuErrorStatus;

typedef struct{
    u8 value;
    u8 state;
    u8 toggle;
    u16 toggle_period;
    u16 toggle_elapsed;
} SevenSeg_strtSegment;

typedef struct{
	u8 pin;
	u8 type;
} SevenSeg_strtSegConfig;

// seven segment type
#define SEVSEG_u8TYPE_ANODE             0b1
#define SEVSEG_u8TYPE_CATHODE           0b0

// state control
#define SEVSEG_u8ON                     0b1
#define SEVSEG_u8OFF                    0b0

// numbers macros                         abcdefg.
#define SEVSEG_u8NUM_0                  0b11111100
#define SEVSEG_u8NUM_1                  0b01100000
#define SEVSEG_u8NUM_2                  0b11011010
#define SEVSEG_u8NUM_3                  0b11110010
#define SEVSEG_u8NUM_4                  0b01100110
#define SEVSEG_u8NUM_5                  0b10110110
#define SEVSEG_u8NUM_6                  0b10111110
#define SEVSEG_u8NUM_7                  0b11100000
#define SEVSEG_u8NUM_8                  0b11111110
#define SEVSEG_u8NUM_9                  0b11110110


void sevSeg_vidInit(void);

/*
* the following function is used to display the 
    given number on seven segment
* Args:         Copy_u32Number:         displayed number
* Return:       sevSeg_tenuErrorStatus: return status
* example:
		sevSeg_enuDisplayNumber(124);
*/
extern sevSeg_tenuErrorStatus sevSeg_enuDisplayNumber(u32 Copy_u32Number);

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
extern sevSeg_tenuErrorStatus sevSeg_enuToggleSegment(u8 Copy_u8Segment, u16 Copy_u16ToggleDelay);

/*
* the following function is used to fix a given 
    seven segment from toggling on and off
* Args:         Copy_u8Segment:         identifier of the selected seven segment
* Return:       sevSeg_tenuErrorStatus: return status
* example:
		sevSeg_enuToggleSegment(0);
*/
extern sevSeg_tenuErrorStatus sevSeg_enuFixSegment(u8 Copy_u8Segment);

/*
* the following function is by the scheduler to 
    perform one or more of the following actions:
        - refresh displayed number
        - toggle one or more segment(s)
    note: IT CANNOT BE CALLED BY THE USER 
* Args:         None
* Return:       None
* example:
		------
*/
extern void sevSeg_vidTask(void);

#endif /* SEVENSEGMENT_H_ */
