/*
 * sysctrl.c
 *
 *  Created on: Feb 24, 2020
 *      Author: Amany
 */

#include "sysctrl.h"
#include "hw_types.h"
#include "std_types.h"

void Sysctrl_BusSet_PortLock(Sysctrl_bus_t bus,  Sysctrl_port_pin_t port)
{
    if(bus==AHB)
    {
        SetBit(GPIO_High_Performance_Bus_Control,port);
        SetBit(SYSCTL_RCGC2_R,port);
    }
    else if (bus==APB)
    {
        ClearBit(GPIO_High_Performance_Bus_Control,port);
        SetBit(SYSCTL_RCGC2_R,port);
    }

}
