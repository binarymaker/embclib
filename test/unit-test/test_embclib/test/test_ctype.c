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
#include "ctype.h"
#include "stddef.h"

void
setUp()
{

}

void
tearDown()
{

}

void
test_IsAlpha()
{

  TEST_ASSERT_EQUAL( TRUE, IsAlpha('A') );
  TEST_ASSERT_EQUAL( TRUE, IsAlpha('Z') );
  TEST_ASSERT_EQUAL( TRUE, IsAlpha('a') );
  TEST_ASSERT_EQUAL( TRUE, IsAlpha('z') );

  TEST_ASSERT_EQUAL( FALSE, IsAlpha('0') );
  TEST_ASSERT_EQUAL( FALSE, IsAlpha('9') );
  
  TEST_ASSERT_EQUAL( FALSE, IsAlpha('@') );
  TEST_ASSERT_EQUAL( FALSE, IsAlpha(')') );

}

void
test_IsDigit()
{

  TEST_ASSERT_EQUAL( FALSE, IsDigit('A') );
  TEST_ASSERT_EQUAL( FALSE, IsDigit('Z') );
  TEST_ASSERT_EQUAL( FALSE, IsDigit('a') );
  TEST_ASSERT_EQUAL( FALSE, IsDigit('z') );

  TEST_ASSERT_EQUAL( TRUE, IsDigit('0') );
  TEST_ASSERT_EQUAL( TRUE, IsDigit('9') );
  
  TEST_ASSERT_EQUAL( FALSE, IsDigit('@') );
  TEST_ASSERT_EQUAL( FALSE, IsDigit(')') );

}

void
test_IsAlphaNumeric()
{

  TEST_ASSERT_EQUAL( TRUE, IsAlphaNumeric('A') );
  TEST_ASSERT_EQUAL( TRUE, IsAlphaNumeric('Z') );
  TEST_ASSERT_EQUAL( TRUE, IsAlphaNumeric('a') );
  TEST_ASSERT_EQUAL( TRUE, IsAlphaNumeric('z') );

  TEST_ASSERT_EQUAL( TRUE, IsAlphaNumeric('0') );
  TEST_ASSERT_EQUAL( TRUE, IsAlphaNumeric('9') );
  
  TEST_ASSERT_EQUAL( FALSE, IsAlphaNumeric('@') );
  TEST_ASSERT_EQUAL( FALSE, IsAlphaNumeric(')') );

}

void
test_IsAscii()
{

  TEST_ASSERT_EQUAL( TRUE, IsAscii('A') );
  TEST_ASSERT_EQUAL( TRUE, IsAscii('Z') );
  TEST_ASSERT_EQUAL( TRUE, IsAscii('a') );
  TEST_ASSERT_EQUAL( TRUE, IsAscii('z') );

  TEST_ASSERT_EQUAL( TRUE, IsAscii('0') );
  TEST_ASSERT_EQUAL( TRUE, IsAscii('9') );
  
  TEST_ASSERT_EQUAL( TRUE, IsAscii('@') );
  TEST_ASSERT_EQUAL( TRUE, IsAscii(')') );

  TEST_ASSERT_EQUAL( FALSE, IsAscii(158) );
  TEST_ASSERT_EQUAL( FALSE, IsAscii(255) );

}

void
test_IsControl()
{

  TEST_ASSERT_EQUAL( FALSE, IsControl('A') );
  TEST_ASSERT_EQUAL( FALSE, IsControl('Z') );
  TEST_ASSERT_EQUAL( FALSE, IsControl('a') );
  TEST_ASSERT_EQUAL( FALSE, IsControl('z') );

  TEST_ASSERT_EQUAL( FALSE, IsControl('0') );
  TEST_ASSERT_EQUAL( FALSE, IsControl('9') );
  
  TEST_ASSERT_EQUAL( FALSE, IsControl('@') );
  TEST_ASSERT_EQUAL( FALSE, IsControl(')') );

  TEST_ASSERT_EQUAL( TRUE, IsControl('\n') );
  TEST_ASSERT_EQUAL( TRUE, IsControl('\a') );
  TEST_ASSERT_EQUAL( TRUE, IsControl('\r') );
  
}

void
test_IsGraph()
{

  TEST_ASSERT_EQUAL( TRUE, IsGraph('A') );
  TEST_ASSERT_EQUAL( TRUE, IsGraph('Z') );
  TEST_ASSERT_EQUAL( TRUE, IsGraph('a') );
  TEST_ASSERT_EQUAL( TRUE, IsGraph('z') );

  TEST_ASSERT_EQUAL( TRUE, IsGraph('0') );
  TEST_ASSERT_EQUAL( TRUE, IsGraph('9') );
  
  TEST_ASSERT_EQUAL( TRUE, IsGraph('@') );
  TEST_ASSERT_EQUAL( TRUE, IsGraph(')') );

  TEST_ASSERT_EQUAL( FALSE, IsGraph('\n') );
  TEST_ASSERT_EQUAL( FALSE, IsGraph('\a') );
  TEST_ASSERT_EQUAL( FALSE, IsGraph('\r') );
/*  
  for (int i = 0; i < 255; i++)
  {
    if (IsGraph(i))
    {
      printf("%c ",(char)i);
    }
  }
*/
}

void
test_IsPunct()
{

  TEST_ASSERT_EQUAL( FALSE, IsPunct('A') );
  TEST_ASSERT_EQUAL( FALSE, IsPunct('Z') );
  TEST_ASSERT_EQUAL( FALSE, IsPunct('a') );
  TEST_ASSERT_EQUAL( FALSE, IsPunct('z') );

  TEST_ASSERT_EQUAL( FALSE, IsPunct('0') );
  TEST_ASSERT_EQUAL( FALSE, IsPunct('9') );
  
  TEST_ASSERT_EQUAL( TRUE, IsPunct('@') );
  TEST_ASSERT_EQUAL( TRUE, IsPunct(')') );
  TEST_ASSERT_EQUAL( TRUE, IsPunct('!') );
  TEST_ASSERT_EQUAL( TRUE, IsPunct('\"') );

  TEST_ASSERT_EQUAL( FALSE, IsPunct('\n') );
  TEST_ASSERT_EQUAL( FALSE, IsPunct('\a') );
  TEST_ASSERT_EQUAL( FALSE, IsPunct('\r') );

}

void
test_ToLower()
{

  TEST_ASSERT_EQUAL( 'a', ToLower('A') );
  TEST_ASSERT_EQUAL( 'z', ToLower('Z') );
  TEST_ASSERT_EQUAL( 'a', ToLower('a') );
  TEST_ASSERT_EQUAL( 'z', ToLower('z') );

  TEST_ASSERT_EQUAL( '0', ToLower('0') );

  TEST_ASSERT_EQUAL( '#', ToLower('#') );
  
}

void
test_ToUpper()
{

  TEST_ASSERT_EQUAL( 'A', ToUpper('A') );
  TEST_ASSERT_EQUAL( 'Z', ToUpper('Z') );
  TEST_ASSERT_EQUAL( 'A', ToUpper('a') );
  TEST_ASSERT_EQUAL( 'Z', ToUpper('z') );

  TEST_ASSERT_EQUAL( '0', ToUpper('0') );

  TEST_ASSERT_EQUAL( '#', ToUpper('#') );

}
