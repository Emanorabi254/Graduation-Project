/*
 * DC_MOTOR_Interface.h
 *
 * Created: 4/15/2025 1:40:10 AM
 *  Author: Eman Orabi
 */ 


#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

void PWM_init();
void Motor_init();
void MoveForward();
void MoveBackward();
void MoveRight();
void MoveLeft();
void Stop();  



#endif /* DC_MOTOR_INTERFACE_H_ */