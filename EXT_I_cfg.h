/*
 * EXT_I_cfg.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Ahmed-Yehia
 */

#ifndef DRIVERS_EXT_I_CFG_H_
#define DRIVERS_EXT_I_CFG_H_

#include "EXT_I.h"

#define EXT_I_ENABLED_INT               EXT_I_INT_0 & EXT_I_INT_1 & EXT_I_INT_2

#define EXT_I_INT_0_CTRL                EXT_I_RISING_EDGE
#define EXT_I_INT_1_CTRL                EXT_I_RISING_EDGE
#define EXT_I_INT_2_CTRL                EXT_I_RISING_EDGE

#endif /* DRIVERS_EXT_I_CFG_H_ */
