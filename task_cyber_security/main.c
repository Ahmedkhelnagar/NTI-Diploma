/*
 * main.c
 *
 *  Created on: Nov 11, 2023
 *      Author: dell
 */

#include"StdTypes.h"
#include"MemMap.h"
#include"Utils.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"UART_INTERFACE.h"
#include<stdlib.h>	//rand() function
#include<util/delay.h>




//#define ROUTINE_LED  			3101AA00
//#define NRC_NO_ACCESS 			7F3135
//#define HAVE_ACCESS 			7101AA00
//#define USER_TO_UART_SEED_NUM	2701
//#define USER_TO_UART_ENCR_BYTES 2702
//#define POS_RESPONSE 			6702
//#define NEG_RESPONSE			7F2735


//u16 encry_ran_arr[100]={6,7,0,1};
u8 ran_arr[9];
u8 in_arr[9];
u8 req_arr[5];
//u16 readval;
u8  key=35;
u16 ran=0;
//u8  encrypted_msg=0;
u8 sec_flag=0;

void Have_Security();

int main()
{
	DIO_Init();
	LCD_Init();
	_delay_ms(500);
	UART_init(9600);
	UART_RX_ENABLE();
	UART_TX_ENABLE();


	while(1)
	{
		UART_receiveString(in_arr);

		if(!strcmp(in_arr,"3101AA00"))
		{
			if(sec_flag==0)
			{
				LCD_Clear();
				LCD_GoTo(1,1);
				LCD_WriteString("NRC 7F 31 35");
				Have_Security();
			}
			else if(sec_flag==1)
			{
				LCD_Clear();
				LCD_GoTo(1,1);
				LCD_WriteString("7101AA00");
				DIO_WritePin(PINC4, HIGH);
			}

		}
	}
	return 0;
}

void Have_Security()
{

	UART_receiveString(in_arr);

	if(!strcmp(in_arr,"2701"))
	{
		LCD_Clear();
		LCD_GoTo(1, 1);
		LCD_WriteString("6701 ");

		for(u8 i=0;i<8;i++)
		{
			ran_arr[i]=(rand()%10);
			ran_arr[i]+=48;
		}

		for(u8 i=0;i<8;i++)
		{
			LCD_WriteChar(ran_arr[i]);
		}
		for(u8 i=0;i<8;i++)
		{
			if(ran_arr[i]=='9')
			{
				ran_arr[i]='0';
				continue;
			}
			ran_arr[i]++;
		}
		ran_arr[8]='\0';

		for(u8 i=0;i<8;i++)
		{
			in_arr[i]=0;
		}
		UART_receiveString(req_arr);
		UART_receiveString(in_arr);

		if(!strcmp(in_arr,ran_arr))
		{
			sec_flag=1;
			LCD_Clear();
			LCD_GoTo(1,1);
			LCD_WriteString("6701 ");
		}
		else
		{
			sec_flag=0;
			LCD_Clear();
			LCD_GoTo(1,1);
			LCD_WriteString("7F 27 35");
		}

	}
}
