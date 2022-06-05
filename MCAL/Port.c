/*
 * port.c
 *
 *  Created on: Mar 5, 2022
 *      Author: Ahmed Yehia
 */

// #include <avr/io.h>
#include "Utils/Std_types.h"
#include "Utils/Bit_utils.h"

#include "Port.h"
#include "Port_prv.h"
#include "Port_cfg.h"

#ifndef POINTLESS_MACRO_FOR_COLLAPSING_THE_NEXT_672_LINE
#ifndef Port_u8PIN_0_INIT_CFG
    #define Port_u8PIN_0_INIT_CFG		Port_u8prv_CFG_PIN0
    #warning "default configuration is applied on Pin 0"
#else
    #undef Port_u8prv_CFG_PIN0_DIR
    #undef Port_u8prv_CFG_PIN0_MODE
    #if Port_u8PIN_0_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN0_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN0_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_0_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN0_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN0_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_0_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN0_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN0_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN0_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN0_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_1_INIT_CFG
    #define Port_u8PIN_1_INIT_CFG		Port_u8prv_CFG_PIN1
    #warning "default configuration is applied on Pin 1"
#else
    #undef Port_u8prv_CFG_PIN1_DIR
    #undef Port_u8prv_CFG_PIN1_MODE
    #if Port_u8PIN_1_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN1_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN1_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_1_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN1_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN1_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_1_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN1_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN1_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN1_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN1_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_2_INIT_CFG
    #define Port_u8PIN_2_INIT_CFG		Port_u8prv_CFG_PIN2
    #warning "default configuration is applied on Pin 2"
#else
    #undef Port_u8prv_CFG_PIN2_DIR
    #undef Port_u8prv_CFG_PIN2_MODE
    #if Port_u8PIN_2_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN2_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN2_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_2_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN2_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN2_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_2_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN2_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN2_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN2_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN2_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_3_INIT_CFG
    #define Port_u8PIN_3_INIT_CFG		Port_u8prv_CFG_PIN3
    #warning "default configuration is applied on Pin 3"
#else
    #undef Port_u8prv_CFG_PIN3_DIR
    #undef Port_u8prv_CFG_PIN3_MODE
    #if Port_u8PIN_3_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN3_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN3_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_3_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN3_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN3_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_3_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN3_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN3_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN3_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN3_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_4_INIT_CFG
    #define Port_u8PIN_4_INIT_CFG		Port_u8prv_CFG_PIN4
    #warning "default configuration is applied on Pin 4"
#else
    #undef Port_u8prv_CFG_PIN4_DIR
    #undef Port_u8prv_CFG_PIN4_MODE
    #if Port_u8PIN_4_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN4_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN4_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_4_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN4_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN4_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_4_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN4_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN4_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN4_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN4_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_5_INIT_CFG
    #define Port_u8PIN_5_INIT_CFG		Port_u8prv_CFG_PIN5
    #warning "default configuration is applied on Pin 5"
#else
    #undef Port_u8prv_CFG_PIN5_DIR
    #undef Port_u8prv_CFG_PIN5_MODE
    #if Port_u8PIN_5_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN5_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN5_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_5_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN5_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN5_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_5_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN5_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN5_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN5_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN5_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_6_INIT_CFG
    #define Port_u8PIN_6_INIT_CFG		Port_u8prv_CFG_PIN6
    #warning "default configuration is applied on Pin 6"
#else
    #undef Port_u8prv_CFG_PIN6_DIR
    #undef Port_u8prv_CFG_PIN6_MODE
    #if Port_u8PIN_6_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN6_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN6_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_6_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN6_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN6_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_6_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN6_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN6_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN6_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN6_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_7_INIT_CFG
    #define Port_u8PIN_7_INIT_CFG		Port_u8prv_CFG_PIN7
    #warning "default configuration is applied on Pin 7"
#else
    #undef Port_u8prv_CFG_PIN7_DIR
    #undef Port_u8prv_CFG_PIN7_MODE
    #if Port_u8PIN_7_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN7_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN7_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_7_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN7_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN7_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_7_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN7_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN7_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN7_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN7_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_8_INIT_CFG
    #define Port_u8PIN_8_INIT_CFG		Port_u8prv_CFG_PIN8
    #warning "default configuration is applied on Pin 8"
#else
    #undef Port_u8prv_CFG_PIN8_DIR
    #undef Port_u8prv_CFG_PIN8_MODE
    #if Port_u8PIN_8_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN8_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN8_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_8_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN8_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN8_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_8_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN8_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN8_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN8_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN8_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_9_INIT_CFG
    #define Port_u8PIN_9_INIT_CFG		Port_u8prv_CFG_PIN9
    #warning "default configuration is applied on Pin 9"
