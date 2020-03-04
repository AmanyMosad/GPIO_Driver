/*
 * clock.c
 *
 *  Created on: Feb 20, 2020
 *      Author: Amany
 */


/*
 *0) Use RCC2 because it provides more options.
 *1) set the BYPASS2 (bit 11) bit. At this point the PLL is bypassed and there is no system clock divider.
 *2) specify the crystal frequency in the four XTAL bits using the code in Table 10.1.
 *   OSCSRC2 bits cleared to select the main oscillator as the clock source.
 *3) clear PWRDN2 (bit 13) to activate the PLL.
 *4) configure and enable the clock divider using the 7-bit SYSDIV2 field.
 *   If the 7-bit SYSDIV2 is n, then the clock will be divided by n+1.
 *   To get the desired 80 MHz from the 400 MHz PLL, we need to divide by 5. So, we place a 4 into the SYSDIV2 field.
 *5) wait for the PLL to stabilize by waiting for PLLRIS (bit 6) in the SYSCTL_RIS_R to become high.
 *6) The last step is to connect/enable the PLL by clearing the BYPASS2 bit.
 *   To modify this program to operate on other microcontrollers, you will need to change the crystal frequency and the system clock divider.
 */
#include "clock.h"
#include "clock_cfg.h"
void CLOCK_Activating_the_PLL(void)
{
      // 0) Use RCC2
      SYSCTL_RCC2_R |=  USERCC2;  // USERCC2
      // 1) bypass PLL while initializing
      SYSCTL_RCC2_R |=  BYPASS2_PLL;  // BYPASS2, PLL bypass
      // 2) select the crystal value and oscillator source
      SYSCTL_RCC_R = CLEAR_XTAL + CRYSTAL_VALUE;
      SYSCTL_RCC2_R = MAIN_OSC_SOURCE;  // configure for main oscillator source
      // 3) activate PLL by clearing PWRDN
      SYSCTL_RCC2_R =CLEARING_PWRDN;
      // 4) set the desired system divider
      SYSCTL_RCC2_R = MHz_400_PLL;   // use 400 MHz PLL
      SYSCTL_RCC2_R =CLEAR_SYSDIV +SYSDIV;
      // 5) wait for the PLL to lock by polling PLLLRIS
      while((SYSCTL_RIS_R&0x00000040)==0){};  // wait for PLLRIS bit
      // 6) enable use of PLL by clearing BYPASS
      SYSCTL_RCC2_R =CLEARING_BYPASS2_PLL;

}

