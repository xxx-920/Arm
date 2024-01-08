# ifndef _BSP_SERVO_H
# define _BSP_SERVO_H

# include "stm32f10x.h"

/*----------------------函数定义----------------------*/
void Servo_Init(void);
void Servo_SetAngle1(float Angle);
void Servo_SetAngle2(float Angle);
void Servo_SetAngle3(float Angle);
void Servo_SetAngle4(float Angle);
void Servo1_SlowChange(float angle1, float angle2);
void Servo2_SlowChange(float angle1, float angle2);
void Servo3_SlowChange(float angle1, float angle2);
void Servo4_SlowChange(float angle1, float angle2);

# endif /*_BSP_SERVO_H*/
