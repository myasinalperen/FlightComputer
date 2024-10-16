/*
 * SistemYapilandirici.cpp
 *
 *  Created on: Oct 12, 2024
 *      Author: m_yas
 */

#define taskSize  ( ( size_t ) ( 1 * 512 ) )  // Örneğin 1KB heap


#include <SistemYapilandirici.h>

/**
 * @brief SistemYapilandirici constructor
 */

 SistemYapilandirici::SistemYapilandirici()
{
	 //Instance();
	islevBaslat();
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
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin,GPIO_PIN_SET);


    /* definition and creation of IMUtask */
    osThreadId IMUtaskHandle;
    osThreadDef(IMUtask, IMU::vIMUtask, osPriorityNormal, 0, taskSize);
    IMUtaskHandle = osThreadCreate(osThread(IMUtask), NULL);
    // Task'ın başarıyla oluşturulup oluşturulmadığını kontrol et
    if (IMUtaskHandle == NULL)
    {
    	// Hata yönetimi

    }
    else
    {

    }


	  /* definition and creation of GPStask */
		osThreadId GPStaskHandle;
	  osThreadDef(GPStask, GPS::vGPStask, osPriorityNormal, 0, taskSize);
	  GPStaskHandle = osThreadCreate(osThread(GPStask), NULL);
	    // Task'ın başarıyla oluşturulup oluşturulmadığını kontrol et
	    if (GPStaskHandle == NULL)
	    {
	        // Hata yönetimi
	    	/*printf("ERROR: GPStask basariyla olusturuldu \n");*/
	    }
	    else
	    {
	    	/*printf("GPStask basariyla olusturuldu");*/
	    }




	    /* definition and creation of GKAtask */
	    osThreadId GKAtaskHandle;
		osThreadDef(GKAtask, GKA::vGKAtask, osPriorityNormal, 0, taskSize);
	    GKAtaskHandle = osThreadCreate(osThread(GKAtask), NULL);
	    // Task'ın başarıyla oluşturulup oluşturulmadığını kontrol et
	    if (GKAtaskHandle == NULL)
	    {
	    	// Hata yönetimi
	    }
	    else
	    {

	    }

	    /* definition and creation of GKAtask */
	    osThreadId NAVtaskHandle;
	    osThreadDef(NAVtask,NAV::vNAVtask, osPriorityNormal, 0, taskSize);
	    NAVtaskHandle = osThreadCreate(osThread(NAVtask), NULL);
	    // Task'ın başarıyla oluşturulup oluşturulmadığını kontrol et
	    if (NAVtaskHandle == NULL)
	    {
	    	// Hata yönetimi
	    }
	    else
	    {

	    }

	    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin,GPIO_PIN_RESET);



	}
