# include "./servo/bsp_servo.h"
# include "./tim/bsp_tim.h"
# include "./ad/bsp_ad.h"
# include "./delay/bsp_delay.h"

/**
  * @brief  伺服系统初始化
  * @param  无
  * @retval 无
  */
void Servo_Init(void){

    PWM_TIM_Init(); 
    ADCx_Init();
 }

/**
  * @brief  设置舵机 1 的角度
  * @param  无
  * @retval 无
  */
void Servo_SetAngle1(float Angle){

    PWM_SetCompare1(Angle / 180 * 2000 + 500);
}

/**
  * @brief  设置舵机 2 的角度
  * @param  无
  * @retval 无
  */
void Servo_SetAngle2(float Angle){

    PWM_SetCompare2(Angle / 180 * 2000 + 500);
}

/**
  * @brief  设置舵机 3 的角度
  * @param  无
  * @retval 无
  */
void Servo_SetAngle3(float Angle){

    PWM_SetCompare3(Angle / 180 * 2000 + 500);
}

/**
  * @brief  设置舵机 4 的角度
  * @param  无
  * @retval 无
  */
void Servo_SetAngle4(float Angle){

    PWM_SetCompare4(Angle / 180 * 2000 + 500);
}
