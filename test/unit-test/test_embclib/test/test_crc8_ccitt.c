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

void
setUp()
{

}

void
tearDown()
{

}

/**
 * Refer https://crccalc.com/ for crc calculation 
 */
void
test_crc_2size_array()
{
  uint8_t data_8u_array[] = {0x01, 0x02};
  uint8_t crc_res;

  crc_res = crc8_ccitt(data_8u_array, sizeof(data_8u_array));

  TEST_ASSERT_EQUAL_HEX8(0x1B, crc_res);
}

void
test_crc_string_array()
{
  uint8_t data_8u_array[] = "binarymaker";
  uint8_t crc_res;

  crc_res = crc8_ccitt(data_8u_array, 11);

  TEST_ASSERT_EQUAL_HEX8(0xC4, crc_res);
  
}