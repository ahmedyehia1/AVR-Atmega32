/*
 * Gpt.c
 *
 *  Created on: Apr 15, 2022
 *      Author: Ahmed-Yehia
 */

#include <avr/interrupt.h>
#include "Utils/Bit_utils.h"
#include "Utils/Std_Types.h"

#include "Gpt.h"
#include "Gpt_prv.h"
#include "Gpt_cfg.h"

static u32 Gpt_OV_tot_Cout[3];
static u32 Gpt_OV_Cout_remaining[3];
static f32 Gpt_OV_Time_US[3];
static u8 Gpt_prescaler_val[3];
static u16 Gpt_initialDelay[3];
static Gpt_callbackFunctionType Gpt_callbackFunctions[3];

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
void Gpt_Init(Gpt_ConfigType* cfgPtr)
{
    
	u8 COM = cfgPtr->compareOutputMode;
	u16 COMarr[] = {
		0x0000,
		0x5410,
		0xA820,
		0xFC30
	};
    u16 prescalerVal = (cfgPtr->prescaler) >> 8;
    switch (cfgPtr->channel)
    {
    case Gpt_Timer0:
        
        TCCR0 &= GPT_TIMER_0_2_MASK;
        TCCR0 |= ( (((cfgPtr->mode) & 0xF) << 3) | (((cfgPtr->compareOutputMode) & 0xF) << 4) );
        // ENABLE interrupt
        TIMSK |= GPT_TIMER0_OV_INTERRUPT_EN;
        Gpt_prescaler_val[Gpt_Timer0] = (cfgPtr->prescaler) & 0xF;
        Gpt_OV_Time_US[Gpt_Timer0] =  (f32)GPT_TIMER0_MAX_LOAD_VAL * (f32)prescalerVal * ((f32)1000 / (f32)F_CPU);
        break;

    case Gpt_Timer1:

        TCCR1A &= GPT_TIMER_1A_MASK;
        TCCR1B &= GPT_TIMER_1B_MASK;
        TCCR1A |= ( (((cfgPtr->mode) &0x30) >> 4) | (((COMarr[COM] >> cfgPtr->comparators) & 0xF) << 4) );
        // ENABLE interrupt
        TIMSK |= GPT_TIMER1_OV_INTERRUPT_EN;
        Gpt_prescaler_val[Gpt_Timer1] = (cfgPtr->prescaler) & 0xF;
        Gpt_OV_Time_US[Gpt_Timer1] = (f32)GPT_TIMER1_MAX_LOAD_VAL * (f32)prescalerVal * ((f32)1000 / (f32)F_CPU);
        break;

    case Gpt_Timer2:
        
        TCCR2 &= GPT_TIMER_0_2_MASK;
        TCCR2 |= ( (((cfgPtr->mode) & 0xF) << 3) | (((cfgPtr->compareOutputMode) & 0xF) << 4) );
        // ENABLE interrupt
        TIMSK |= GPT_TIMER2_OV_INTERRUPT_EN;
        Gpt_prescaler_val[Gpt_Timer2] = ((cfgPtr->prescaler) >> 4) & 0xF;
        Gpt_OV_Time_US[Gpt_Timer2] = (f32)GPT_TIMER2_MAX_LOAD_VAL * (f32)prescalerVal * ((f32)1000 / (f32)F_CPU);
        break;
    
    default:
        break;
    }
    
}

