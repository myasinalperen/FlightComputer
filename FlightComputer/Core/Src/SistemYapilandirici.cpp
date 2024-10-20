/*
 * SistemYapilandirici.cpp
 *
 *  Created on: Oct 12, 2024
 *      Author: m_yas
 */

#define taskSize  ( ( size_t ) ( 1 * 512 ) )  // Örneğin 1KB heap


#include <SistemYapilandirici.h>
#include "IMU.h"
#include "LOG.h"
/**
 * @brief SistemYapilandirici constructor
 */

 SistemYapilandirici::SistemYapilandirici()
{
	 //Instance();
	 if(!SistemYapilandiriciBaslatildi)
	 {
    	islevBaslat();
    	return;
	 }

}



/**
 * @brief SistemYapilandirici deconstructor
 */
 SistemYapilandirici::~SistemYapilandirici()
{
	}

 /**
  * @brief SistemYapilandirici deconstructor
  */
void SistemYapilandirici::Instance()
 {
	  GPS m_GPS;
	  NAV m_NAV;

 	}

/**
 * @brief Sistemde olan tasklari baslatir
 */
void SistemYapilandirici::islevBaslat()
{


    /* definition and creation of IMUtask */
    osThreadId IMUtaskHandle;
    osThreadDef(IMUtask, IMU::vIMUtask, osPriorityAboveNormal, 0, taskSize);
    IMUtaskHandle = osThreadCreate(osThread(IMUtask), NULL);
    // Task'ın başarıyla oluşturulup oluşturulmadığını kontrol et
    if (IMUtaskHandle == NULL)
    {
    	LOGu("IMUtask olusturulamadi \n");

    }
    else
    {
    	LOGu("IMUtask olusturuldu \n");

    }


	  /* definition and creation of GPStask */
		osThreadId GPStaskHandle;
	  osThreadDef(GPStask, GPS::vGPStask, osPriorityAboveNormal, 0, taskSize);
	  GPStaskHandle = osThreadCreate(osThread(GPStask), NULL);
	    // Task'ın başarıyla oluşturulup oluşturulmadığını kontrol et
	    if (GPStaskHandle == NULL)
	    {
	    	LOGu("GPStask olusturulamadi \n");
	    }
	    else
	    {
	    	LOGu("GPStask olusturuldu \n");
	    }




#if 0
	    /* definition and creation of GKAtask */
	    osThreadId NAVtaskHandle;
	    osThreadDef(NAVtask,NAV::vNAVtask, osPriorityNormal, 0, taskSize);
	    NAVtaskHandle = osThreadCreate(osThread(NAVtask), NULL);
	    // Task'ın başarıyla oluşturulup oluşturulmadığını kontrol et
	    if (NAVtaskHandle == NULL)
	    {
	    	LOGu("NAVtask olusturulamadi \n");
	    }
	    else
	    {
	    	LOGu("NAVtask olusturuldu \n");
	    }
#endif

	    LOGu("Sistem Yapilandirici Bitti\n");
	    SistemYapilandiriciBaslatildi=true;

return;
	}
