/*
 * Gpt.h
 *
 *  Created on: Apr 15, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef GPT_H_
#define GPT_H_

/* timer init:
*  WGM -> normal
*  COM -> normal
*  CSO = selected based on config
*  TOIE -> disable
*/

/* Gpt types:
*  Gpt_ConfigType       struct
*  Gpt_ChannelType      numeric enum
*  Gpt_ValueType        numeric
*/   

#define GPT_MODE_NORMAL                                 0x00
#define GPT_MODE_CTC                                    0x41
#define GPT_MODE_CTC_ON_OV                              0xC1

#define GPT_CLK_OFF                                     (u64)0x000000
#define GPT_INTERNAL_CLK_PRESCALER_VAL_1                (u64)0x000111
#define GPT_INTERNAL_CLK_PRESCALER_VAL_8                (u64)0x000822
#define GPT_INTERNAL_CLK_PRESCALER_VAL_32               (u64)0x002030
#define GPT_INTERNAL_CLK_PRESCALER_VAL_64               (u64)0x004043
#define GPT_INTERNAL_CLK_PRESCALER_VAL_128              (u64)0x008050
#define GPT_INTERNAL_CLK_PRESCALER_VAL_256              (u64)0x010064
#define GPT_INTERNAL_CLK_PRESCALER_VAL_1024             (u64)0x040075
#define GPT_EXTERNAL_CLK_FALLING_EDGE                   (u64)0x000006
#define GPT_EXTERNAL_CLK_RISING_EDGE                    (u64)0x000007

#define GPT_COMPARE_OUTPUT_MODE_OFF                     0x00
#define GPT_COMPARE_OUTPUT_MODE_TOGGLE                  0x01
#define GPT_COMPARE_OUTPUT_MODE_CLEAR                   0x02
#define GPT_COMPARE_OUTPUT_MODE_SET                     0x03

#define GPT_COMPARATORS_OFF                             0x00
#define GPT_COMPARATOR_A                                0x04
#define GPT_COMPARATOR_B                                0x08
#define GPT_COMPARATOR_A_AND_B                          0x0C

typedef enum{
    Gpt_Timer0,
    Gpt_Timer1,
    Gpt_Timer2,
} Gpt_ChannelType;

typedef struct{
    Gpt_ChannelType channel;
    u8              mode;
    u32              prescaler;
    u8              compareOutputMode;
    u8              comparators;
} Gpt_ConfigType;

typedef f32 Gpt_ValueType;          // time in ms

// definition for the callback function used on gpt module
typedef void (*Gpt_callbackFunctionType)(void);


/*
* the following function is used to initialize the 
	gpt module using the configured options
* Args:         cfgPtr: pointer to the configuration used
* Return:       None
* example:
        Gpt_ConfigType cfg = {
            .channel = Gpt_Timer1,
            .mode = GPT_MODE_NORMAL,
            .prescaler = GPT_INTERNAL_CLK_PRESCALER_VAL_8,
            .compareOutputMode = GPT_COMPARE_OUTPUT_MODE_OFF,
            .comparators = GPT_COMPARATOR_A
        };
        Gpt_Init(&cfg);
*/
void Gpt_Init(Gpt_ConfigType* cfgPtr);

/*
* the following function is used to calculate the 
	time elapsed from the start of the given timer
* Args:         channel: channel no.
* Return:       time value
* example:
        Gpt_ValueType time Gpt_GetTimeElapsed(Gpt_Timer1);
*/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType channel);

/*
* the following function is used to calculate the 
	time remaining for the given timer before 
    reaching the provided time
* Args:         channel: channel no.
* Return:       time value
* example:
        Gpt_ValueType time Gpt_GetTimeRemaining(Gpt_Timer1);
*/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType channel);

/*
* the following function is used to start the 
    given timer
* Args:         channel: channel no.
*               timeMs: given time in milliseconds
* Return:       None
* example:
        Gpt_StartTimer(Gpt_Timer1,400);
*/
void Gpt_StartTimer(Gpt_ChannelType channel, Gpt_ValueType timeMs);

/*
* the following function is used to stop the 
    given timer
* Args:         channel: channel no.
* Return:       None
* example:
        Gpt_StopTimer(Gpt_Timer1);
*/
void Gpt_StopTimer(Gpt_ChannelType channel);

/*
* the following function is used to register a 
    notification function to be fired after the
    time elapse  
* Args:         channel: channel no.
*               CBF: the given callback function 
* Return:       None
* example:
        Gpt_StopTimer(Gpt_Timer1);
*/
void Gpt_registerNotification(Gpt_ChannelType channel, Gpt_callbackFunctionType CBF);

#endif
