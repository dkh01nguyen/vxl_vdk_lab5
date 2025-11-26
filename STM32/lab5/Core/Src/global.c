/*
 * global.c
 *
 *  Created on: Nov 26, 2025
 *      Author: nguyen
 */


#include "global.h"

void LEDBlinky() {
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

