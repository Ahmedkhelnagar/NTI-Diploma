/*
 * ping_pong_interface.h
 *
 *  Created on: Nov 2, 2023
 *      Author: dell
 */

#ifndef PING_PONG_INTERFACE_H_
#define PING_PONG_INTERFACE_H_

#include"StdTypes.h"
#include"MemMap.h"
#include"Utils.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"

#include <util/delay.h>


void pingpong_Init();
void pingpong_end(void);
void left_To_Right(void);
void Right_To_Left(void);


#endif /* PING_PONG_INTERFACE_H_ */
