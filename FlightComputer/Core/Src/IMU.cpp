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
	LOGu("IMU Taska Giris\n");
	while(1)
	{
		LOGu("IMU\n");
		osDelay(1);


	}
}