#else
    #undef Port_u8prv_CFG_PIN9_DIR
    #undef Port_u8prv_CFG_PIN9_MODE
    #if Port_u8PIN_9_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN9_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN9_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_9_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN9_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN9_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_9_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN9_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN9_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN9_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN9_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_10_INIT_CFG
    #define Port_u8PIN_10_INIT_CFG		Port_u8prv_CFG_PIN10
    #warning "default configuration is applied on Pin 10"
#else
    #undef Port_u8prv_CFG_PIN10_DIR
    #undef Port_u8prv_CFG_PIN10_MODE
    #if Port_u8PIN_10_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN10_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN10_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_10_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN10_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN10_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_10_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN10_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN10_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN10_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN10_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_11_INIT_CFG
    #define Port_u8PIN_11_INIT_CFG		Port_u8prv_CFG_PIN11
    #warning "default configuration is applied on Pin 11"
#else
    #undef Port_u8prv_CFG_PIN11_DIR
    #undef Port_u8prv_CFG_PIN11_MODE
    #if Port_u8PIN_11_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN11_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN11_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_11_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN11_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN11_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_11_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN11_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN11_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN11_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN11_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_12_INIT_CFG
    #define Port_u8PIN_12_INIT_CFG		Port_u8prv_CFG_PIN12
    #warning "default configuration is applied on Pin 12"
#else
    #undef Port_u8prv_CFG_PIN12_DIR
    #undef Port_u8prv_CFG_PIN12_MODE
    #if Port_u8PIN_12_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN12_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN12_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_12_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN12_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN12_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_12_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN12_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN12_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN12_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN12_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_13_INIT_CFG
    #define Port_u8PIN_13_INIT_CFG		Port_u8prv_CFG_PIN13
    #warning "default configuration is applied on Pin 13"
#else
    #undef Port_u8prv_CFG_PIN13_DIR
    #undef Port_u8prv_CFG_PIN13_MODE
    #if Port_u8PIN_13_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN13_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN13_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_13_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN13_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN13_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_13_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN13_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN13_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN13_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN13_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_14_INIT_CFG
    #define Port_u8PIN_14_INIT_CFG		Port_u8prv_CFG_PIN14
    #warning "default configuration is applied on Pin 14"
#else
    #undef Port_u8prv_CFG_PIN14_DIR
    #undef Port_u8prv_CFG_PIN14_MODE
    #if Port_u8PIN_14_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN14_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN14_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_14_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN14_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN14_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_14_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN14_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN14_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN14_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN14_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_15_INIT_CFG
    #define Port_u8PIN_15_INIT_CFG		Port_u8prv_CFG_PIN15
    #warning "default configuration is applied on Pin 15"
#else
    #undef Port_u8prv_CFG_PIN15_DIR
    #undef Port_u8prv_CFG_PIN15_MODE
    #if Port_u8PIN_15_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN15_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN15_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_15_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN15_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN15_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_15_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN15_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN15_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN15_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN15_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_16_INIT_CFG
    #define Port_u8PIN_16_INIT_CFG		Port_u8prv_CFG_PIN16
    #warning "default configuration is applied on Pin 16"
#else
    #undef Port_u8prv_CFG_PIN16_DIR
    #undef Port_u8prv_CFG_PIN16_MODE
    #if Port_u8PIN_16_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN16_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN16_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_16_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN16_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN16_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_16_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN16_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN16_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN16_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN16_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_17_INIT_CFG
    #define Port_u8PIN_17_INIT_CFG		Port_u8prv_CFG_PIN17
    #warning "default configuration is applied on Pin 17"
#else
    #undef Port_u8prv_CFG_PIN17_DIR
    #undef Port_u8prv_CFG_PIN17_MODE
    #if Port_u8PIN_17_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN17_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN17_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_17_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN17_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN17_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_17_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN17_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN17_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN17_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN17_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_18_INIT_CFG
    #define Port_u8PIN_18_INIT_CFG		Port_u8prv_CFG_PIN18
    #warning "default configuration is applied on Pin 18"
#else
    #undef Port_u8prv_CFG_PIN18_DIR
    #undef Port_u8prv_CFG_PIN18_MODE
    #if Port_u8PIN_18_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN18_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN18_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_18_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN18_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN18_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_18_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN18_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN18_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN18_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN18_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_19_INIT_CFG
    #define Port_u8PIN_19_INIT_CFG		Port_u8prv_CFG_PIN19
    #warning "default configuration is applied on Pin 19"
