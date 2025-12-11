/*
 * uart.c
 *
 *  Created on: Nov 26, 2025
 *      Author: nguyen
 */

#include "uart.h"

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART2) {
        buffer_flag = 1;
        HAL_UART_Receive_IT(&huart2, &temp, 1);
    }
}

void cmd_parser_final(){
	if(buffer_flag == 1) {
		command_parser_fsm();
		buffer_flag = 0;
    }
}

