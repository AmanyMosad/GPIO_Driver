/*
 * clock_cfg.h
 *
 *  Created on: Feb 20, 2020
 *      Author: Amany
 */

#ifndef CLOCK_CFG_H_
#define CLOCK_CFG_H_

/*16 MHz main oscillator to run at 80 MHz
 *8 MHz crystal to run at 50 MHz
 *Change the specification from 16 MHz to 8 MHz
 *Change the specification from divide by 5 to divide by 8. */

#define CRYSTAL_VALUE  0x00000540    // 10101, configure for 16 MHz crystal, 24 MHz crystal has an XTAL field of 11001,
#define SYSDIV           (4<<22)     // configure for 80 MHz clock, (7<<22)configure for 50 MHz clock




#endif /* CLOCK_CFG_H_ */
