/*
 * interrupt.h
 *
 *  Created on: Oct 22, 2023
 *      Author: dell
 */

#ifndef GLOBAL_INTERR_H_
#define GLOBAL_INTERR_H_

#define SREG (*(volatile unsigned char*)0x5F)

void GIE_voidEnable(void);
void GIE_voidDisable(void);

#endif /* GLOBAL_INTERR_H_ */
