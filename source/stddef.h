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
 * \file stddef.h
 * \author Binary Maker (https://github.com/binarymaker)
 * \brief Standard types and ctype function library
 * \date 2019-10-10
 */

#ifndef STDDEF_05076ec2_ea68_11e9_8db3_705a0f25cb51
#define STDDEF_05076ec2_ea68_11e9_8db3_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __TYPES_VERSION      (0x0001u) /*!< version: 0.1v */

#include "stdint.h"


/**
 * \brief Boolean data type
 * 
 */
typedef enum{
  FALSE = 0,
  TRUE
}bool_et;

/**
 * \brief Logical state data type 
 * 
 */
typedef enum{
  LOW = 0,
  HIGH
}state_et;

/**
 * \brief Process (or) Functional state data type
 * 
 */
typedef enum{
  FAILED = 0,
  SUCCESS,
  BUSY,
  TIMEOUT
}status_et;

#ifdef __cplusplus
}
#endif

#endif /* STDDEF_05076ec2_ea68_11e9_8db3_705a0f25cb51 */
