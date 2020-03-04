/*
 * gpio.h
 *
 *  Created on: Feb 20, 2020
 *      Author: Amany
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "regmap.h"

typedef enum {
    MODE_IN = 0x00, MODE_OUT = 0xff, MODE_AF = 0x3, MODE_GPIO=0x4
}gpio_mode_t;


typedef enum {
    PORTA, PORTB, PORTC
}gpio_port_t;


typedef enum {
    Drive_2mA, Drive_4mA, Drive_8mA, Drive_8mA_Selw
}gpio_drive_t;


typedef enum {
    Pad_PU,Pad_PD,Pad_NPU_NPD,Pad_OD
}gpio_pad_t;

typedef enum {
    Digital_enable, Digital_disable
}gpio_DigitalMode_t;

typedef enum {
    Analog_enable, Analog_disable
}gpio_AnalogMode_t;


typedef enum {
    LOW_LEVEL, HIGH_LEVEL
}gpio_InterruptEvent_t;
typedef enum {
    FALING_EDGE, RAISNG_EDGE, BOTH_EDGES
}gpio_InterruptSense_t;
//Functions prototype


void GPIODirectionModeSet(unsigned long int port, unsigned char pins, gpio_mode_t mode);
unsigned char GPIODirGet(unsigned long int port, unsigned char pins);
unsigned char GPIOModeGet(unsigned long int port, unsigned char pins);

void GPIOPadSet(unsigned long int port, unsigned char pins,gpio_drive_t str, gpio_pad_t pad);
unsigned char GPIOPadDriveStrGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadOpenDrainGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadPullUpGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadPullDownGet(unsigned long int port, unsigned char pins);


unsigned char GPIORead(unsigned long int port, unsigned char pins);
void GPIOWrite(unsigned long int port, unsigned char pins, unsigned char data);

void GPIODigitalSelect(unsigned long int port, unsigned char pins, gpio_DigitalMode_t mode);
void GPIOAnalogSelect(unsigned long int port, unsigned char pins, gpio_AnalogMode_t mode);

void GPIOInterruptMask(unsigned long int port, unsigned char pins);
void GPIOInterruptUnMask(unsigned long int port, unsigned char pins);
void GPIOInterruptClear(unsigned long int port, unsigned char pins);
unsigned char GPIOInterruptStatusGet(unsigned long int port, unsigned char pins);
void GPIOInterruptEventSenseCfg(unsigned long int port, unsigned char pins, gpio_InterruptEvent_t event, gpio_InterruptSense_t sense );


#endif /* GPIO_H_ */
