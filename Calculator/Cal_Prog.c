/*
 * Cal_Prog.c
 *
 *  Created on: Nov 8, 2023
 *      Author: AhmedKhaled
 */

#include"StdTypes.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"Cal_Interface.h"
#include"KeyPad_Interface.h"


#include<util/delay.h>

/************************Preprocessor********************/
#define arr_size 100

/************************Global Variables****************/
u16 arr_cal[arr_size]={0};
u8 arr_index=0;
u8 key=0;
u8 flagResult=0;
u8 rowNum=0;
u8 colNum=0;

/********************************************************
 *
 * 				Function Definitions
 *
 ********************************************************/
/********************************************************
 *
 * 				Cal_Init Function
 *
 ********************************************************/
void Cal_Init(void)
{
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
}

/********************************************************
 *
 * 				ShiftArray Function
 *
 ********************************************************/
void ShiftArray(u8 index)
{
	for(u8 i=index;i<=arr_index;i++)
	{
		arr_cal[i]=arr_cal[i+2];
	}
	arr_index-=2;
}
/********************************************************
 *
 * 				Cal_Result Function
 *
 ********************************************************/
void Cal_Result(void)
{
	/*******Multiplication and Division operators********/
	for(u8 i=0;i<=arr_index;i++)
	{
		if(arr_cal[i]=='*')
		{
			arr_cal[i-1] *= arr_cal[i+1];
			ShiftArray(i);
			i=0;
		}
		else if(arr_cal[i]=='/')
		{
			arr_cal[i-1] /= arr_cal[i+1];
			ShiftArray(i);
			i=0;
		}
	}
	/***********Addition and subtraction*****************/
	for(u8 i=0;i<=arr_index;i++)
	{
		if(arr_cal[i]=='+')
		{
			arr_cal[i-1]+=arr_cal[i+1];
			ShiftArray(i);
			i=0;
		}
		else if(arr_cal[i]=='-')
		{
			/*******To handle the sign negative********/
			if(arr_cal[i-1]>=arr_cal[i+1])
			{
				arr_cal[i-1]-=arr_cal[i+1];
			}
			else
			{
				arr_cal[i-1]=arr_cal[i+1]-arr_cal[i-1];
			}
			ShiftArray(i);
			i=0;
		}
	}
}

/********************************************************
 *
 * 				DisplayResult Function
 *
 ********************************************************/
void DisplayResult(void)
{
	rowNum=0;
	colNum=0;

	LCD_Clear();
	LCD_GoTo(rowNum, colNum);

	LCD_WriteString("Result = ");
	LCD_GoTo(0, 9);

	  	  	  /******Result will display in 7 digits******/
	//7
	LCD_WriteChar((arr_cal[arr_index]/1000000)+'0');
	//6
	LCD_WriteChar(((arr_cal[arr_index]%1000000)/100000)+'0');
	//5
	LCD_WriteChar(((arr_cal[arr_index]%100000)/10000)+'0');
	//4
	LCD_WriteChar(((arr_cal[arr_index]%10000)/1000)+'0');
	//3
	LCD_WriteChar(((arr_cal[arr_index]%1000)/100)+'0');
	//2
	LCD_WriteChar(((arr_cal[arr_index]%100)/10)+'0');
	//1
	LCD_WriteChar(((arr_cal[arr_index]%10)/1)+'0');

	flagResult=1;
}

/********************************************************
 *
 * 				get_Num Function
 *
 ********************************************************/
void get_Num(u8 dig)
{
	 dig-='0';
	 arr_cal[arr_index]*=10;
	 arr_cal[arr_index]+=dig;
}


/********************************************************
 *
 * 				CheckNum Function
 *
 ********************************************************/
void CheckNum(u8 num)
{
	if((num!='*') && (num!='/') && (num!='+') && (num!='-'))
	{
		/***this means that the input is a number not an operator and store in in the array***/
		get_Num(num);
	}
	else
	{
		/****store the taken operator in the array****/
		arr_index++;
		arr_cal[arr_index]=num;
		arr_index++;
	}
}
//
//u8 checkOperators(void)
//{
//	for(u8 i=0;i<arr_index;i++)
//	{
//		if((arr_cal[i]=='*' && arr_cal[i-1]=='/') || (arr_cal[i]=='*' && arr_cal[i+1]=='/'))
//		{
////			return 1;
//			break;
//		}
//		if( (arr_cal[i]=='/' && arr_cal[i-1]=='*') || (arr_cal[i]=='/' && arr_cal[i+1]=='*'))
//		{
//			return 1;
//		}
//		if((arr_cal[i]=='+' && arr_cal[i-1]=='-') || (arr_cal[i]=='+' && arr_cal[i+1]=='-'))
//		{
//			return 1;
//		}
//		if( (arr_cal[i]=='-' && arr_cal[i-1]=='+') || (arr_cal[i]=='-' && arr_cal[i+1]=='+'))
//		{
//			return 1;
//		}
//		if( (arr_cal[i]=='-' && arr_cal[i-1]=='/') || (arr_cal[i]=='-' && arr_cal[i+1]=='/'))
//		{
//			return 1;
//		}
//		if( (arr_cal[i]=='/' && arr_cal[i-1]=='-') || (arr_cal[i]=='/' && arr_cal[i+1]=='-'))
//		{
//			return 1;
//		}
//		if( (arr_cal[i]=='*' && arr_cal[i-1]=='+') || (arr_cal[i]=='*' && arr_cal[i+1]=='+'))
//		{
//			return 1;
//		}
//		if( (arr_cal[i]=='+' && arr_cal[i-1]=='*') || (arr_cal[i]=='+' && arr_cal[i+1]=='*'))
//		{
//			return 1;
//		}
//		else
//		{
//			return -1;
//		}
//	}
//}


/********************************************************
 *
 * 				Calculator Function
 *
 ********************************************************/
void Calculator(void)
{
	key=KEYPAD_GetKey();

	if(key!=NO_KEY)
	{
		if(key=='=')
		{
			Cal_Result();
			DisplayResult();
		}
		if(key!='=')
		{
			/***when this flag =1 ,this means that the result was displayed on the LCD***/
			if(flagResult==1)
			{
				LCD_Clear();
				arr_index=0;
				flagResult=0;
				for(u8 i=0;i<arr_size;i++)
				{
					arr_cal[i]=0;
				}
			}
			CheckNum(key);
			LCD_GoTo(rowNum, colNum);
			LCD_WriteChar(key);
			colNum++;
			if(colNum==21)
			{
				rowNum++;
			}


		}
	}
}
