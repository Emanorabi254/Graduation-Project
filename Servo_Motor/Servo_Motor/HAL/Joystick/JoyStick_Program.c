/*
 * JoyStick_Program.c
 *
 * Created: 4/18/2025 2:56:43 AM
 *  Author: Eman Orabi
 */ 

#include "STD_TYPES.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

void JoyStick_init() {
	u16 x = ADC_Read(0); // Reading VRx
	u16 y = ADC_Read(1); // Reading VRy
	
	if (x < 400) {
		MoveLeft();
		ShowingTheValue('L');
		} else if (x > 600) {
		MoveRight();
		ShowingTheValue('R');
		} else if (y < 400) {
		MoveBackward();
		ShowingTheValue('B');
		} else if (y > 600) {
		MoveForward();
		ShowingTheValue('F');
		} else {
		Stop();
		ShowingTheValue('S');
	}
}