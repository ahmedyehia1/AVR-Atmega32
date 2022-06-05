/*
 * ADC_prv.h
 *
 *  Created on: Apr 4, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef DRIVERS_ADC_PRV_H_
#define DRIVERS_ADC_PRV_H_

// Register addresses
#define ADCL                                                    (*(volatile u8*)0x24)
#define ADCH                                                    (*(volatile u8*)0x25)
#define ADCSRA                                                  (*(volatile u8*)0x26)
#define ADMUX                                                   (*(volatile u8*)0x27)
#define ACSR                                                    (*(volatile u8*)0x28)
#define SFIOR                                                   (*(volatile u8*)0x50)

// non-configurable parameters      
#define ADC_u8ENABLE                                            0x80

#define ADC_u8START_CONVERSTION_ON                              0x40

#define ADC_u8AUTO_TRIGGER_ON                                   0x20


#define ADC_u8REF_SELECT_MASK                                   0xC0
#define ADC_u8ADJUST_MASK                                       0x20
#define ADC_u8CHANNEL_SELECT_MASK                               0x1F
#define ADC_u8ENABLE_MASK                                       0x80
#define ADC_u8START_CONVERSTION_MASK                            0x40
#define ADC_u8AUTO_TRIGGER_MASK                                 0x20
#define ADC_u8INTERRUPT_FLAG_MASK                               0x10
#define ADC_u8PRESCALER_MASK                                    0x07
#define ADC_u8AUTO_TRIGGER_SRC_MASK                             0xE0

#define ADC_u8REF_SELECT_CLR_MASK                               0x3F
#define ADC_u8ADJUST_CLR_MASK                                   0xDF
#define ADC_u8CHANNEL_SELECT_CLR_MASK                           0xE0
#define ADC_u8ENABLE_CLR_MASK                                   0x7F
#define ADC_u8START_CONVERSTION_CLR_MASK                        0xBF
#define ADC_u8AUTO_TRIGGER_CLR_MASK                             0xDF
#define ADC_u8INTERRUPT_FLAG_CLR_MASK                           0xEF
#define ADC_u8PRESCALER_CLR_MASK                                0xF8
#define ADC_u8AUTO_TRIGGER_SRC_CLR_MASK                         0x1F


#endif /* DRIVERS_ADC_PRV_H_ */
