/*
 * GPS.cpp
 *
 *  Created on: Oct 12, 2024
 *      Author: m_yas
 */

#include "GPS.h"

GPS::GPS() {
	// TODO Auto-generated constructor stub

}

GPS::~GPS() {
	// TODO Auto-generated destructor stub
}

 void GPS::vGPStask(void const* argument)
{
    while (1) {

		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin,GPIO_PIN_SET);
        // Task code goes here
    }
}
