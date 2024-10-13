/*
 * IMU.cpp
 *
 *  Created on: Oct 12, 2024
 *      Author: m_yas
 */

#include "IMU.h"

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
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin,GPIO_PIN_SET);

	}
}
