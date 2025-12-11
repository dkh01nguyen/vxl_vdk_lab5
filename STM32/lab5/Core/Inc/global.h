#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

// ====================================================
// 1. CÁC ĐỊNH NGHĨA (DEFINE)
// ====================================================

#include "scheduler.h"
#include "software_timer.h"
#include "uart.h"
#include "fsm_machine.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_BUFFER_SIZE  30
#define NO_CMD           0
#define COMMAND_RST      1
#define COMMAND_OK       2
#define PARSER_INIT      0
#define PARSER_READING   1
#define UART_COMM_WAIT     0
#define UART_COMM_SEND     1
#define UART_COMM_WAIT_OK  2


extern uint8_t temp;                    // Ký tự vừa nhận
extern uint8_t buffer[MAX_BUFFER_SIZE]; // Mảng chứa dữ liệu thô (Circular Buffer)
extern uint8_t index_buffer;            // Chỉ số mảng thô
extern uint8_t buffer_flag;             // Cờ báo có dữ liệu mới

extern uint8_t parser_state;                    // Trạng thái máy Parser
extern uint8_t cmd_buffer[MAX_BUFFER_SIZE];     // Mảng chứa lệnh sạch để strcmp
extern uint8_t cmd_idx;                         // Chỉ số mảng lệnh
extern uint8_t command_flag;                    // Cờ báo: Đã nhận được lệnh hoàn chỉnh (!...#)
extern uint8_t command_data;                    // Dữ liệu lệnh: 1 là RST, 2 là OK

extern uint8_t uart_comm_status;    // Trạng thái máy giao tiếp
extern uint32_t saved_ADC_Value;    // Lưu giá trị ADC cũ để gửi lại (QUAN TRỌNG)

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

void fsm_init();
void ledBlink();

#endif /* INC_GLOBAL_H_ */
