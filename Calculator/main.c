/*
 * main.c
 *
 *  Created on: Nov 8, 2023
 *      Author: AhmedKhaled
 */


#include"StdTypes.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"Cal_Interface.h"

#include<util/delay.h>

int main()
{
	Cal_Init();

	while(1)
	{
		Calculator();
	}
	return 0;
}
