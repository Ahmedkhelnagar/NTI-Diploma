/*
 * SPI_config.h
 *
 *  Created on: Oct 30, 2023
 *      Author: dell
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include"SPI_Private.h"

#define CLOCK_PLOARITY   IDLE_LOW
#define CLOCK_PHASE		 ZERO
#define DATA_ORDER 		 LSB_FIRST
#define SPI_FREQUENCY  	 PRESCALER_4
#define INTERRUPT_MODE 	 ENABLE_INTERRUPT
#define SPEED_MODE 		 NORMAL_MODE
#endif /* SPI_CONFIG_H_ */