/*
* the following function is used to calculate the 
	time elapsed from the start of the given timer
* Args:         channel: channel no.
* Return:       time value
* example:
        Gpt_ValueType time Gpt_GetTimeElapsed(Gpt_Timer1);
*/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType channel)
{
    f32 elapsedTime;
    switch (channel)
    {
    case Gpt_Timer0:
        elapsedTime = (((f32)(Gpt_OV_tot_Cout[Gpt_Timer0]-Gpt_OV_Cout_remaining[Gpt_Timer0]) * (f32)Gpt_OV_Time_US[Gpt_Timer0]) + (f32)(GPT_TIMER0_MAX_LOAD_VAL - TCNT0 + Gpt_initialDelay[Gpt_Timer0]) * (f32)Gpt_OV_Time_US[Gpt_Timer0] / (f32)GPT_TIMER0_MAX_LOAD_VAL) / (f32)1000;
        break;
    case Gpt_Timer1:
        elapsedTime = (((f32)(Gpt_OV_tot_Cout[Gpt_Timer1]-Gpt_OV_Cout_remaining[Gpt_Timer1]) * (f32)Gpt_OV_Time_US[Gpt_Timer1]) + (f32)(GPT_TIMER1_MAX_LOAD_VAL - TCNT1 + Gpt_initialDelay[Gpt_Timer1]) * (f32)Gpt_OV_Time_US[Gpt_Timer1] / (f32)GPT_TIMER1_MAX_LOAD_VAL) / (f32)1000;
        
        break;
    case Gpt_Timer2:
        elapsedTime = (((f32)(Gpt_OV_tot_Cout[Gpt_Timer2]-Gpt_OV_Cout_remaining[Gpt_Timer2]) * (f32)Gpt_OV_Time_US[Gpt_Timer2]) + (f32)(GPT_TIMER2_MAX_LOAD_VAL - TCNT2 + Gpt_initialDelay[Gpt_Timer2]) * (f32)Gpt_OV_Time_US[Gpt_Timer2] / (f32)GPT_TIMER2_MAX_LOAD_VAL) / (f32)1000;
        break;
    default:
        break;
    }
    return elapsedTime;
}

/*
* the following function is used to calculate the 
	time remaining for the given timer before 
    reaching the provided time
* Args:         channel: channel no.
* Return:       time value
* example:
        Gpt_ValueType time Gpt_GetTimeRemaining(Gpt_Timer1);
*/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType channel)
{
    f32 remainingTime;
    switch (channel)
    {
    case Gpt_Timer0:
        remainingTime = (((f32)Gpt_OV_Cout_remaining[Gpt_Timer0] * (f32)Gpt_OV_Time_US[Gpt_Timer0]) + (f32)TCNT0 * (f32)Gpt_OV_Time_US[Gpt_Timer0] / (f32)GPT_TIMER0_MAX_LOAD_VAL) / (f32)1000;
        break;
    case Gpt_Timer1:
        remainingTime = (((f32)Gpt_OV_Cout_remaining[Gpt_Timer1] * (f32)Gpt_OV_Time_US[Gpt_Timer1]) + (f32)TCNT1 * (f32)Gpt_OV_Time_US[Gpt_Timer1] / (f32)GPT_TIMER1_MAX_LOAD_VAL) / (f32)1000;
        break;
    case Gpt_Timer2:
        remainingTime = (((f32)Gpt_OV_Cout_remaining[Gpt_Timer2] * (f32)Gpt_OV_Time_US[Gpt_Timer2]) + (f32)TCNT2 * (f32)Gpt_OV_Time_US[Gpt_Timer2] / (f32)GPT_TIMER2_MAX_LOAD_VAL) / (f32)1000;
        break;
    default:
        break;
    }
    return remainingTime;
}

