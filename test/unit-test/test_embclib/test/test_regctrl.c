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
#include "regctrl.h"
#include "stdint.h"
#include "common-def.h"

void
setUp()
{

}

void
tearDown()
{

}

void
test_bitMask()
{
  uint16_t res; 
  
  res = BIT_Mask(5);
  TEST_ASSERT_EQUAL(32, res);
  
  res = BIT_Mask(15);
  TEST_ASSERT_EQUAL(32768, res);
}

void
test_bitMaskFill()
{
  uint16_t res; 
  
  res = BIT_MaskFill(5);
  TEST_ASSERT_EQUAL(31, res);
  
  res = BIT_MaskFill(15);
  TEST_ASSERT_EQUAL(32767, res);
}

void
test_IsAnyBitSet()
{
  uint16_t res; 
  
  res = BIT_IsAnySet(5, 0x01);
  TEST_ASSERT_EQUAL(TRUE, res);
  
  res = BIT_IsAnySet(15, 0x08);
  TEST_ASSERT_EQUAL(TRUE, res);
}

void
test_IsAllBitSet()
{
  uint16_t res; 

  res = BIT_IsAllSet(15, 0x0f);
  TEST_ASSERT_EQUAL(TRUE, res);
  
  res = BIT_IsAllSet(25, 0x19);
  TEST_ASSERT_EQUAL(TRUE, res);
}

void
test_RegCut()
{
  uint16_t res; 

  res = REG_GroupRead(100, 2, 5);
  TEST_ASSERT_EQUAL(25, res);
}