/*
 * port_prv.h
 *
 *  Created on: Mar 5, 2022
 *      Author: Ahmed Yehia
 */

#ifndef PORT_PRV_H_
#define PORT_PRV_H_

/*
* Register Addresses
*/
#define DDRA                              (*(volatile u8*)0x3A)
#define DDRB                              (*(volatile u8*)0x37)
#define DDRC                              (*(volatile u8*)0x34)
#define DDRD                              (*(volatile u8*)0x31)

#define PORTA                             (*(volatile u8*)0x3B)
#define PORTB                             (*(volatile u8*)0x38)
#define PORTC                             (*(volatile u8*)0x35)
#define PORTD                             (*(volatile u8*)0x32)

#define PINA                              (*(volatile u8*)0x39)
#define PINB                              (*(volatile u8*)0x36)
#define PINC                              (*(volatile u8*)0x33)
#define PIND                              (*(volatile u8*)0x30)


/*
* the following definitions are used on:
      - Port_enuSetPinDirection()
      - Port_enuSetPinMode()
*/
#define Port_u8NumOfPins 			32
#define Port_u8PortSize		 		8

/*
* the following definitions are used on:
      - Port_enuSetPinDirection()
*/
#define Port_u8DirectionStates		2

/*
* the following definitions are used on:
      - Port_enuSetPinMode()
*/
#define Port_u8ModeStates			4

/*
* the following definitions are used to
   configure the direction and the mode 
   of each pin, used on:
      - Port_vidInit()
*/
#define Port_u8PULL_UP 					1
#define Port_u8HIGH_IMP 				0
#define Port_u8LOW 			    		0
#define Port_u8HIGH 		    	    1

/*
* the following definitions are used
    as a default pins configuration:
*/
#define Port_u8prv_CFG_Pin0             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin1             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin2             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin3             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin4             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin5             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin6             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin7             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin8             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin9             Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin10            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin11            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin12            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin13            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin14            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin15            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin16            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin17            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin18            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin19            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin20            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin21            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin22            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin23            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin24            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin25            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin26            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin27            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin28            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin29            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin30            Port_u8OUTPUT_LOW
#define Port_u8prv_CFG_Pin31            Port_u8OUTPUT_LOW

/*
* the following definitions are the
    actual macros used in direction
    and mode configuration:
*/
#define Port_u8prv_CFG_PIN0_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN0_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN1_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN1_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN2_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN2_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN3_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN3_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN4_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN4_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN5_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN5_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN6_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN6_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN7_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN7_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN8_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN8_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN9_DIR	        Port_u8OUTPUT
#define Port_u8prv_CFG_PIN9_MODE        Port_u8LOW
#define Port_u8prv_CFG_PIN10_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN10_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN11_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN11_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN12_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN12_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN13_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN13_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN14_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN14_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN15_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN15_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN16_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN16_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN17_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN17_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN18_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN18_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN19_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN19_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN20_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN20_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN21_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN21_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN22_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN22_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN23_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN23_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN24_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN24_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN25_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN25_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN26_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN26_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN27_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN27_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN28_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN28_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN29_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN29_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN30_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN30_MODE       Port_u8LOW
#define Port_u8prv_CFG_PIN31_DIR	    Port_u8OUTPUT
#define Port_u8prv_CFG_PIN31_MODE       Port_u8LOW

/*
* the following enum type definition is used
 	to identify each port provided from the
 	given Pin Number
*/
typedef enum{
    Port_enuPortAId,
    Port_enuPortBId,
    Port_enuPortCId,
    Port_enuPortDId
} Port_tenuPortId;

#endif /* PORT_PRV_H_ */
