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
#include "string.h"
#include "cmsis_os.h"
#include "LOG.h"
#include <SistemYapilandirici.h>



#include <stdint.h>
#include "main.h"
extern I2C_HandleTypeDef hi2c1;

typedef struct {
    int16_t Accel_X_RAW;
    int16_t Accel_Y_RAW;
    int16_t Accel_Z_RAW;
    double Ax;
    double Ay;
    double Az;

    int16_t Gyro_X_RAW;
    int16_t Gyro_Y_RAW;
    int16_t Gyro_Z_RAW;
    double Gx;
    double Gy;
    double Gz;

    float Temperature;

    double KalmanAngleX;
    double KalmanAngleY;
}MPU6050_t;



typedef struct {
    double Q_angle;
    double Q_bias;
    double R_measure;
    double angle;
    double bias;
    double P[2][2];
}Kalman_t;

class IMU {
public:
	IMU();
	virtual ~IMU();
	static void vIMUtask(void const* argument);

	uint8_t MPU6050_Init(I2C_HandleTypeDef *I2Cx);

	void MPU6050_Read_Accel(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

	void MPU6050_Read_Gyro(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

	void MPU6050_Read_Temp(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

	void MPU6050_Read_All(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

	double Kalman_getAngle(Kalman_t *Kalman, double newAngle, double newRate, double dt);

};

#endif /* SRC_IMU_H_ */
