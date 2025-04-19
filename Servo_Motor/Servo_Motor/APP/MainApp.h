/*
 * MainApp.h
 *
 * Created: 4/19/2025 12:46:39 AM
 *  Author: hp
 */ 


#ifndef MAINAPP_H_
#define MAINAPP_H_


#define MODE_JOYSTICK 0
#define MODE_MOBILE   1
#define MODE_VOICE    2
#define MODE_EYE      3

void setup_modes_pins();
u8 get_mode(void);

void JoyStick_Mode();
void MobileApp_Mode();
void Voice_Mode();
void EyeTracking_Mode();

#endif /* MAINAPP_H_ */