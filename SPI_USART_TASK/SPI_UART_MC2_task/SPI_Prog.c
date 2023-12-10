/*
 * SPI_Prog.c
 *
 *  Created on: Oct 30, 2023
 *      Author: dell
 */

#define F_CPU 8000000UL
#include "StdTypes.h"
#include "Utils.h"
#include"MemMap.h"
#include "SPI_INTERFACE.h"


static void(*g_SPIResult)(void)=NULLPTR;

void SPI_voidMasterInit(void)
{
	/*Master select*/
	SET_BIT(SPCR,MSTR);

	/*clock polarity*/
	switch(CLOCK_PLOARITY)
	{
	case 0:
		CLR_BIT(SPCR,CPOL);
		break;
	case 1:
		SET_BIT(SPCR,CPOL);
		break;
	}

	switch(CLOCK_PHASE)
	{
	case 0:
		CLR_BIT(SPCR,CPHA);
		break;
	case 1:
		SET_BIT(SPCR,CPHA);
		break;
	}

	switch(DATA_ORDER)
	{
	case 0:
		SET_BIT(SPCR,DORD);
		break;
	case 1:
		CLR_BIT(SPCR,DORD);
		break;
	}

	switch(SPI_FREQUENCY)
	{
	case 0:
		CLR_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		CLR_BIT(SPCR,SPI2X);
		break;
	case 1:
		SET_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		CLR_BIT(SPCR,SPI2X);
		break;
	case 2:
		CLR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLR_BIT(SPCR,SPI2X);
		break;
	case 3:
		SET_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLR_BIT(SPCR,SPI2X);
		break;
	}

	switch(INTERRUPT_MODE)
	{
	case 0:
		SET_BIT(SPCR,SPIE);
		break;
	case 1:
		CLR_BIT(SPCR,SPIE);
		break;
	}

	switch(SPEED_MODE)
	{
	case 0:
		CLR_BIT(SPSR,SPI2X);
		break;
	case 1:
		SET_BIT(SPSR,SPSR);
		break;
	}

	SET_BIT(SPCR,SPE);	//enable SPI
}/*End of MasterInit*/

void SPI_voidSlaveInit(void)
{
	CLR_BIT(SPCR,MSTR);

	/*clock polarity*/
	switch(CLOCK_PLOARITY)
	{
	case 0:
		CLR_BIT(SPCR,CPOL);
		break;
	case 1:
		SET_BIT(SPCR,CPOL);
		break;
	}

	switch(CLOCK_PHASE)
	{
	case 0:
		CLR_BIT(SPCR,CPHA);
		break;
	case 1:
		SET_BIT(SPCR,CPHA);
		break;
	}

	switch(DATA_ORDER)
	{
	case 0:
		SET_BIT(SPCR,DORD);
		break;
	case 1:
		CLR_BIT(SPCR,DORD);
		break;
	}

	switch(SPI_FREQUENCY)
	{
	case 0:
		CLR_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		CLR_BIT(SPCR,SPI2X);
		break;
	case 1:
		SET_BIT(SPCR,SPR0);
		CLR_BIT(SPCR,SPR1);
		CLR_BIT(SPCR,SPI2X);
		break;
	case 2:
		CLR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLR_BIT(SPCR,SPI2X);
		break;
	case 3:
		SET_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLR_BIT(SPCR,SPI2X);
		break;
	}

	switch(INTERRUPT_MODE)
	{
	case 0:
		SET_BIT(SPCR,SPIE);
		break;
	case 1:
		CLR_BIT(SPCR,SPIE);
		break;
	}

	switch(SPEED_MODE)
	{
	case 0:
		CLR_BIT(SPSR,SPI2X);
		break;
	case 1:
		SET_BIT(SPSR,SPSR);
		break;
	}

	SET_BIT(SPCR,SPE);	//enable SPI
}/*End of SlaveInit*/


u8 SPI_u8Transfer(u8 Copy_Data)
{
	SPDR=Copy_Data;
	while(BIT_IS_CLEAR(SPSR,SPIF));
	return SPDR;
}

u8 SPI_u8Recieve(u8 Copy_Data)
{
	SPDR = Copy_Data;
	while(!READ_BIT(SPSR, SPIF));
	return SPDR;
}


u8 SPI_u8ReadDataISR(void)
{
	return SPDR;
}


void SPI_SendString(const u8 *Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		SPI_u8Transfer(Str[i]);
		i++;
	}
}

void SPI_ReceiveString(u8 *Str)
{
	unsigned char i = 0;
	Str[i] = SPI_u8ReadDataISR();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = SPI_u8ReadDataISR();
	}
	Str[i] = '\0';
}




void __vector_12 (void) __attribute__ ((signal,used, externally_visible));
void __vector_12 (void)
{
	if(g_SPIResult!=NULLPTR)
	{
		g_SPIResult();
	}
}


void SPI_voidSendDataISR(u8 Copy_Data)
{
	SPDR=Copy_Data;
}

void SPI_voidSetCallBack( void (*PtrToFunc) (void) )
{
	g_SPIResult=PtrToFunc;
}
