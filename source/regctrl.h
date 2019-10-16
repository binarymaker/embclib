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

#define BIT_Mask(bitpos)             (1 << (bitpos))
#define BIT_MaskFill(bitpos)         (BIT_Mask((bitpos)) - 1)

#define BIT_Set(reg, bitpos)      \
    ((reg) |=  BIT_Mask((bitpos)))

#define BIT_Clear(reg, bitpos)    \
    ((reg) &= ~BIT_Mask((bitpos)))

#define BIT_Read(reg, bitpos)     \
    (((reg) >> (bitpos)) & 0x1U)

#define BIT_Toggle(reg, bitpos)   \
    ((reg) ^=  BIT_Mask((bitpos)))

#define REG_Clear(reg)         \
    ((reg)  =  (0x0))

#define REG_Write(reg, val)    \
    ((reg)  =  (val))

#define REG_Read(reg)     ((reg))

#define REG_Modify(reg, setmask, clearmask)  \
REG_Write((reg), (((REG_Read(reg)) & (~(clearmask))) | (setmask)))

#define REG_Cut(reg, bitpos, len)   \
    (((reg) >> (bitpos)) & BIT_MaskFill((len)))

#define REG_Shift(val, bitpos)      \
    ( (val) << (bitpos)) 

#define REG_RightShift(val, bitpos)  \
    ((val) >> (bitpos)) 

#define BIT_IsSet(reg, bitpos)       \
    (BIT_Read((reg), (bitpos)))

#define BIT_IsClear(reg, bitpos)     \
    (BIT_Read((reg), (bitpos)) == 0x0U)

#define BIT_IsAllSet(reg, mask)         \
    (((reg) & (mask)) == (mask))

#define BIT_IsAnySet(reg, mask)         \
    (((reg) & (mask)) != 0x0U)

#ifdef __cplusplus
}
#endif

#endif /* REGCTRL_4f297a88_eb33_11e9_bd8a_705a0f25cb51 */