#else
    #undef Port_u8prv_CFG_PIN19_DIR
    #undef Port_u8prv_CFG_PIN19_MODE
    #if Port_u8PIN_19_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN19_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN19_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_19_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN19_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN19_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_19_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN19_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN19_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN19_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN19_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_20_INIT_CFG
    #define Port_u8PIN_20_INIT_CFG		Port_u8prv_CFG_PIN20
    #warning "default configuration is applied on Pin 20"
#else
    #undef Port_u8prv_CFG_PIN20_DIR
    #undef Port_u8prv_CFG_PIN20_MODE
    #if Port_u8PIN_20_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN20_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN20_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_20_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN20_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN20_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_20_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN20_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN20_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN20_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN20_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_21_INIT_CFG
    #define Port_u8PIN_21_INIT_CFG		Port_u8prv_CFG_PIN21
    #warning "default configuration is applied on Pin 21"
#else
    #undef Port_u8prv_CFG_PIN21_DIR
    #undef Port_u8prv_CFG_PIN21_MODE
    #if Port_u8PIN_21_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN21_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN21_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_21_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN21_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN21_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_21_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN21_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN21_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN21_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN21_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_22_INIT_CFG
    #define Port_u8PIN_22_INIT_CFG		Port_u8prv_CFG_PIN22
    #warning "default configuration is applied on Pin 22"
#else
    #undef Port_u8prv_CFG_PIN22_DIR
    #undef Port_u8prv_CFG_PIN22_MODE
    #if Port_u8PIN_22_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN22_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN22_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_22_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN22_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN22_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_22_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN22_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN22_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN22_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN22_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_23_INIT_CFG
    #define Port_u8PIN_23_INIT_CFG		Port_u8prv_CFG_PIN23
    #warning "default configuration is applied on Pin 23"
#else
    #undef Port_u8prv_CFG_PIN23_DIR
    #undef Port_u8prv_CFG_PIN23_MODE
    #if Port_u8PIN_23_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN23_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN23_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_23_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN23_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN23_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_23_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN23_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN23_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN23_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN23_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_24_INIT_CFG
    #define Port_u8PIN_24_INIT_CFG		Port_u8prv_CFG_PIN24
    #warning "default configuration is applied on Pin 24"
#else
    #undef Port_u8prv_CFG_PIN24_DIR
    #undef Port_u8prv_CFG_PIN24_MODE
    #if Port_u8PIN_24_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN24_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN24_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_24_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN24_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN24_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_24_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN24_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN24_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN24_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN24_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_25_INIT_CFG
    #define Port_u8PIN_25_INIT_CFG		Port_u8prv_CFG_PIN25
    #warning "default configuration is applied on Pin 25"
#else
    #undef Port_u8prv_CFG_PIN25_DIR
    #undef Port_u8prv_CFG_PIN25_MODE
    #if Port_u8PIN_25_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN25_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN25_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_25_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN25_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN25_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_25_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN25_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN25_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN25_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN25_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_26_INIT_CFG
    #define Port_u8PIN_26_INIT_CFG		Port_u8prv_CFG_PIN26
    #warning "default configuration is applied on Pin 26"
#else
    #undef Port_u8prv_CFG_PIN26_DIR
    #undef Port_u8prv_CFG_PIN26_MODE
    #if Port_u8PIN_26_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN26_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN26_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_26_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN26_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN26_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_26_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN26_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN26_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN26_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN26_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_27_INIT_CFG
    #define Port_u8PIN_27_INIT_CFG		Port_u8prv_CFG_PIN27
    #warning "default configuration is applied on Pin 27"
#else
    #undef Port_u8prv_CFG_PIN27_DIR
    #undef Port_u8prv_CFG_PIN27_MODE
    #if Port_u8PIN_27_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN27_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN27_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_27_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN27_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN27_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_27_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN27_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN27_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN27_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN27_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_28_INIT_CFG
    #define Port_u8PIN_28_INIT_CFG		Port_u8prv_CFG_PIN28
    #warning "default configuration is applied on Pin 28"
#else
    #undef Port_u8prv_CFG_PIN28_DIR
    #undef Port_u8prv_CFG_PIN28_MODE
    #if Port_u8PIN_28_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN28_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN28_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_28_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN28_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN28_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_28_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN28_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN28_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN28_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN28_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_29_INIT_CFG
    #define Port_u8PIN_29_INIT_CFG		Port_u8prv_CFG_PIN29
    #warning "default configuration is applied on Pin 29"
