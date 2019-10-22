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

#ifndef REGCTRL_4f297a88_eb33_11e9_bd8a_705a0f25cb51
#define REGCTRL_4f297a88_eb33_11e9_bd8a_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

#define __REGCTRL_VERSION      (0x0001u)

/* Exported macro ------------------------------------------------------------*/
#define BIT_MASK(bitpos)                                        (1 << (bitpos))
#define BIT_MASKFILL(bitpos)                           (BIT_MASK((bitpos)) - 1)
#define BIT_SET(reg, bitpos)                     ((reg) |=  BIT_MASK((bitpos)))
#define BIT_CLEAR(reg, bitpos)                   ((reg) &= ~BIT_MASK((bitpos)))
#define BIT_READ(reg, bitpos)                      (((reg) >> (bitpos)) & 0x1U)
#define BIT_TOGGLE(reg, bitpos)                  ((reg) ^=  BIT_MASK((bitpos)))

#define BIT_IS_SET(reg, bitpos)                      (BIT_READ((reg), (bitpos)))
#define BIT_IS_CLEAR(reg, bitpos)            (BIT_READ((reg), (bitpos)) == 0x0U)
#define BIT_IS_ALLSET(reg, mask)                    (((reg) & (mask)) == (mask))
#define BIT_IS_ANYSET(reg, mask)                      (((reg) & (mask)) != 0x0U)

#define REG_CLEAR(reg)                                        ((reg)  =  (0x0))
#define REG_WRITE(reg, val)                                   ((reg)  =  (val))
#define REG_READ(reg)                                                   ((reg))
#define REG_GROUP(reg, bitpos, len)  (((reg) >> (bitpos)) & BIT_MASKFILL((len)))
#define REG_GROUP_MASK(reg, bitpos, mask)         (((reg) >> (bitpos)) & (mask))
#define REG_SHIFT(val, bitpos)                               ((val) << (bitpos))
#define REG_RIGHTSHIFT(val, bitpos)                          ((val) >> (bitpos))
#define REG_MODIFY(reg, setmask, clearmask)                                   \
              REG_WRITE((reg), (((REG_READ(reg)) & (~(clearmask))) | (setmask)))

#ifdef __cplusplus
}
#endif

#endif /* REGCTRL_4f297a88_eb33_11e9_bd8a_705a0f25cb51 */
