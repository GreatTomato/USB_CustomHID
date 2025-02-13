/*
 * USB_Joystick.c
 *
 *  Created on: Jan 31, 2025
 *      Author: Tomato
 */

#include "USB_Joystick.h"
static uint8_t calulateAxis12to8Parabolic(uint16_t);

void joystick_mouse_conversion(uint16_t *adcJoystickValues, uint8_t *mouseReport) {
	mouseReport[1] = calulateAxis12to8Parabolic(adcJoystickValues[0]/16);
	mouseReport[2] = calulateAxis12to8Parabolic(adcJoystickValues[1]/16);
};

static uint8_t calulateAxis12to8Parabolic(uint16_t Axis) {
	if (Axis < (122)) {
		return (0xff-(122-Axis)/3);
	} else if (Axis < (134)) {
		return 0;
	} else {
		return ((Axis-134)/3);
	}
	return 0;
};