#else
    #undef Port_u8prv_CFG_PIN29_DIR
    #undef Port_u8prv_CFG_PIN29_MODE
    #if Port_u8PIN_29_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN29_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN29_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_29_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN29_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN29_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_29_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN29_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN29_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN29_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN29_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_30_INIT_CFG
    #define Port_u8PIN_30_INIT_CFG		Port_u8prv_CFG_PIN30
    #warning "default configuration is applied on Pin 30"
#else
    #undef Port_u8prv_CFG_PIN30_DIR
    #undef Port_u8prv_CFG_PIN30_MODE
    #if Port_u8PIN_30_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN30_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN30_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_30_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN30_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN30_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_30_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN30_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN30_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN30_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN30_MODE	    Port_u8HIGH	
    #endif
#endif

#ifndef Port_u8PIN_31_INIT_CFG
    #define Port_u8PIN_31_INIT_CFG		Port_u8prv_CFG_PIN31
    #warning "default configuration is applied on Pin 31"
#else
    #undef Port_u8prv_CFG_PIN31_DIR
    #undef Port_u8prv_CFG_PIN31_MODE
    #if Port_u8PIN_31_INIT_CFG == Port_u8INPUT_HIGH_IMP
        #define Port_u8prv_CFG_PIN31_DIR	    Port_u8INPUT
        #define Port_u8prv_CFG_PIN31_MODE	    Port_u8HIGH_IMP
    #elif Port_u8PIN_31_INIT_CFG == Port_u8INPUT_PULL_UP
        #define Port_u8prv_CFG_PIN31_DIR       Port_u8INPUT
        #define Port_u8prv_CFG_PIN31_MODE	    Port_u8PULL_UP
    #elif Port_u8PIN_31_INIT_CFG == Port_u8OUTPUT_LOW
        #define Port_u8prv_CFG_PIN31_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN31_MODE	    Port_u8LOW
    #else // Port_u8OUTPUT_HIGH
        #define Port_u8prv_CFG_PIN31_DIR		Port_u8OUTPUT
        #define Port_u8prv_CFG_PIN31_MODE	    Port_u8HIGH	
    #endif
#endif
#endif

/*
* the following function is used to put the 
*	initial configuration parameters
* Args: 		None
* Return:		None
*/
void Port_vidInit(void)
{
	DDRA = CONC(
		Port_u8prv_CFG_PIN7_DIR,Port_u8prv_CFG_PIN6_DIR,
		Port_u8prv_CFG_PIN5_DIR,Port_u8prv_CFG_PIN4_DIR,
		Port_u8prv_CFG_PIN3_DIR,Port_u8prv_CFG_PIN2_DIR,
		Port_u8prv_CFG_PIN1_DIR,Port_u8prv_CFG_PIN0_DIR
		);
	DDRB = CONC(
		Port_u8prv_CFG_PIN15_DIR,Port_u8prv_CFG_PIN14_DIR,
		Port_u8prv_CFG_PIN13_DIR,Port_u8prv_CFG_PIN12_DIR,
		Port_u8prv_CFG_PIN11_DIR,Port_u8prv_CFG_PIN10_DIR,
		Port_u8prv_CFG_PIN9_DIR,Port_u8prv_CFG_PIN8_DIR
		);
	DDRC = CONC(
		Port_u8prv_CFG_PIN23_DIR,Port_u8prv_CFG_PIN22_DIR,
		Port_u8prv_CFG_PIN21_DIR,Port_u8prv_CFG_PIN20_DIR,
		Port_u8prv_CFG_PIN19_DIR,Port_u8prv_CFG_PIN18_DIR,
		Port_u8prv_CFG_PIN17_DIR,Port_u8prv_CFG_PIN16_DIR
		);
	DDRD = CONC(
		Port_u8prv_CFG_PIN31_DIR,Port_u8prv_CFG_PIN30_DIR,
		Port_u8prv_CFG_PIN29_DIR,Port_u8prv_CFG_PIN28_DIR,
		Port_u8prv_CFG_PIN27_DIR,Port_u8prv_CFG_PIN26_DIR,
		Port_u8prv_CFG_PIN25_DIR,Port_u8prv_CFG_PIN24_DIR
		);

	
	PORTA = CONC(
		Port_u8prv_CFG_PIN7_MODE,Port_u8prv_CFG_PIN6_MODE,
		Port_u8prv_CFG_PIN5_MODE,Port_u8prv_CFG_PIN4_MODE,
		Port_u8prv_CFG_PIN3_MODE,Port_u8prv_CFG_PIN2_MODE,
		Port_u8prv_CFG_PIN1_MODE,Port_u8prv_CFG_PIN0_MODE
		);
	PORTB = CONC(
		Port_u8prv_CFG_PIN15_MODE,Port_u8prv_CFG_PIN14_MODE,
		Port_u8prv_CFG_PIN13_MODE,Port_u8prv_CFG_PIN12_MODE,
		Port_u8prv_CFG_PIN11_MODE,Port_u8prv_CFG_PIN10_MODE,
		Port_u8prv_CFG_PIN9_MODE,Port_u8prv_CFG_PIN8_MODE
		);
	PORTC = CONC(
		Port_u8prv_CFG_PIN23_MODE,Port_u8prv_CFG_PIN22_MODE,
		Port_u8prv_CFG_PIN21_MODE,Port_u8prv_CFG_PIN20_MODE,
		Port_u8prv_CFG_PIN19_MODE,Port_u8prv_CFG_PIN18_MODE,
		Port_u8prv_CFG_PIN17_MODE,Port_u8prv_CFG_PIN16_MODE
		);
	PORTD = CONC(
		Port_u8prv_CFG_PIN31_MODE,Port_u8prv_CFG_PIN30_MODE,
		Port_u8prv_CFG_PIN29_MODE,Port_u8prv_CFG_PIN28_MODE,
		Port_u8prv_CFG_PIN27_MODE,Port_u8prv_CFG_PIN26_MODE,
		Port_u8prv_CFG_PIN25_MODE,Port_u8prv_CFG_PIN24_MODE
		);

}

