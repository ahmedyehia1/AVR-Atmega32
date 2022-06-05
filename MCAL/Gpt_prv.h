/*
 * Gpt_prv.h
 *
 *  Created on: Apr 15, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef GPT_PRV_H_
#define GPT_PRV_H_

#define GPT_TIMER_0_2_MASK                              0x80
#define GPT_TIMER_1A_MASK                               0x0C
#define GPT_TIMER_1B_MASK                               0xE0

#define GPT_PRESCALER_MASK                              0x07

#define GPT_TIMER0_MAX_LOAD_VAL                         256
#define GPT_TIMER1_MAX_LOAD_VAL                         65536
#define GPT_TIMER2_MAX_LOAD_VAL                         256

#define GPT_TIMER0_OV_INTERRUPT_EN                      0x01
#define GPT_TIMER1_OV_INTERRUPT_EN                      0x04
#define GPT_TIMER2_OV_INTERRUPT_EN                      0x40


/*
* Register Addresses
*/
#define TCCR0                              (*(volatile u8*)0x53)
#define TCNT0                              (*(volatile u8*)0x52)
#define OCR0                              (*(volatile u8*)0x5C)

#define TCCR1A                              (*(volatile u8*)0x4F)
#define TCCR1B                              (*(volatile u8*)0x4E)
#define TCNT1H                              (*(volatile u8*)0x4D)
#define TCNT1L                              (*(volatile u8*)0x4C)
#define OCR1AH                             (*(volatile u8*)0x4B)
#define OCR1AL                             (*(volatile u8*)0x4A)
#define OCR1BH                             (*(volatile u8*)0x49)
#define OCR1BL                             (*(volatile u8*)0x48)
#define ICR1H                             (*(volatile u8*)0x47)
#define ICR1L                             (*(volatile u8*)0x46)

#define TCCR2                              (*(volatile u8*)0x45)
#define TCNT2                              (*(volatile u8*)0x44)
#define OCR2                             (*(volatile u8*)0x43)

#define TIMSK                              (*(volatile u8*)0x59)
#define TIFR                              (*(volatile u8*)0x58)

#endif