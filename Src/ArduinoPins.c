/*
 * ArduinoPins.c
 *
 *  Created on: Aug 6, 2019
 *      Author: muman
 */


#include "ArduinoPins.h"

/**
 * This structure is used to translate pin # to GPIO Port and Pin on STM32
 */
#if 0
struct digitalPinEntry arduinoPinTable[] = {
		{ GPIOA, GPIO_PIN_3 },							// D0
		{ GPIOA, GPIO_PIN_2 },							// D1
		{ GPIOC, GPIO_PIN_6 },							// D2
		{ GPIOA, GPIO_PIN_10 },							// D3
		{ GPIOC, GPIO_PIN_10 }, 						// D4
		{ GPIOA, GPIO_PIN_15 },							// D5
		{ GPIOA, GPIO_PIN_8 },							// D6
		{ GPIOC, GPIO_PIN_13 },							// D7

		{ GPIOC, GPIO_PIN_12 },							// D8
		{ GPIOA, GPIO_PIN_9 },							// D9
		{ GPIOA, GPIO_PIN_4 },							// D10
		{ GPIOA, GPIO_PIN_7 },							// D11
		{ GPIOA, GPIO_PIN_6 },							// D12
		{ GPIOA, GPIO_PIN_5 },							// D13
		{ GPIOB, GPIO_PIN_9 },							// D14
		{ GPIOB, GPIO_PIN_8 },							// D15
};
#endif
#ifdef STM32F413xx
struct digitalPinEntry arduinoPinTable[] = {
		{ GPIOG, GPIO_PIN_9 },							// D0
		{ GPIOG, GPIO_PIN_14 },							// D1
		{ GPIOF, GPIO_PIN_15 },							// D2
		{ GPIOE, GPIO_PIN_13 },							// D3
		{ GPIOF, GPIO_PIN_14 }, 						// D4
		{ GPIOE, GPIO_PIN_11 },							// D5
		{ GPIOE, GPIO_PIN_9 },							// D6
		{ GPIOF, GPIO_PIN_13 },							// D7

		{ GPIOF, GPIO_PIN_12 },							// D8
		{ GPIOD, GPIO_PIN_15 },							// D9
		{ GPIOD, GPIO_PIN_14 },							// D10
		{ GPIOA, GPIO_PIN_7 },							// D11
		{ GPIOA, GPIO_PIN_6 },							// D12
		{ GPIOA, GPIO_PIN_5 },							// D13
		{ GPIOB, GPIO_PIN_9 },							// D14
		{ GPIOB, GPIO_PIN_8 },							// D15
};
#endif


/**
 * Write a value to a pin, using the arduino pin #.
 */
void digitalWrite(int pin, GPIO_PinState value) {
	HAL_GPIO_WritePin(arduinoPinTable[pin].port, arduinoPinTable[pin].pin, value);
}

GPIO_PinState digitalRead(int pin) {
	return HAL_GPIO_ReadPin(arduinoPinTable[pin].port, arduinoPinTable[pin].pin);
}

void togglePin(int pin) {
	HAL_GPIO_TogglePin(arduinoPinTable[pin].port, arduinoPinTable[pin].pin);
}
