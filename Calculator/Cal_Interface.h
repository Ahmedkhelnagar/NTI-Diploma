/*
 * Cal_Interface.h
 *
 *  Created on: Nov 8, 2023
 *      Author: AhmedKhaled
 */

#ifndef CAL_INTERFACE_H_
#define CAL_INTERFACE_H_

void Cal_Init(void);
void ShiftArray(u8 index);
void Cal_Result(void);
void DisplayResult(void);
void get_Num(u8 dig);
void CheckNum(u8 num);
//u8 checkOperators(void);
void Calculator(void);

#endif /* CAL_INTERFACE_H_ */
