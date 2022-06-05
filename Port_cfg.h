/*
 * port_cfg.h
 *
 *  Created on: Mar 5, 2022
 *      Author: Ahmed Yehia
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
* the following definitions are used for 
    configuring each pin on each port (0 : 31)
* please note that in case of removing any 
    definition the corresponding pin will 
    take the default configuration value
*/
#define Port_u8PIN_0_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_1_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_2_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_3_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_4_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_5_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_6_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_7_INIT_CFG 		Port_u8OUTPUT_LOW

#define Port_u8PIN_8_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_9_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_10_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_11_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_12_INIT_CFG 		Port_u8INPUT_PULL_UP			// SS
#define Port_u8PIN_13_INIT_CFG 		Port_u8INPUT_PULL_UP			// MOSI
#define Port_u8PIN_14_INIT_CFG 		Port_u8OUTPUT_LOW				// MISO
#define Port_u8PIN_15_INIT_CFG 		Port_u8INPUT_PULL_UP			// SCK

#define Port_u8PIN_16_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_17_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_18_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_19_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_20_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_21_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_22_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_23_INIT_CFG 		Port_u8OUTPUT_LOW

#define Port_u8PIN_24_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_25_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_26_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_27_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_28_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_29_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_30_INIT_CFG 		Port_u8OUTPUT_LOW
#define Port_u8PIN_31_INIT_CFG 		Port_u8OUTPUT_LOW


#endif /* PORT_CFG_H_ */
