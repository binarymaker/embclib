/**\cond
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) 2019 Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
\endcond */

#include "utils.h"
#include "utils-cfg.h"

static uint16_t _shift_reg_u16 = 0;

void
UTILS_RandSeed(uint16_t seed_i16)
{
  _shift_reg_u16 = seed_i16;
}

int16_t
UTILS_Rand_i16(int16_t min_i16, int16_t max_i16)
{
  int16_t range_i16;

  range_i16 = max_i16 - min_i16;

  _shift_reg_u16 = _shift_reg_u16 ^ POLYNOMIAL;
  _shift_reg_u16 = (_shift_reg_u16 >> 1) ^ (_shift_reg_u16 << 15);

  return (min_i16 + (_shift_reg_u16 % range_i16));
}

int16_t
UTILS_Scale_i16(int16_t in_value_i16, 
                int16_t in_min_i16, int16_t in_max_i16, 
                int16_t out_min_i16, int16_t out_max_i16)
{
  int16_t scaling_factor_i16;
  int16_t scaling_value_i16;

  scaling_factor_i16 = (out_max_i16 - out_min_i16) /
                        (in_max_i16 - in_min_i16);

  scaling_value_i16 = ((in_value_i16 - in_min_i16) * 
                        scaling_factor_i16) + out_min_i16;

  return (scaling_value_i16);
}
