/*
 * NAV.h
 *
 *  Created on: Oct 12, 2024
 *      Author: m_yas
 */

#ifndef SRC_NAV_H_
#define SRC_NAV_H_

#include "stm32h7xx_hal.h"
#include "main.h"
#include "LOG.h"
#include <SistemYapilandirici.h>

class NAV {
public:
	NAV();
	virtual ~NAV();
	static void vNAVtask(void const* argument);
};

#endif /* SRC_NAV_H_ */
