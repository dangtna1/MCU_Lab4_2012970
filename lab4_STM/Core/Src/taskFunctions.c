/*
 * taskFunctions.c
 *
 *  Created on: Nov 23, 2022
 *      Author: tamqu
 */

#include "taskFunctions.h"
#include "stdlib.h"

void task1(){
	HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin|LED_RED3_Pin|LED_RED4_Pin|LED_RED5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
}
void task2(){
	HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_RED3_Pin|LED_RED4_Pin|LED_RED5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
}
void task3(){
	HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin|LED_RED1_Pin|LED_RED4_Pin|LED_RED5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED3_GPIO_Port, LED_RED3_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_TogglePin(LED_RED3_GPIO_Port, LED_RED3_Pin);
}
void task4(){
	HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin|LED_RED3_Pin|LED_RED1_Pin|LED_RED5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED4_GPIO_Port, LED_RED4_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_TogglePin(LED_RED4_GPIO_Port, LED_RED4_Pin);
}
void task5(){
//	update_ledbuffer();
	HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin|LED_RED3_Pin|LED_RED4_Pin|LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED5_GPIO_Port, LED_RED5_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_TogglePin(LED_RED5_GPIO_Port, LED_RED5_Pin);
}