/*
* the following function is used to set
 	the Direction of a given pin,
	note: that if the provided pin number
	is not available, the function will
	report that error on the returned 
	status
* Args:
		u8 Copy_u8PinNum:		targeted Pin number
		u8 Copy_u8PinDirection:	pin configuration direction
* Return:
		Port_tenuErrorStatus: the Status of the function activity
* example:
		Port_tenuErrorStatus status = Port_enuSetPinDirection(Port_u8_PIN_30, Port_u8OUTPUT);
*/
Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum, u8 Copy_u8PinDirection)
{
	Port_tenuPortId Loc_u8Pin;
	u8 Loc_u8Port;
	Port_tenuErrorStatus Loc_enuStatus;

	if (Copy_u8PinNum >= Port_u8NumOfPins)
	{
		Loc_enuStatus = Port_enuPinError;
	}
	else if (Copy_u8PinDirection >= Port_u8DirectionStates)
	{
		Loc_enuStatus = Port_enuDirectionError;
	}
	else
	{
		Loc_u8Port = Copy_u8PinNum / Port_u8PortSize;
		Loc_u8Pin  = Copy_u8PinNum % Port_u8PortSize;
		switch (Loc_u8Port)
		{
		case Port_enuPortAId:
			if (Copy_u8PinDirection == Port_u8OUTPUT)
			{
				SET_BIT(DDRA,Loc_u8Pin);
			}
			else
			{
				CLR_BIT(DDRA,Loc_u8Pin);
			}
			break;
		case Port_enuPortBId:
			if (Copy_u8PinDirection == Port_u8OUTPUT)
			{
				SET_BIT(DDRB,Loc_u8Pin);
			}
			else
			{
				CLR_BIT(DDRB,Loc_u8Pin);
			}
			break;
		case Port_enuPortCId:
			if (Copy_u8PinDirection == Port_u8OUTPUT)
			{
				SET_BIT(DDRC,Loc_u8Pin);
			}
			else
			{
				CLR_BIT(DDRC,Loc_u8Pin);
			}
			break;
		case Port_enuPortDId:
			if (Copy_u8PinDirection == Port_u8OUTPUT)
			{
				SET_BIT(DDRD,Loc_u8Pin);
			}
			else
			{
				CLR_BIT(DDRD,Loc_u8Pin);
			}
			break;
		default:
			/* MISRA */
			break;
		}
	}
	return Loc_enuStatus;
}

