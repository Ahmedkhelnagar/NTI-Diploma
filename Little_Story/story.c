/*
 * story.c
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
#include<util/delay.h>

/***********Global Variables******/
u8 flagstory=0;

u8 Khaled[] = {0x04,0x04,0x0E,0x15,0x04,0x0A,0x11,0x00};

/*************Function definitions**************/
void Story_Init(void)
{
	DIO_Init();
	LCD_Init();
	LCD_CustomChar(0,Khaled);
}
void Story_Run(void)
{
	if(flagstory==0)
	{
		Story_Welcome();
	}
	else if(flagstory==1)
	{
		MyStory();
	}
	else{}
}


void Story_Welcome(void)
{
	LCD_GoTo(1,3);
	LCD_WriteString("    Hello!      ");

	_delay_ms(1000);
	LCD_Clear();

	/****Printing khaled****/
	LCD_GoTo(1, 19);
	LCD_WriteChar(0);

	LCD_GoTo(1,1);
	_delay_ms(500);
	LCD_WriteString("This is ME ,I'll ");

	LCD_GoTo(2,1);
	_delay_ms(500);
	LCD_WriteString("talk with you ");

	LCD_GoTo(3,1);
	_delay_ms(500);
	LCD_WriteString("about my Story.");

	_delay_ms(2000);
	LCD_Clear();
	flagstory=1;
}

void MyStory(void)
{
	LCD_GoTo(0,0);
	LCD_WriteString("let's go back throw ");

	LCD_GoTo(1,0);
	_delay_ms(500);
	LCD_WriteString("at 2020,here the ");

	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("change point of ");

	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("my life.As my father ");

	_delay_ms(1000);
	LCD_Clear(); //clear

	LCD_GoTo(0,0);
	_delay_ms(500);
	LCD_WriteString("died before the ");


	LCD_GoTo(1,0);
	_delay_ms(500);
	LCD_WriteString("beginning of my last ");

	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("year in college.");

	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("i can't tell u how ");

	_delay_ms(1000);
	LCD_Clear();  //clear

	LCD_GoTo(0,0);
	_delay_ms(500);
	LCD_WriteString("this year was ");

	LCD_GoTo(1,0);
	_delay_ms(500);
	LCD_WriteString("difficult for me ");

	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("cuz u can't fall ");


	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("down or be weak ");

	_delay_ms(1000);
	LCD_Clear();  //clear

	LCD_GoTo(0,0);
	_delay_ms(500);
	LCD_WriteString("besides the grad ");

	LCD_GoTo(1,0);
	_delay_ms(500);
	LCD_WriteString("Project and the ");

	LCD_GoTo(2,0);
	_delay_ms(1000);
	LCD_WriteString("difficultness of ");

	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("Engineering AinShams.");

	_delay_ms(1000);
	LCD_Clear(); //clear

	LCD_GoTo(0,0);
	_delay_ms(500);
	LCD_WriteString("but there's no ");

	LCD_GoTo(1,0);
	_delay_ms(500);
	LCD_WriteString("something impossible");

	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("Every thing need ");

	LCD_GoTo(3,0);
	_delay_ms(1000);
	LCD_WriteString("Patience and Diligence.");

	_delay_ms(1000);
	LCD_Clear();	//clear

	LCD_GoTo(0,0);
	_delay_ms(500);
	LCD_WriteString("So,here i'm now ");

	LCD_GoTo(1,0);
	_delay_ms(500);
	LCD_WriteString("graduated and ");

	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("meantime i'm  ");

	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("a trainee at NTI ");

	_delay_ms(1000);
	LCD_Clear();	//clear

	LCD_GoTo(0,0);
	_delay_ms(500);
	LCD_WriteString("4 months smart ");

	LCD_GoTo(1,0);
	_delay_ms(500);
	LCD_WriteString("village branch ");

	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("at Group 3 ");

	_delay_ms(1000);
	LCD_Clear();	//clear

	LCD_GoTo(2,3);
	_delay_ms(500);
	LCD_WriteString("The End..");
}









