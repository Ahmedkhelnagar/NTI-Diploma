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
#define D4  PINB0
#define D5  PINB1
#define D6  PINB2
#define D7  PINB3


#define RS  PINA0

#define E   PINA1

/************************** 8 BIT only ***************************/
#define LCD_PORT  PC


#endif /* LCD_LCD_CFG_H_ */
