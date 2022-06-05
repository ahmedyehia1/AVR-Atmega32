/*
 * Lcd_cfg.h
 *
 *  Created on: Mar 15, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_u8EN_PIN                    DIO_u8PIN8
#define LCD_u8RW_PIN                    DIO_u8PIN10
#define LCD_u8RS_PIN                    DIO_u8PIN9

#define LCD_u8D0_PIN                    DIO_u8PIN16
#define LCD_u8D1_PIN                    DIO_u8PIN17
#define LCD_u8D2_PIN                    DIO_u8PIN18
#define LCD_u8D3_PIN                    DIO_u8PIN19
#define LCD_u8D4_PIN                    DIO_u8PIN20
#define LCD_u8D5_PIN                    DIO_u8PIN21
#define LCD_u8D6_PIN                    DIO_u8PIN22
#define LCD_u8D7_PIN                    DIO_u8PIN23

// remember: default config is needed here
#define LCD_u8MODE_CFG                 LCD_u8CMD__MODE_8_BIT_2_LINE_5_7_FONT
#define LCD_u8DIPLAY_CFG               LCD_u8CMD__DISPLAY_ON_CURSOR_OFF
#define LCD_u8CURSOR_AND_SHIFT_CFG     LCD_u8CMD__CURSOR_INC_SCEERN_SHIFT_OFF


#endif /* LCD_CFG_H_ */