/*
* the following function is used to set
 	the Direction and the mode of a given
	pin
	note: that if the provided pin number
	is not available, the function will
	report that error on the returned 
	status
* Args:
		u8 Copy_u8PinNum:		targeted Pin number
		u8 Copy_u8PinMode:		pin configuration direction and mode
* Return:
		Port_tenuErrorStatus: the Status of the function activity
* example:
		Port_tenuErrorStatus status = Port_enuSetPinMode(Port_u8_PIN_25, Port_u8INPUT_PULL_UP);
*/
Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum, u8 Copy_u8PinMode)
{
	Port_tenuPortId Loc_u8Pin;
	u8 Loc_u8Port;
	Port_tenuErrorStatus Loc_enuStatus;

	if (Copy_u8PinNum >= Port_u8NumOfPins)
	{
		Loc_enuStatus = Port_enuPinError;
	}
	else if (Copy_u8PinMode >= Port_u8ModeStates)
	{
		Loc_enuStatus = Port_enuModeError;
	}
	else
	{
		Loc_u8Port = Copy_u8PinNum / Port_u8PortSize;
		Loc_u8Pin  = Copy_u8PinNum % Port_u8PortSize;
		switch (Loc_u8Port)
		{
		case Port_enuPortAId:
			switch (Copy_u8PinMode)
			{
			case Port_u8INPUT_PULL_UP:
				CLR_BIT(DDRA,Loc_u8Pin);
				SET_BIT(PORTA,Loc_u8Pin);
				break;
			case Port_u8INPUT_HIGH_IMP:
				CLR_BIT(DDRA,Loc_u8Pin);
				CLR_BIT(PORTA,Loc_u8Pin);
				break;
			case Port_u8OUTPUT_HIGH:
				SET_BIT(DDRA,Loc_u8Pin);
				SET_BIT(PORTA,Loc_u8Pin);
				break;
			case Port_u8OUTPUT_LOW:
				SET_BIT(DDRA,Loc_u8Pin);
				CLR_BIT(PORTA,Loc_u8Pin);
				break;
			default:
				/* MISRA */
				break;
			}
			break;
		case Port_enuPortBId:
			switch (Copy_u8PinMode)
			{
			case Port_u8INPUT_PULL_UP:
				CLR_BIT(DDRB,Loc_u8Pin);
				SET_BIT(PORTB,Loc_u8Pin);
				break;
			case Port_u8INPUT_HIGH_IMP:
				CLR_BIT(DDRB,Loc_u8Pin);
				CLR_BIT(PORTB,Loc_u8Pin);
				break;
			case Port_u8OUTPUT_HIGH:
				SET_BIT(DDRB,Loc_u8Pin);
				SET_BIT(PORTB,Loc_u8Pin);
				break;
			case Port_u8OUTPUT_LOW:
				SET_BIT(DDRB,Loc_u8Pin);
				CLR_BIT(PORTB,Loc_u8Pin);
				break;
			default:
				/* MISRA */
				break;
			}
			break;
		case Port_enuPortCId:
			switch (Copy_u8PinMode)
			{
			case Port_u8INPUT_PULL_UP:
				CLR_BIT(DDRC,Loc_u8Pin);
				SET_BIT(PORTC,Loc_u8Pin);
				break;
			case Port_u8INPUT_HIGH_IMP:
				CLR_BIT(DDRC,Loc_u8Pin);
				CLR_BIT(PORTC,Loc_u8Pin);
				break;
			case Port_u8OUTPUT_HIGH:
				SET_BIT(DDRC,Loc_u8Pin);
				SET_BIT(PORTC,Loc_u8Pin);
				break;
			case Port_u8OUTPUT_LOW:
				SET_BIT(DDRC,Loc_u8Pin);
				CLR_BIT(PORTC,Loc_u8Pin);
				break;
			default:
				/* MISRA */
				break;
			}
			break;
		case Port_enuPortDId:
			switch (Copy_u8PinMode)
			{
			case Port_u8INPUT_PULL_UP:
				CLR_BIT(DDRD,Loc_u8Pin);
				SET_BIT(PORTD,Loc_u8Pin);
				break;
			case Port_u8INPUT_HIGH_IMP:
				CLR_BIT(DDRD,Loc_u8Pin);
				CLR_BIT(PORTD,Loc_u8Pin);
				break;
			case Port_u8OUTPUT_HIGH:
				SET_BIT(DDRD,Loc_u8Pin);
				SET_BIT(PORTD,Loc_u8Pin);
				break;
			case Port_u8OUTPUT_LOW:
				SET_BIT(DDRD,Loc_u8Pin);
				CLR_BIT(PORTD,Loc_u8Pin);
				break;
			default:
				/* MISRA */
				break;
			}
			break;
		default:
			/* MISRA */
			break;
		}
	}
	return Loc_enuStatus;
}
