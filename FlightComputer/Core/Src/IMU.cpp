/*
 * IMU.cpp
 *
 *  Created on: Oct 12, 2024
 *      Author: m_yas
 */

#include "IMU.h"
#include "string.h"
#include "cmsis_os.h"

IMU::IMU() {
	// TODO Auto-generated constructor stub

}

IMU::~IMU() {
	// TODO Auto-generated destructor stub
}

void IMU::vIMUtask(void const* argument)
{

	while(1)
	{
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin,GPIO_PIN_SET);

		osDelay(1000);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin,GPIO_PIN_RESET);

		osDelay(1000);


	}
}
