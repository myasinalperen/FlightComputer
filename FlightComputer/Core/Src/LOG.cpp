/*
 * LOG.cpp
 *
 *  Created on: Oct 19, 2024
 *      Author: m_yas
 */

#include "LOG.h"
#include "main.h"
#include <stdio.h> // snprintf için
#include <string.h> // strlen için
#include "main.h"
#include "stm32h7xx_hal.h"
#include "FreeRTOS.h"
#include <stdarg.h>
extern UART_HandleTypeDef huart2;
extern osMutexId LogMutexHandle;


void LOGu(const char *format, ...)
{
    char message[300]; // Mesajı tutacak bir dizi
    va_list args; // Değişken argümanlar için
    va_start(args, format); // Argüman listesini başlat

    // Mesajı formatlayın
    vsnprintf(message, sizeof(message), format, args);

    va_end(args); // Argüman listesini sonlandır

    // Mutex ile UART erişimini güvenli hale getirin
    if (osMutexWait(LogMutexHandle, osWaitForever) == osOK)
    {
        // Mesajı UART üzerinden gönderin
        if (HAL_UART_Transmit(&huart2, (uint8_t *)message, strlen(message), 10) != HAL_OK)
        {
            // Hata durumu yönetimi
        }

        // UART erişimi bitti, mutex'i bırak
        osMutexRelease(LogMutexHandle);
    }
}

