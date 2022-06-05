/*
 * sevenSegment_cfg.c
 *
 *  Created on: Mar 27, 2022
 *      Author: Ahmed-Yehia
 */

#include "Utils/Std_types.h"

#include "Dio.h"
#include "sevenSegment.h"
#include "sevenSegment_cfg.h"


SevenSeg_strtSegConfig SevenSeg_strPinsConfig[SEVSEG_u8NUM_OF_SEGMENTS] = {

    [SEVSEG_u8SEG_0] = {
    		.pin = DIO_u8PIN25,
			.type = SEVSEG_u8TYPE_ANODE
    },
    [SEVSEG_u8SEG_1] = {
    		.pin = DIO_u8PIN24,
			.type = SEVSEG_u8TYPE_ANODE
    },
    [SEVSEG_u8SEG_2] = {
    		.pin = DIO_u8PIN26,
			.type = SEVSEG_u8TYPE_CATHODE
    },
    [SEVSEG_u8SEG_3] = {
    		.pin = DIO_u8PIN27,
			.type = SEVSEG_u8TYPE_CATHODE
    },
};
