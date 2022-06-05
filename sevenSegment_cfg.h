/*
 * sevenSegment_cfg.h
 *
 *  Created on: Mar 27, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef SEVENSEGMENT_CFG_H_
#define SEVENSEGMENT_CFG_H_


#define SEVSEG_u8TYPE                   SEVSEG_u8TYPE_CATHODE
#define SEVSEG_u8TaskPeriod_ms          2

// seg 0 is the left most digit
enum{
    SEVSEG_u8SEG_0,
    SEVSEG_u8SEG_1,
    SEVSEG_u8SEG_2,
    SEVSEG_u8SEG_3,
    SEVSEG_u8NUM_OF_SEGMENTS
};

#define SEVSEG_u8PIN_A                  DIO_u8PIN1
#define SEVSEG_u8PIN_B                  DIO_u8PIN0
#define SEVSEG_u8PIN_C                  DIO_u8PIN3
#define SEVSEG_u8PIN_D                  DIO_u8PIN4
#define SEVSEG_u8PIN_E                  DIO_u8PIN5
#define SEVSEG_u8PIN_F                  DIO_u8PIN7
#define SEVSEG_u8PIN_G                  DIO_u8PIN6
#define SEVSEG_u8PIN_DOT                DIO_u8PIN2

//#define SEVSEG_u8PIN_A                  DIO_u8PIN0
//#define SEVSEG_u8PIN_B                  DIO_u8PIN1
//#define SEVSEG_u8PIN_C                  DIO_u8PIN2
//#define SEVSEG_u8PIN_D                  DIO_u8PIN3
//#define SEVSEG_u8PIN_E                  DIO_u8PIN4
//#define SEVSEG_u8PIN_F                  DIO_u8PIN5
//#define SEVSEG_u8PIN_G                  DIO_u8PIN6
//#define SEVSEG_u8PIN_DOT                DIO_u8PIN7

#endif /* SEVENSEGMENT_CFG_H_ */
