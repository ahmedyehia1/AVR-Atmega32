/*
 * Lcd_prv.h
 *
 *  Created on: Mar 15, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef LCD_PRV_H_
#define LCD_PRV_H_

#define LCD_u8CMD__CLR_SCRN_CFG				0x01
#define LCD_u8CMD__NUM_2_ASCII				0x30

u16 Lcd_u16Ascii2Signal(u8 Copy_u8Char);

#endif /* LCD_PRV_H_ */                 
