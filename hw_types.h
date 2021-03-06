/*
 * hw_types.h
 *
 *  Created on: Feb 20, 2020
 *      Author: Amany
 */

#ifndef HW_TYPES_H_
#define HW_TYPES_H_

#define SET_PINS(address,pins)      WRITE_REG(address,READ_REG(address)|=(0xff&pins))
#define CLEAR_PINS(address,pins)    WRITE_REG(address,READ_REG(address) &=~(pins))
#define TOGGLE_PINS(address,pins)   READ_REG(address) ^=(pins)

#define GET_PIN(address,pin)      ((READ_REG(address) &=(1<<pin))>>pin)

#define READ_REG(address)        (*(volatile uint32*)(address))
#define WRITE_REG(address,value) ((*(volatile uint32*)(address)) = value )

#define SetBit(address,BIT)    WRITE_REG(address,READ_REG(address)|=(1<<BIT))
#define ClearBit(address,BIT)  WRITE_REG(address,READ_REG(address) &= ~(1<<BIT))
#define ToggleBit(address,BIT) WRITE_REG(address,READ_REG(address) ^= (1<<BIT))
#define GetBit(address,BIT)    WRITE_REG(address,READ_REG(address) & (1<<BIT)) >> BIT)
#endif /* HW_TYPES_H_ */
