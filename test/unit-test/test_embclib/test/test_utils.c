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
#include "utils.h"

void
setUp()
{

}

void
tearDown()
{

}

void
test_swap_unsigned()
{
  uint8_t a = 255;
  uint8_t b = 128;

  Swap(a, b);
  TEST_ASSERT_EQUAL(128, a);
  TEST_ASSERT_EQUAL(255, b);

  uint16_t c = 65535;
  uint16_t d = 1682;

  Swap(c, d);
  TEST_ASSERT_EQUAL(1682, c);
  TEST_ASSERT_EQUAL(65535, d);
}

void
test_swap_signed()
{
  int8_t a = -120;
  int8_t b = 89;

  Swap(a, b);
  TEST_ASSERT_EQUAL(89, a);
  TEST_ASSERT_EQUAL(-120, b);

  int16_t c = -5000;
  int16_t d = 6000;

  Swap(c, d);
  TEST_ASSERT_EQUAL(6000, c);
  TEST_ASSERT_EQUAL(-5000, d);
}

void
test_scaling()
{
  int16_t res;

  res = UTILS_Scale_i16(5, 0, 10, 0, 100);
  TEST_ASSERT_EQUAL(50, res);

  res = UTILS_Scale_i16(14, 10, 20, 200, 300);
  TEST_ASSERT_EQUAL(240, res);

}

void
test_limit()
{
  int16_t res;

  res = Limit(8, 0, 5);
  TEST_ASSERT_EQUAL(5, res);
  
  res = Limit(-8, 0, 5);
  TEST_ASSERT_EQUAL(0, res);

  res = Limit(3000, 256, 5000);
  TEST_ASSERT_EQUAL(3000, res);

}


void
test_rand()
{
  UTILS_RandSeed(0x2566);

  printf("Random number generator (-255, 255) \n");
  for (int j = 0; j < 5; j++)
  {
    for (int i = 0; i < 10; i++)
    {
      printf("%d \t", UTILS_Rand_i16(-255, 255));
    }
    printf("\n");
  }
}
