/*
 * ADC.c
 *
 *  Created on: Apr 4, 2022
 *      Author: Ahmed-Yehia
 */

#include "Utils/Bit_utils.h"
#include "Utils/Std_types.h"
#include "Dio.h"

#include "ADC.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"

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
void ADC_vidInit(void)
{
    #ifndef ADC_u8REF_SELECT
    #define ADC_u8REF_SELECT                        ADC_u8REF_SELECT_AVCC
    #warning "default configuration is applied to (ADC_u8REF_SELECT = ADC_u8REF_SELECT_AVCC)"
    #endif

    #ifndef ADC_u8ADJUSTMENT
    #define ADC_u8ADJUSTMENT                        ADC_u8ADJUST_RIGHT
    #warning "default configuration is applied to (ADC_u8ADJUSTMENT = ADC_u8ADJUST_RIGHT)"
    #endif

    #ifndef ADC_u8CHANNEL_SELECT
    #define ADC_u8CHANNEL_SELECT                    ADC_u8CHANNEL_SELECT_ADC0
    #warning "default configuration is applied to (ADC_u8CHANNEL_SELECT = ADC_u8CHANNEL_SELECT_ADC0)"
    #endif

    #ifndef ADC_u8INTERRUPT
    #define ADC_u8INTERRUPT                         ADC_u8INTERRUPT_DISABLE
    #warning "default configuration is applied to (ADC_u8INTERRUPT = ADC_u8INTERRUPT_DISABLE)"
    #endif

    #ifndef ADC_u8PRESCALER_VAL
    #define ADC_u8PRESCALER_VAL                     ADC_u8PRESCALER_VAL_2
    #warning "default configuration is applied to (ADC_u8PRESCALER_VAL = ADC_u8PRESCALER_VAL_2)"
    #endif

    #ifndef ADC_u8AUTO_TRIGGER_SRC
    #define ADC_u8AUTO_TRIGGER_SRC                  ADC_u8AUTO_TRIGGER_SRC_FREE_RUNNING
    #warning "default configuration is applied (ADC_u8AUTO_TRIGGER_SRC = ADC_u8AUTO_TRIGGER_SRC_FREE_RUNNING)"
    #endif

	
    ADMUX = 0x00;
    ADMUX |= (ADC_u8REF_SELECT | ADC_u8ADJUSTMENT | ADC_u8CHANNEL_SELECT);

    ADCSRA = 0x00;
    ADCSRA |= (ADC_u8ENABLE | ADC_u8INTERRUPT | ADC_u8PRESCALER_VAL);
    
    SFIOR = 0x00;
    SFIOR |= (ADC_u8AUTO_TRIGGER_SRC);

}

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
ADC_tenuErrorStatus ADC_enuSelectChannel(u8 Copy_u8ChannelId)
{
    ADC_tenuErrorStatus Loc_enuStatus = ADC_enuOK;
    if (Copy_u8ChannelId > ADC_u8CHANNEL_SELECT_GND)
    {
        Loc_enuStatus = ADC_enuInvalidChannelError;
    }
    else
    {
        ADMUX &= ADC_u8CHANNEL_SELECT_CLR_MASK;
        ADMUX |= Copy_u8ChannelId;
    }
    return Loc_enuStatus;
}

/*
* the following function is used to start the ADC process
* Args:
		None
* Return:
		None
* example:
		ADC_vidStartConversion();
*/
void ADC_vidStartConversion(void)
{
    ADCSRA |= ADC_u8START_CONVERSTION_ON;
}

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
ADC_tenuErrorStatus ADC_vidEndOfConversion(pu8 Copy_pu8Status)
{
    ADC_tenuErrorStatus Loc_enuStatus = ADC_enuOK;
    if (Copy_pu8Status == NULL)
    {
        Loc_enuStatus = ADC_enuNullPointerError;
    }
    else
    {
        *Copy_pu8Status = ((ADCSRA & ADC_u8INTERRUPT_FLAG_MASK) == ADC_u8INTERRUPT_FLAG_MASK);
    }
    return Loc_enuStatus;
}

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
ADC_tenuErrorStatus ADC_enuAnalogValue(pu16 Copy_pu16Value)
{
     ADC_tenuErrorStatus Loc_enuStatus = ADC_enuOK;
    if (Copy_pu16Value == NULL)
    {
        Loc_enuStatus = ADC_enuNullPointerError;
    }
    else
    {
        if ((ADCSRA & ADC_u8INTERRUPT_FLAG_MASK) == 0x00)
        {
            Loc_enuStatus = ADC_enuPending;
        }
        else
        {
            // OK
            if ((ADMUX & ADC_u8ADJUST_MASK) == ADC_u8ADJUST_RIGHT)
            {
                *Copy_pu16Value = (u16)((u16)ADCL | ((u16)ADCH<<8));
            }
            else
            {
                *Copy_pu16Value = (u16)(((u16)ADCL>>6) | ((u16)ADCH<<2));
            }
            // clear Interrupt flag
            ADCSRA &= ADC_u8INTERRUPT_FLAG_CLR_MASK;
        }
    }
    return Loc_enuStatus;
}
