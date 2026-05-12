#include "main.h"
#include <stdio.h>
#include <string.h>

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim2;

volatile uint16_t adc_value = 0;
volatile uint8_t adc_ready = 0;

char uart_buffer[64];

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    if (hadc->Instance == ADC1)
    {
        adc_ready = 1;
    }
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_DMA_Init();
    MX_USART2_UART_Init();
    MX_ADC1_Init();
    MX_TIM2_Init();

    HAL_TIM_Base_Start(&htim2);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adc_value, 1);

    while (1)
    {
        if (adc_ready)
        {
            adc_ready = 0;

            int len = snprintf(uart_buffer, sizeof(uart_buffer), "%u\r\n", adc_value);
            HAL_UART_Transmit(&huart2, (uint8_t*)uart_buffer, len, HAL_MAX_DELAY);
        }
    }
}
