/*
 * Dio_prv.h
 *
 *  Created on: Mar 5, 2022
 *      Author: Ahmed Yehia
 */

#ifndef DIO_PRV_H_
#define DIO_PRV_H_
/*
* private Constants
*/

/*
* Register Addresses
*/
#define DDRA                              (*(volatile u8*)0x3A)
#define DDRB                              (*(volatile u8*)0x37)
#define DDRC                              (*(volatile u8*)0x34)
#define DDRD                              (*(volatile u8*)0x31)

/*
* the following definitions are used on:
      - Dio_enuWriteChannel()
      - Dio_enuReadChannel()
      - Dio_enuFlipChannel()
*/
#define Dio_u8NumOfPins 			32
#define Dio_u8PortSize		 		8

#endif /* DIO_PRV_H_ */
