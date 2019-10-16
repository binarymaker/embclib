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

/**
 * \file utils.h
 * \author Binary Maker (https://github.com/binarymaker)
 * \brief helper function
 * \date 2019-10-15
 */

#ifndef UTILS_af45c5ee_eb0b_11e9_8850_74dfbf0d835a
#define UTILS_af45c5ee_eb0b_11e9_8850_74dfbf0d835a

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __UTILS_VERSION      (0x0001u) /*!< version: 0.1v */

#include "stdint.h"

/**
 * \brief Find the smaller value
 * 
 */
#define Min(a, b)     (((a) < (b)) ? (a) : (b))

/**
 * \brief Find the greater value
 * 
 */
#define Max(a, b)     (((a) > (b)) ? (a) : (b))

/**
 * \brief convert negative value to non-negative value
 * 
 */
#define Abs(n)        ((n < 0) ? (-n) : (n))

/**
 * \brief Find the power of 2 of given value
 * 
 */
#define Pow2(x)       (1 << (x))

/**
 * \brief Swap/Exchange between the two values
 * 
 */
#define Swap(a,b)     ((a) ^= (b) ^= (a) ^= (b))

/**
 * \brief Limit value between maximum and minimum range
 * 
 */
#define Limit(val, min, max) (Min( Max(val, (min) ), (max) ))

/**
 * \brief Generate the random value between range
 * 
 * \param min_i16 [in] Minimum limit of random number
 * \param max_i16 [in] Maximum limit of random number
 * \return int16_t Random number
 */
int16_t
UTILS_Rand_i16(int16_t min_i16, int16_t max_i16);

/**
 * \brief Initialize the value to random number generator
 * 
 * \param seed_i16 initialize value
 */
void
UTILS_RandSeed(uint16_t seed_i16);

/**
 * \brief Scale a number from one range to another
 * 
 * \param in_value_i16  [in] Scaling value
 * \param in_min_i16    [in] From range minimum value
 * \param in_max_i16    [in] From range maximum value
 * \param out_min_i16   [in] To range minimum value
 * \param out_max_i16   [in] To range maximum value
 * \return int16_t Range scaled value
 */
int16_t
UTILS_Scale_i16(int16_t in_value_i16, 
                int16_t in_min_i16, int16_t in_max_i16, 
                int16_t out_min_i16, int16_t out_max_i16);

#ifdef __cplusplus
}
#endif

#endif /* UTILS_af45c5ee_eb0b_11e9_8850_74dfbf0d835a */
