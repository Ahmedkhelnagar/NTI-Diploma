/*
 * Utils.h
 *
 *  Created on: Oct 21, 2023
 *      Author: dell
 */

#ifndef LCD_UTILS_H_
#define LCD_UTILS_H_

#define READ_BIT(reg, bit) ((reg>>bit)&1)
#define SET_BIT(reg, bit) (reg=reg|(1<<bit))
#define CLR_BIT(reg, bit) (reg=reg&~(1<<bit))
#define TOG_BIT(reg, bit) (reg=reg^(1<<bit))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#endif /* LCD_UTILS_H_ */
