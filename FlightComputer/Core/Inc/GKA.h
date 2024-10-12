/*
 * GKA.h
 *
 *  Created on: Oct 12, 2024
 *      Author: m_yas
 */

#ifndef INC_GKA_H_
#define INC_GKA_H_

#include "stm32h7xx_hal.h"
#include "main.h"

class GKA {
public:
	GKA();
	virtual ~GKA();
	static void vGKAtask(void const* argument);
};

#endif /* INC_GKA_H_ */
