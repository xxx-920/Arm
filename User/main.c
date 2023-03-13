# include "stm32f10x.h"
# include "./ad/bsp_ad.h"
# include "./oled/oled.h"
# include "./tim/bsp_tim.h"

int main(void){

	OLED_Init();
	ADCx_Init();
	PWM_TIM_Init();

	while(1){


	}
}
