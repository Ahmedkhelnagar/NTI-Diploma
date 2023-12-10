/*
 * UART_PROG.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Ahmed
 */
#define F_CPU 8000000UL
#include "StdTypes.h"
#include "Utils.h"
#include"MemMap.h"
#include "UART_INTERFACE.h"

static void(*g_InterrResult)(void)=NULLPTR;


void UART_init( u16 baud )
{
//	u16 UBRR = (F_CPU / (2* baud))-1;
//	u16 UBRR = (((F_CPU / (baud * 8UL))) - 1);
//	UBRRH = (UBRR>>8);
//	UBRRL = UBRR;
	SET_BIT(UCSRC,URSEL);
	UBRRL=51;

	CLR_BIT(UCSRC,URSEL);
	switch(UART_CHAR_SIZE)
	{
	case 0:
		CLR_BIT(UCSRC, UCSZ0);
		CLR_BIT(UCSRC, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
	case 1:
		SET_BIT(UCSRC, UCSZ0);
		CLR_BIT(UCSRC, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
	case 2:
		CLR_BIT(UCSRC, UCSZ0);
		SET_BIT(UCSRC, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
	case 3:
		SET_BIT(UCSRC, UCSZ0);
		SET_BIT(UCSRC, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
	case 4:
		SET_BIT(UCSRC, UCSZ0);
		SET_BIT(UCSRC, UCSZ1);
		SET_BIT(UCSRB, UCSZ2);
		break;

	}
	switch(USART_Mode_Select)
	{
	case 0:
		CLR_BIT(UCSRC, UMSEL);
		switch(SPEED_MODE)
		{
		case 0:
			CLR_BIT(UCSRA, U2X);
			break;
		case 1:
			SET_BIT(UCSRA, U2X);
			break;
		}
		break;
		case 1:
			SET_BIT(UCSRC, UMSEL);
			if(READ_BIT(UCSRB,TXEN)==1)
			{
				switch(CLOCK_POLARITY)
				{
				case 0:
					CLR_BIT(UCSRC, UCPOL);
					break;
				case 1:
					SET_BIT(UCSRC, UCPOL);
					break;
				}
			}
			if(READ_BIT(UCSRB,RXEN)==1)
			{
				switch(CLOCK_POLARITY)
				{
				case 0:
					CLR_BIT(UCSRC, UCPOL);
					break;
				case 1:
					SET_BIT(UCSRC, UCPOL);
					break;
				}
			}


		break;
	}

	switch(PARITY_MODE)
	{
	case 0:
		CLR_BIT(UCSRC, UPM0);
		CLR_BIT(UCSRC, UPM1);
		break;
	case 1:
		CLR_BIT(UCSRC, UPM0);
		SET_BIT(UCSRC, UPM1);
		break;
	case 2:
		SET_BIT(UCSRC, UPM0);
		SET_BIT(UCSRC, UPM1);
		break;
	}

	switch(STOP_BIT_SELECT)
		{
		case 0:
			CLR_BIT(UCSRC, USBS);
			break;
		case 1:
			SET_BIT(UCSRC, USBS);
			break;
		}

}/*end of uart_init*/


void UART_RX_ENABLE(void)
{
	SET_BIT(UCSRB, RXEN);

}
void UART_RX_DISABLE(void)
{
	CLR_BIT(UCSRB, RXEN);

}
void UART_TX_ENABLE(void)
{
	SET_BIT(UCSRB, TXEN);

}
void UART_TX_DISABLE(void)
{
	CLR_BIT(UCSRB, TXEN);

}


void USART_Transmit( u8 data )
{
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC));
	//SET_BIT(UCSRA,TXC);	//this line used when Asynchrounous not synch.
}
u8 USART_Receive( )
{
	while(BIT_IS_CLEAR(UCSRA,RXC)); //this line not used because we use interrupt
	return UDR;
}
void UART_String_Transmit( u8* data )
{
	while( data != '\0')
	{
		USART_Transmit(*data);
		data++;
	}
}

void UART_receiveString(u8 *Str)
{
	u8 i = 0;
	Str[i] = USART_Receive();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = USART_Receive();
	}
	Str[i] = '\0';
}

//
//void Uart_Enable_Interr(void)
//{
//	SET_BIT(UCSRB,RXCIE);
//}
//
//
//
//void Interr_SetCallback( void (*ptr) (void) )
//{
//	g_InterrResult=ptr;
//}
//
//
//void __vector_13 (void) __attribute__ ((signal,used, externally_visible));
//void __vector_13 (void)
//{
//	if(g_InterrResult!=NULLPTR)
//	{
//		g_InterrResult();
//	}
//}


