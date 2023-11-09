/*
 * main.c
 *
 *  Created on: Nov 9, 2023
 *      Author: dell
 */


#include"StdTypes.h"
#include"MemMap.h"
#include"Utils.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"story_interface.h"


int main(void)
{
	Story_Init();

	while(1)
	{
		Story_Run();
	}
	return 0;
}
