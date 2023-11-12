/*
 * LCD_Cfg.h
 *
 *  Created on: Oct 21, 2023
 *      Author: dell
 */

#ifndef LCD_LCD_CFG_H_
#define LCD_LCD_CFG_H_

#define _4_BIT  0
#define _8_BIT  1


/************************** _8_BIT or _4_BIT **********************/
#define LCD_MODE  _4_BIT

/************************** 4 BIT only ***************************/
#define D4  PINC0
#define D5  PINC1
#define D6  PINC2
#define D7  PINC3


#define RS  PIND4

#define E   PIND6

/************************** 8 BIT only ***************************/
#define LCD_PORT  PC


#endif /* LCD_LCD_CFG_H_ */
