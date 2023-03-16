# include "stm32f10x.h"
# include "./ad/bsp_ad.h"
# include "./oled/oled.h"
# include "./tim/bsp_tim.h"
# include "./servo/bsp_servo.h"

uint16_t AD0, AD1, AD2, AD3;
float servo0, servo1, servo2, servo3;

int main(void){

	OLED_Init();
	Servo_Init();

	OLED_ShowString(1, 1, "A0");
	OLED_ShowString(2, 1, "A1");
	OLED_ShowString(3, 1, "A2");
	OLED_ShowString(4, 1, "A3");

	while(1){
 
		AD0 = ADC_GetValue(ADC_Channel_0);
		AD1 = ADC_GetValue(ADC_Channel_1);
		AD2 = ADC_GetValue(ADC_Channel_2);
		AD3 = ADC_GetValue(ADC_Channel_3);

		servo0 = (float)(4096-AD0)/4096*180;
		servo1 = (float)(4096-AD1)/4096*180;
		servo2 = (float)(4096-AD2)/4096*180;
		servo3 = (float)(4096-AD3)/4096*180;

		Servo_SetAngle1(servo0);
		Servo_SetAngle2(servo1);
		Servo_SetAngle3(servo2);
		Servo_SetAngle4(servo3);

		OLED_Showfloat(1, 11, servo0);
		OLED_Showfloat(2, 11, servo1);
		OLED_Showfloat(3, 11, servo2);
		OLED_Showfloat(4, 11, servo3);
	}
}
