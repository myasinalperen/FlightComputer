/*
 * SistemYapilandirici.h
 *
 *  Created on: Oct 12, 2024
 *      Author: m_yas
 */

#ifndef SRC_SISTEMYAPILANDIRICI_H_
#define SRC_SISTEMYAPILANDIRICI_H_

#include "main.h"
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"

#include <GPS.h>
#include <IMU.h>
#include <NAV.h>




class SistemYapilandirici{
public:

	SistemYapilandirici();
~SistemYapilandirici();

private:
bool SistemYapilandiriciBaslatildi=false;
void islevBaslat();
void Instance();


};



#endif /* SRC_SISTEMYAPILANDIRICI_H_ */
