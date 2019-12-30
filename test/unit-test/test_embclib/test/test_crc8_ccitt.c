/**
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
  */

#include "unity.h"
#include "crc8-ccitt.h"
#include <stdint.h>

void
setUp()
{

}

void
tearDown()
{

}

/**
 * Refer online calculator for cross check
 * https://crccalc.com/?crc=0x01 0x02&method=crc8&datatype=hex&outtype=hex
 */
void
test_crc_2size_array()
{
  uint8_t data_u8arr[] = {0x01, 0x02};
  uint8_t crc_res;

  crc_res = crc8_ccitt(data_u8arr, sizeof(data_u8arr));

  TEST_ASSERT_EQUAL_HEX8(0x1B, crc_res);
}

void
test_crc_string_array()
{
  /**
    * https://crccalc.com/?crc=binarymaker&method=crc8&datatype=ascii&outtype=hex
    */
  uint8_t data_u8arr[] = "binarymaker";
  uint8_t crc_res;

  crc_res = crc8_ccitt(data_u8arr, 11);

  TEST_ASSERT_EQUAL_HEX8(0xC4, crc_res);
  
}

void
test_crc_exit_size_is_zero()
{
  uint8_t data_u8arr[] = {0,2,4};
  uint8_t crc_res;

  crc_res = crc8_ccitt(data_u8arr, 0);

  TEST_ASSERT_EQUAL_HEX8(0x00, crc_res);
  
}

void
test_crc_16bit_data_to_crc8()
{
  /**
    * https://crccalc.com/?crc= 0x56 0x32  0x81 0x69&method=crc8&datatype=hex&outtype=hex
    */
  uint16_t data_16u_array[] = {0x3256,0x6981}; /* is equ to {0x56, 0x32}, {0x81, 0x69}*/
  uint8_t crc_res;

  crc_res = crc8_ccitt(data_16u_array, sizeof(data_16u_array));

  TEST_ASSERT_EQUAL_HEX8(0x04, crc_res);
  
}
