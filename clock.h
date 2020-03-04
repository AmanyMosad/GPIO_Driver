/*
 * clock.h
 *
 *  Created on: Feb 20, 2020
 *      Author: Amany
 */

#ifndef CLOCK_H_
#define CLOCK_H_


#define SYSCTL_RIS_R   (*((volatile unsigned long *)0x400FE050))
#define SYSCTL_RCC_R   (*((volatile unsigned long *)0x400FE060))
#define SYSCTL_RCC2_R  (*((volatile unsigned long *)0x400FE070))

#define USERCC2                   0x80000000
#define BYPASS2_PLL               0x00000800
#define CLEARING_BYPASS2_PLL      (SYSCTL_RCC2_R &~0x00000800)
#define CLEAR_XTAL                (SYSCTL_RCC_R &~0x000007C0)
#define MAIN_OSC_SOURCE           (SYSCTL_RCC2_R &~0x00000070)
#define CLEARING_PWRDN            (SYSCTL_RCC2_R &~0x00002000)
#define MHz_400_PLL               (SYSCTL_RCC2_R | 0x40000000)
#define CLEAR_SYSDIV              (SYSCTL_RCC2_R&~ 0x1FC00000) // clear system clock divider

void CLOCK_Activating_the_PLL(void);
#endif /* CLOCK_H_ */
