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

extern UART_HandleTypeDef huart2;



void LOGu(const char *format, ...)
{
    char message[100]; // Mesajı tutacak bir dizi
    va_list args; // Değişken argümanlar için
    va_start(args, format); // Argüman listesini başlat

    // Mesajı formatlayın
    vsnprintf(message, sizeof(message), format, args);

    va_end(args); // Argüman listesini sonlandır

    // Mesajı UART üzerinden gönderin
    if (HAL_UART_Transmit(&huart2, (uint8_t *)message, strlen(message), 1000) != HAL_OK)
    {
        // Hata durumu yönetimi
    }
}


