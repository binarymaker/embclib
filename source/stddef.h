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

#define _ASM_            __asm                 /*!< asm keyword for target Compiler   */
#define _INLINE_         inline                /*!< inline keyword for target Compiler*/
#define _STATIC_INLINE_  static inline         /*!< static inline combination for \
                                                                inline function */

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

/**
 * \brief Check a character is an alphabet or not.
 *        Ex. (a-z) and (A-Z)
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsAlpha(uint8_t ch)
{
  if ( ( ( (unsigned)ch | 32U) - 'a' ) < 26 )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is an number character or not.
 *        Ex. (0-9)
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsDigit(uint8_t ch)
{
  if ( ( (unsigned)ch - '0') < 10 )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is an alphabetic and number character or not.
 *        Ex. (a-z) (A-Z) (0-9)
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsAlphaNumeric(uint8_t ch)
{
  if ( IsAlpha(ch) || IsDigit(ch) )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is an ASCII character or not.
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsAscii(uint8_t ch)
{
  if ( !( (unsigned)ch & ~0x7f) )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is a control character or not.
 *        Ex. (\n - newline, \t - tab, \r - enter, \b - backspace)
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsControl(uint8_t ch)
{
  if ( (ch < 0x20) || (ch == 0x7f) )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is a graphical character or not.
 *        Ex. ! " # $ % & ' ( ) * + , - . / (0-9) : ; < = > 
 *            ? @ (A-Z) [ \ ] ^ _ ` (a-z) { | } ~ 
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsGraph(uint8_t ch)
{
  if ( ( (unsigned)ch - 0x21) < 0x5e )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is a punctuation character or not.
 *        Ex. ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] 
 *            ^ _ ` { | } ~ 
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsPunct(uint8_t ch)
{
  if ( IsGraph(ch) && !IsAlphaNumeric(ch) )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is a printable character or not.
 *        Ex. All graphical character \ref IsGraph include space
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsPrintable(uint8_t ch)
{
  if ( ( (unsigned)ch - 0x20) < 0x5f ) 
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is a space character or not.
 *        Ex. space
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsSpace(uint8_t ch)
{
  if ( ( ( (unsigned)ch - '\t') < 5 ) || ch == ' ' )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is a hexadecimal character or not.
 *        Ex. (0-9) (a-f) (A-F)
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsHexDigit(uint8_t ch)
{
  if ( ( (unsigned)(ch - '0') < 10 ) || ( (unsigned)(ch | 32) - 'a') < 6 )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is a lower case character or not.
 *        Ex. (a-z)
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsLower(uint8_t ch)
{
  if ( (unsigned)(ch - 'a') < 26 )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Check a character is a upper case character or not.
 *        Ex. (A-Z)
 * 
 * \param ch [in] Character
 * \return \arg \ref bool_et TRUE 
 *         \arg \ref bool_et FALSE
 */
_STATIC_INLINE_ bool_et
IsUpper(uint8_t ch)
{
  if ( (unsigned)(ch - 'A') < 26 )
  {
    return TRUE;
  }
  return FALSE;
}

/**
 * \brief Convert a character to lower case character.
 *        Ex. (a-z) (A-Z) to (a-z)
 * 
 * \param ch [in] Character
 * \return Lower case character
 */
_STATIC_INLINE_ uint8_t
ToLower(uint8_t ch)
{
  if ( IsUpper(ch) )
  {
    return ( ch | 32 );
  }
  return (ch);
}

/**
 * \brief Convert a character to upper case character.
 *        Ex. (a-z) (A-Z) to (A-Z)
 * 
 * \param ch [in] Character
 * \return Upper case character
 */
_STATIC_INLINE_ uint8_t
ToUpper(uint8_t ch)
{
  if ( IsLower(ch) )
  {
    return ( ch & 0x5f );
  }
  return (ch);
}

#ifdef __cplusplus
}
#endif

#endif /* STDDEF_05076ec2_ea68_11e9_8db3_705a0f25cb51 */
