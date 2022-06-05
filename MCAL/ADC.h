/*
 * ADC.h
 *
 *  Created on: Apr 4, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef DRIVERS_ADC_H_
#define DRIVERS_ADC_H_

// configurable parameters      
#define ADC_u8REF_SELECT_OFF                                    0x00
#define ADC_u8REF_SELECT_AVCC                                   0x40
#define ADC_u8REF_SELECT_INTERNAL                               0xC0

#define ADC_u8ADJUST_RIGHT                                      0x00
#define ADC_u8ADJUST_LEFT                                       0x20

#define ADC_u8CHANNEL_SELECT_ADC0                               0x00
#define ADC_u8CHANNEL_SELECT_ADC1                               0x01
#define ADC_u8CHANNEL_SELECT_ADC2                               0x02
#define ADC_u8CHANNEL_SELECT_ADC3                               0x03
#define ADC_u8CHANNEL_SELECT_ADC4                               0x04
#define ADC_u8CHANNEL_SELECT_ADC5                               0x05
#define ADC_u8CHANNEL_SELECT_ADC6                               0x06
#define ADC_u8CHANNEL_SELECT_ADC7                               0x07
#define ADC_u8CHANNEL_SELECT_ADC0_GAIN_10                       0x08
#define ADC_u8CHANNEL_SELECT_ADC0_ADC1_GAIN_10                  0x09
#define ADC_u8CHANNEL_SELECT_ADC0_GAIN_200                      0x0A
#define ADC_u8CHANNEL_SELECT_ADC0_ADC1_GAIN_200                 0x0B
#define ADC_u8CHANNEL_SELECT_ADC2_GAIN_10                       0x0C
#define ADC_u8CHANNEL_SELECT_ADC2_ADC3_GAIN_10                  0x0D
#define ADC_u8CHANNEL_SELECT_ADC2_GAIN_200                      0x0E
#define ADC_u8CHANNEL_SELECT_ADC2_ADC3_GAIN_200                 0x0F
#define ADC_u8CHANNEL_SELECT_ADC0_ADC1                          0x10
#define ADC_u8CHANNEL_SELECT_ADC1_ADC1                          0x11
#define ADC_u8CHANNEL_SELECT_ADC2_ADC1                          0x12
#define ADC_u8CHANNEL_SELECT_ADC3_ADC1                          0x13
#define ADC_u8CHANNEL_SELECT_ADC4_ADC1                          0x14
#define ADC_u8CHANNEL_SELECT_ADC5_ADC1                          0x15
#define ADC_u8CHANNEL_SELECT_ADC6_ADC1                          0x16
#define ADC_u8CHANNEL_SELECT_ADC7_ADC1                          0x17
#define ADC_u8CHANNEL_SELECT_ADC0_ADC2                          0x18
#define ADC_u8CHANNEL_SELECT_ADC1_ADC2                          0x19
#define ADC_u8CHANNEL_SELECT_ADC2_ADC2                          0x1A
#define ADC_u8CHANNEL_SELECT_ADC3_ADC2                          0x1B
#define ADC_u8CHANNEL_SELECT_ADC4_ADC2                          0x1C
#define ADC_u8CHANNEL_SELECT_ADC5_ADC2                          0x1D
#define ADC_u8CHANNEL_SELECT_Vbg                                0x1E
#define ADC_u8CHANNEL_SELECT_GND                                0x1F


#define ADC_u8PRESCALER_VAL_2                                   0x00
#define ADC_u8PRESCALER_VAL_4                                   0x02
#define ADC_u8PRESCALER_VAL_8                                   0x03
#define ADC_u8PRESCALER_VAL_16                                  0x04
#define ADC_u8PRESCALER_VAL_32                                  0x05
#define ADC_u8PRESCALER_VAL_64                                  0x06
#define ADC_u8PRESCALER_VAL_128                                 0x07

#define ADC_u8INTERRUPT_DISABLE                                 0x00
#define ADC_u8INTERRUPT_ENABLE                                  0x08

#define ADC_u8AUTO_TRIGGER_SRC_FREE_RUNNING                     0x00
#define ADC_u8AUTO_TRIGGER_SRC_ANALOG_COMPARATOR                0x01
#define ADC_u8AUTO_TRIGGER_SRC_EX_IRQ_0                         0x02
#define ADC_u8AUTO_TRIGGER_SRC_TIMER_COUNTER0_MATCH             0x03
#define ADC_u8AUTO_TRIGGER_SRC_TIMER_COUNTER0_OVERFLOW          0x04
#define ADC_u8AUTO_TRIGGER_SRC_TIMER_COUNTER1_MATCH             0x05
#define ADC_u8AUTO_TRIGGER_SRC_TIMER_COUNTER1_OVERFLOW          0x06
#define ADC_u8AUTO_TRIGGER_SRC_TIMER_COUNTER1_CAPTURE_EVENT     0x07

/*
* the following enum type definition is used
 	as a returned error status from every 
	function usage:
		- ADC_tenuErrorStatus status = ADC_enuSelectChannel(----)
*/
typedef enum{
    ADC_enuOK,
    ADC_enuPending,
    ADC_enuNullPointerError,
    ADC_enuInvalidChannelError,
} ADC_tenuErrorStatus;

/*
* the following function is used to initialize the 
    ADC module with the initial configuration
    configuration parameters:
        - select reference type
        - select adjustment type (left or right adjustment)
        - select ADC channel
        -enable/disable interrupt
        -select prescaler value
        -select tigger source
* Args:
		None
* Return:
		None
* example:
		ADC_vidInit();
*/
void ADC_vidInit(void);

/*
* the following function is used to select new ADC channel
* Args:
		u8 Copy_u8ChannelId:        the ADC channel to be selected
* Return:
		ADC_tenuErrorStatus:        return status
* example:
		ADC_tenuErrorStatus status =
                ADC_enuSelectChannel(ADC_u8CHANNEL_SELECT_ADC3);
*/
ADC_tenuErrorStatus ADC_enuSelectChannel(u8 Copy_u8ChannelId);

/*
* the following function is used to start the ADC process
* Args:
		None
* Return:
		None
* example:
		ADC_vidStartConversion();
*/
void ADC_vidStartConversion(void);

/*
* the following function is used to end the ADC process (stop the ADC)
* Args:
		pu8 Copy_pu8Status: 		pointer to hold the status of the ADC conversion
* Return:
		ADC_tenuErrorStatus:		return status
* example:
		u8 ADC_status;
		ADC_tenuErrorStatus status =
				ADC_vidEndOfConversion(&ADC_status);
*/
ADC_tenuErrorStatus ADC_vidEndOfConversion(pu8 Copy_pu8Status);

/*
* the following function is used to get the analog value represented
    in a 10 bit value (based on the reference analog value) 
* Args:
		pu16 Copy_pu16Value:         pointer to variable to hold the ADC computed value
* Return:
		ADC_tenuErrorStatus:        return status
* example:
        u16 ADC_val;
		ADC_tenuErrorStatus status =
                ADC_enuAnalogValue(&ADC_val);
*/
ADC_tenuErrorStatus ADC_enuAnalogValue(pu16 Copy_pu16Value);

#endif /* DRIVERS_ADC_H_ */
