/*
 * EXT_I_prv.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef DRIVERS_EXT_I_PRV_H_
#define DRIVERS_EXT_I_PRV_H_

// register addresses
#define MCUCSR                          (*(volatile u8*)0x54)
#define MCUCR                           (*(volatile u8*)0x55)
#define GICR                            (*(volatile u8*)0x5B)
#define GIFR                            (*(volatile u8*)0x5A)

// private masks
#define EXT_I_ENABLE_MASK               0x1F
#define EXT_I_INT_0_CTRL_MASK           0xFC
#define EXT_I_INT_1_CTRL_MASK           0xF3
#define EXT_I_INT_2_CTRL_MASK           0xBF

#define EXT_I_INT_0_CTRL_OFFSET         0
#define EXT_I_INT_1_CTRL_OFFSET         2
#define EXT_I_INT_2_CTRL_OFFSET         6


#endif /* DRIVERS_EXT_I_PRV_H_ */
