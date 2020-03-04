/*
 * gpio.c
 *
 *  Created on: Feb 24, 2020
 *      Author: Amany
 */
#include "gpio.h"
#include "hw_types.h"
#include "std_types.h"

void GPIODirectionModeSet(unsigned long int port, unsigned char pins, gpio_mode_t mode)
{
    //Mode
    if (mode == MODE_AF)
        SET_PINS(port + GPIO_ALTERNATE_FUNC_SEL_OFFSET,pins);
    else if (mode == MODE_GPIO)
        CLEAR_PINS(port + GPIO_ALTERNATE_FUNC_SEL_OFFSET,pins);
    //direction
    if (mode == MODE_OUT)
        SET_PINS(port + GPIO_DIRECTION_OFFSET,pins);
    else if (mode == MODE_IN)
        CLEAR_PINS(port + GPIO_DIRECTION_OFFSET,pins);
}

unsigned char GPIODirGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_DIRECTION_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_DIRECTION_OFFSET);
    return data;
}

unsigned char GPIOModeGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_ALTERNATE_FUNC_SEL_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_ALTERNATE_FUNC_SEL_OFFSET);
    return data;
}

void GPIOPadSet(unsigned long int port, unsigned char pins,gpio_drive_t str, gpio_pad_t pad)
{
        //current
        if (str == Drive_2mA)
            SET_PINS(port + GPIO_2_MA_DRIVE_SEL_OFFSET,pins);
        else if (str == Drive_4mA)
            SET_PINS(port + GPIO_4_MA_DRIVE_SEL_OFFSET,pins);
        else if (str == Drive_8mA)
            SET_PINS(port + GPIO_8_MA_DRIVE_SEL_OFFSET,pins);
        else if (str == Drive_8mA_Selw)
            SET_PINS(port + GPIO_SLEW_RATE_CONTROL_SEL_OFFSET,pins);
        //resistance
        if (pad == Pad_PU)
            SET_PINS(port + GPIO_PULL_UP_SEL_OFFSET,pins);
        else if (pad == Pad_PD)
            SET_PINS(port + GPIO_PULL_DOWN_SEL_OFFSET,pins);
        else if (pad == Pad_OD)
            SET_PINS(port + GPIO_OPEN_DRAIN_SEL_OFFSET,pins);

}
unsigned char GPIOPadDrive_2mAStrGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_2_MA_DRIVE_SEL_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_2_MA_DRIVE_SEL_OFFSET);
    return data;
}
unsigned char GPIOPadDrive_4mAStrGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_4_MA_DRIVE_SEL_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_4_MA_DRIVE_SEL_OFFSET);
    return data;
}
unsigned char GPIOPadDrive_8mAStrGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_8_MA_DRIVE_SEL_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_8_MA_DRIVE_SEL_OFFSET);
    return data;
}
unsigned char GPIOPadDrive_8mA_SelwStrGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_SLEW_RATE_CONTROL_SEL_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_SLEW_RATE_CONTROL_SEL_OFFSET);
    return data;
}
unsigned char GPIOPadOpenDrainGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_OPEN_DRAIN_SEL_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_OPEN_DRAIN_SEL_OFFSET);
    return data;
}
unsigned char GPIOPadPullUpGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_PULL_UP_SEL_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_PULL_UP_SEL_OFFSET);
    return data;
}
unsigned char GPIOPadPullDownGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_PULL_DOWN_SEL_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_PULL_DOWN_SEL_OFFSET);
    return data;
}
uint8 GPIORead(uint32 port, uint8 pins)
{
    //CLEAR_PINS(port + GPIO_DATA_OFFSET,~(pins)); /*wrong*/
    uint8 data = (uint8)READ_REG(port + GPIO_DATA_OFFSET + ((uint16)pins << 2));
    return data;
}
void GPIOWrite(unsigned long int port, unsigned char pins, unsigned char data)
{
    volatile unsigned long *REG=(volatile unsigned long *) port+GPIO_DATA_OFFSET+((uint16)pins<<2);
    *REG=data;
}

void GPIODigitalSelect(unsigned long int port, unsigned char pins, gpio_DigitalMode_t mode)
{
    if (mode == Digital_enable)
        SET_PINS(port + GPIO_DIGITAL_EN_OFFSET,pins);
    else if (mode == Digital_disable)
        CLEAR_PINS(port + GPIO_DIGITAL_EN_OFFSET,pins);
}
void GPIOAnalogSelect(unsigned long int port, unsigned char pins, gpio_AnalogMode_t mode)
{
    if (mode == Analog_enable)
        SET_PINS(port + GPIO_ANALOG_MODE_SEL_OFFSET,pins);
    else if (mode == Analog_disable)
        CLEAR_PINS(port + GPIO_ANALOG_MODE_SEL_OFFSET,pins);
}

void GPIOInterruptMask(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_INTERRUPT_MASK_OFFSET,pins);

}

void GPIOInterruptUnMask(unsigned long int port, unsigned char pins)
{
    SET_PINS(port + GPIO_INTERRUPT_MASK_OFFSET,pins);
}

void GPIOInterruptClear(unsigned long int port, unsigned char pins)
{
    SET_PINS(port + GPIO_INTERRUPT_CLEAR_OFFSET,pins);
}

unsigned char GPIOInterruptStatusGet(unsigned long int port, unsigned char pins)
{
    CLEAR_PINS(port + GPIO_INTERRUPT_MASK_OFFSET,~(pins));
    unsigned long int data =READ_REG(port + GPIO_INTERRUPT_MASK_OFFSET);
    return data;
}

void GPIOInterruptEventSenseCfg(unsigned long int port, unsigned char pins, gpio_InterruptEvent_t event, gpio_InterruptSense_t sense )
{
    //event
    if (event == HIGH_LEVEL)
    {
        SET_PINS(port + GPIO_INTERRUPT_SENSE_OFFSET,pins);///*Enable Level sensitive interrupt.*/
        SET_PINS(port + GPIO_INTERRUPT_EVENT_OFFSET,pins);
    }
    else if (event == LOW_LEVEL)
    {
        SET_PINS(port + GPIO_INTERRUPT_SENSE_OFFSET,pins);///*Enable Level sensitive interrupt.*/
        CLEAR_PINS(port + GPIO_INTERRUPT_EVENT_OFFSET,pins);
    }
    //sense
    if (sense == RAISNG_EDGE)
    {
        CLEAR_PINS(port + GPIO_INTERRUPT_SENSE_OFFSET,pins);/*Enable edge sensitive interrupt.*/
        SET_PINS(port + GPIO_INTERRUPT_EVENT_OFFSET,pins);
    }
    else if (sense == FALING_EDGE)
    {
        CLEAR_PINS(port + GPIO_INTERRUPT_SENSE_OFFSET,pins);/*Enable edge sensitive interrupt.*/
        CLEAR_PINS(port + GPIO_INTERRUPT_EVENT_OFFSET,pins);
    }
    else if (sense == BOTH_EDGES)
    {
        CLEAR_PINS(port + GPIO_INTERRUPT_SENSE_OFFSET,pins);/*Enable edge sensitive interrupt.*/
        SET_PINS(port + GPIO_INTERRUPT_BOTH_EDGE_OFFSET,pins);
    }

}

