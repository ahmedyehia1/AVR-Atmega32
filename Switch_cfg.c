/*
 * Switch_cfg.c
 *
 *  Created on: Apr 25, 2022
 *      Author: Ahmed-Yehia
 */

#include "Utils/Std_types.h"

#include "Dio.h"
#include "Switch_cfg.h"

const u8 Switch_au8PinConfig[Switch_count] = {
    [Switch_right_switch] = DIO_u8PIN31,
    [Switch_left_switch] = DIO_u8PIN30,
    [Switch_up_switch] = DIO_u8PIN29,
    [Switch_down_switch] = DIO_u8PIN28,
    [Switch_mode_switch] = DIO_u8PIN16,
};
