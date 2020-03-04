/*
 * sysctrl.h
 *
 *  Created on: Feb 24, 2020
 *      Author: Amany
 */

#ifndef SYSCTRL_H_
#define SYSCTRL_H_

#include "gpio.h"

#define GPIO_High_Performance_Bus_Control    0x400FE06C
#define SYSCTL_RCGC2_R                       0x400FE108

typedef enum {
    AHB, APB
}Sysctrl_bus_t;

typedef enum {
    portA_pin=0 ,portB_pin=1 ,portC_pin=2
    , portD_pin=3 ,portE_pin=4 , portF_pin=5
}Sysctrl_port_pin_t;
void Sysctrl_BusSet_PortLock(Sysctrl_bus_t bus, Sysctrl_port_pin_t port);

#endif /* SYSCTRL_H_ */
