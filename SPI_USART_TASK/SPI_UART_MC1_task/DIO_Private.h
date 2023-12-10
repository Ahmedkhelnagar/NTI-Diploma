/*
 * DIO_Private.h
 *
 *  Created on: Oct 21, 2023
 *      Author: dell
 */

#ifndef LCD_DIO_PRIVATE_H_
#define LCD_DIO_PRIVATE_H_

extern const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS];
static void DIO_InitPin(DIO_Pin_type pin, DIO_PinStatus_type status);

#endif /* LCD_DIO_PRIVATE_H_ */
