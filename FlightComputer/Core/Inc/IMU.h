/*
 * IMU.h
 *
 *  Created on: Oct 12, 2024
 *      Author: m_yas
 */

#ifndef SRC_IMU_H_
#define SRC_IMU_H_

#include "stm32h7xx_hal.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

class IMU {
public:
	IMU();
	virtual ~IMU();
	static void vIMUtask(void const* argument);

};

#endif /* SRC_IMU_H_ */
