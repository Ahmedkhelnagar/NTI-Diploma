/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: dell
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include"StdTypes.h"
#include"Utils.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"SPI_Interface.h"
#include"GLOBAL_Interr.h"
#include"UART_INTERFACE.h"
#include"keypad.h"



//void Interr_Action()
//{
//
//}

	u8 receieve_data;
	u8 readSPi;

int main()
{
	DIO_Init();
	LCD_Init();
	_delay_ms(500);
	SPI_voidMasterInit();
	UART_init(9600);
	UART_RX_ENABLE();
//	GIE_voidEnable();
//	Uart_Enable_Interr();
//	Interr_SetCallback(Interr_Action);

	while(1)
	{
		receieve_data=USART_Receive();
		LCD_WriteChar(receieve_data);
//		_delay_ms(500);
		DIO_WritePin(PINB4,0);
		readSPi=SPI_u8Transfer(receieve_data);
	}
	return 0;
}