/*
* the following function is used to start the 
    given timer
* Args:         channel: channel no.
*               timeMs: given time in milliseconds
* Return:       None
* example:
        Gpt_StartTimer(Gpt_Timer1,400);
*/
void Gpt_StartTimer(Gpt_ChannelType channel, Gpt_ValueType timeMs)
{
    Gpt_ValueType numOfOverflows;
    switch (channel)
    {
    case Gpt_Timer0:
        numOfOverflows = ( timeMs) / Gpt_OV_Time_US[Gpt_Timer0];
        PORTC =  CEIL(numOfOverflows);
        Gpt_OV_tot_Cout[Gpt_Timer0] = CEIL(numOfOverflows);
        Gpt_OV_Cout_remaining[Gpt_Timer0] = Gpt_OV_tot_Cout[Gpt_Timer0];
        Gpt_initialDelay[Gpt_Timer0] = GPT_TIMER0_MAX_LOAD_VAL * (Gpt_OV_tot_Cout[Gpt_Timer0] - numOfOverflows);
        TCNT0 = Gpt_initialDelay[Gpt_Timer0];
        TCCR0 |= Gpt_prescaler_val[Gpt_Timer0];
        break;

    case Gpt_Timer1:
        numOfOverflows = ( timeMs) / Gpt_OV_Time_US[Gpt_Timer1];
        Gpt_OV_tot_Cout[Gpt_Timer1] = CEIL(numOfOverflows);
        Gpt_OV_Cout_remaining[Gpt_Timer1] = Gpt_OV_tot_Cout[Gpt_Timer1];
        Gpt_initialDelay[Gpt_Timer1] = GPT_TIMER1_MAX_LOAD_VAL * (Gpt_OV_tot_Cout[Gpt_Timer1] - numOfOverflows);
        TCNT1L = Gpt_initialDelay[Gpt_Timer1];
        TCNT1H = Gpt_initialDelay[Gpt_Timer1] >> 8;
        TCCR1B |= Gpt_prescaler_val[Gpt_Timer1];
        break;
    
    case Gpt_Timer2:
        numOfOverflows = ( timeMs) / Gpt_OV_Time_US[Gpt_Timer2];
        Gpt_OV_tot_Cout[Gpt_Timer2] = CEIL(numOfOverflows);
        Gpt_OV_Cout_remaining[Gpt_Timer2] = Gpt_OV_tot_Cout[Gpt_Timer2];
        Gpt_initialDelay[Gpt_Timer2] = GPT_TIMER2_MAX_LOAD_VAL * (Gpt_OV_tot_Cout[Gpt_Timer2] - numOfOverflows);
        TCNT2 = Gpt_initialDelay[Gpt_Timer2];
        TCCR2 |= Gpt_prescaler_val[Gpt_Timer2];
        break;
    
    default:
        break;
    }
}

/*
* the following function is used to stop the 
    given timer
* Args:         channel: channel no.
* Return:       None
* example:
        Gpt_StopTimer(Gpt_Timer1);
*/
void Gpt_StopTimer(Gpt_ChannelType channel)
{
    switch (channel)
    {
    case Gpt_Timer0:
        TCCR0 &= GPT_PRESCALER_MASK;
        break;

    case Gpt_Timer1:
        TCCR1B &= GPT_PRESCALER_MASK;
        break;
    
    case Gpt_Timer2:
        TCCR2 &= GPT_PRESCALER_MASK;
        break;
    
    default:
        break;
    }
}

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

void Gpt_registerNotification(Gpt_ChannelType channel, Gpt_callbackFunctionType CBF)
{
    if (channel >= Gpt_Timer0 && channel <= Gpt_Timer2)
    {
        Gpt_callbackFunctions[channel] = CBF;
    }
}






ISR(TIMER0_OVF_vect)
{
    Gpt_OV_Cout_remaining[Gpt_Timer0]--;
    if (Gpt_OV_Cout_remaining[Gpt_Timer0] == 0)
    {
        // cal CBF
        Gpt_callbackFunctions[Gpt_Timer0]();
        // update ov count
        Gpt_OV_Cout_remaining[Gpt_Timer0] = Gpt_OV_tot_Cout[Gpt_Timer0];
        // update tcnt;
        TCNT0 = Gpt_initialDelay[Gpt_Timer0];
    }
}
ISR(TIMER1_OVF_vect)
{
    Gpt_OV_Cout_remaining[Gpt_Timer1]--;
    if (Gpt_OV_Cout_remaining[Gpt_Timer1] == 0)
    {
        // cal CBF
        Gpt_callbackFunctions[Gpt_Timer1]();
        // update ov count
        Gpt_OV_Cout_remaining[Gpt_Timer1] = Gpt_OV_tot_Cout[Gpt_Timer1];
        // update tcnt;
        TCNT1 = Gpt_initialDelay[Gpt_Timer1];
    }
}
ISR(TIMER2_OVF_vect)
{
    Gpt_OV_Cout_remaining[Gpt_Timer2]--;
    if (Gpt_OV_Cout_remaining[Gpt_Timer2] == 0)
    {
        // cal CBF
        Gpt_callbackFunctions[Gpt_Timer2]();
        // update ov count
        Gpt_OV_Cout_remaining[Gpt_Timer2] = Gpt_OV_tot_Cout[Gpt_Timer2];
        // update tcnt;
        TCNT2 = Gpt_initialDelay[Gpt_Timer2];
    }
}
