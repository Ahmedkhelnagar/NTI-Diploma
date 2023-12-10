/*
 * SPI_Interface.h
 *
 *  Created on: Oct 30, 2023
 *      Author: dell
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#include"SPI_config.h"
#include"SPI_Private.h"

void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

u8 SPI_u8Transfer(u8 Copy_Data);

u8 SPI_u8Recieve(u8 Copy_Data);

void SPI_SendString(const u8 *Str);

void SPI_ReceiveString(u8 *Str);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) );

u8 SPI_u8ReadDataISR(void);

void SPI_voidSendDataISR(u8 Copy_Data);

#endif /* SPI_INTERFACE_H_ */
