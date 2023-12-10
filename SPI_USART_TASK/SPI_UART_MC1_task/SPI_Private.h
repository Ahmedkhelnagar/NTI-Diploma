/*
 * SPI_Private.h
 *
 *  Created on: Oct 30, 2023
 *      Author: dell
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*Clock polarity options */
#define IDLE_LOW   0
#define IDLE_HIGH  1

/*Clock phase options */
#define ZERO   0
#define ONE	   1

/*Data order*/
#define LSB_FIRST 		0
#define MSB_FIRST		1

/*SPI Frequency*/
#define PRESCALER_4		0
#define PRESCALER_16	1
#define PRESCALER_64	2
#define PRESCALER_128	3

/*Enable Interrupt*/
#define ENABLE_INTERRUPT  0
#define DISABLE_INTERRUPT 1

/*Speed modes*/
#define NORMAL_MODE  0
#define DOUBLE_MODE  1

#endif /* SPI_PRIVATE_H_ */
