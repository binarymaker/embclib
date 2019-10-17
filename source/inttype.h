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
 * \file inttype.h
 * \author Binary Maker (https://github.com/binarymaker)
 * \brief Standard interger data types based on integer length
 * \date 2019-10-10
 */

#ifndef INTTYPE_f6dccee6_ea67_11e9_87ae_705a0f25cb51
#define INTTYPE_f6dccee6_ea67_11e9_87ae_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __INTTYPE_VERSION      (0x0001u) /*!< version: 0.1v */

/** \defgroup IntTypeDef Standard integer type definition
  * @{
  */

/**
 * \brief 8 bit signed integer.
 *        \ref SignIntLimits
 */
typedef signed char       int8_t    ;

/**
 * \brief 16 bit signed integer.
 *        \ref SignIntLimits
 */
typedef signed int        int16_t   ;

/**
 * \brief 32 bit signed integer.
 *        \ref SignIntLimits
 */
typedef signed long int   int32_t   ;

/**
 * \brief 8 bit unsigned integer.
 *        \ref UnsignIntLimits
 */
typedef unsigned char     uint8_t   ;

/**
 * \brief 16 bit unsigned integer.
 *        \ref UnsignIntLimits
 */
typedef unsigned int      uint16_t  ;

/**
 * \brief 32 bit unsigned integer.
 *        \ref UnsignIntLimits
 */
typedef unsigned long int uint32_t  ;

/**
  * @}
  */

/** \defgroup IntLimits standard integer type maximun and minimum limits
  * @{
  */

/** \defgroup SignIntLimits Signed integer type maximun and minimum limits
  * @{
  */

/**
 * \brief 8 bit signed integer maximum limit
 */
#define INT8_MAX     127
/**
 * \brief 8 bit signed integer minimum limit
 */
#define INT8_MIN    -128

/**
 * \brief 16 bit signed integer maximum limit
 */
#define INT16_MAX    32767
/**
 * \brief 16 bit signed integer minimum limit
 */
#define INT16_MIN   -32768

/**
 * \brief 32 bit signed integer maximum limit
 */
#define INT32_MAX    2147483647
/**
 * \brief 32 bit signed integer minimum limit
 */
#define INT32_MIN   -2147483648

/**
  * @}
  */

 /** \defgroup UnsignIntLimits Unsigned integer type maximun and minimum limits
  * @{
  */

/**
 * \brief 8 bit unsigned integer maximum limit
 */
#define UINT8_MAX    255u
/**
 * \brief 8 bit unsigned integer minimum limit
 */
#define UINT8_MIN    0u

/**
 * \brief 16 bit unsigned integer maximum limit
 */
#define UINT16_MAX   65535u
/**
 * \brief 16 bit unsigned integer minimum limit
 */
#define UINT16_MIN   0u

/**
 * \brief 32 bit unsigned integer maximum limit
 */
#define UINT32_MAX   4294967295u
/**
 * \brief 32 bit unsigned integer minimum limit
 */
#define UINT32_MIN   0u

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* INTTYPE_f6dccee6_ea67_11e9_87ae_705a0f25cb51 */
