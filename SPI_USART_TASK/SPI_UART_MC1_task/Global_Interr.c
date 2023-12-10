/*
 * inter.c
 *
 *  Created on: Oct 22, 2023
 *      Author: dell
 */


#include "GLOBAL_Interr.h"
#include"Utils.h"
#include"MemMap.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);

}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);
}
