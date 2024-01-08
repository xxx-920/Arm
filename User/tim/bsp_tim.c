# include "./tim/bsp_tim.h"

/**
 *  @brief  TIM GPIO 初始化
 *  @param  无
 *  @retval 无
 */
static void PWM_TIM_GPIO_Config(void){

    RCC_APB2PeriphClockCmd(PWM_TIM_CH1_GPIO_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(PWM_TIM_CH3_GPIO_CLK, ENABLE);

    /*配置上拉输入*/
    GPIO_InitTypeDef    GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = PWM_TIM_CH1_PIN | PWM_TIM_CH2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(PWM_TIM_CH1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PWM_TIM_CH3_PIN | PWM_TIM_CH4_PIN;
    GPIO_Init(PWM_TIM_CH3_PORT, &GPIO_InitStructure);
}

/**
 *  @brief  TIM 模式初始化
 *  @param  无
 *  @retval 无
 */
static void PWM_TIM_Mode_Config(void){

    PWM_TIM_APBxClock_FUN(PWM_TIM_CLK, ENABLE);

    /*---------------时基配置---------------*/
    TIM_InternalClockConfig(PWM_TIM);       //选择内部时钟
    TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_Period = PWM_ARR_Period;
    TIM_TimeBaseStructure.TIM_Prescaler = PWM_PSC_Prescaler;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseStructure);

    /*---------------输出通道配置---------------*/
    TIM_OCInitTypeDef       TIM_OCInitStructure;
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;       //PWM1模式
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   //高电平有效
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能
    TIM_OCInitStructure.TIM_Pulse = 0;      //CCR
    TIM_OC1Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_OC2Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_OC3Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_OC4Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_Cmd(PWM_TIM, ENABLE);       //使能定时器
}

/**
 *  @brief  TIM 初始化
 *  @param  无
 *  @retval 无
 */
void PWM_TIM_Init(void){

    PWM_TIM_GPIO_Config();
    PWM_TIM_Mode_Config();
}

/**
 *  @brief  设置通道 1占空比
 *  @param  无
 *  @retval 无
 */
void PWM_SetCompare1(uint16_t Compare){
    TIM_SetCompare1(PWM_TIM, Compare);
}

/**
 *  @brief  设置通道 2占空比
 *  @param  无
 *  @retval 无
 */
void PWM_SetCompare2(uint16_t Compare){
    TIM_SetCompare2(PWM_TIM, Compare);
}

/**
 *  @brief  设置通道 3占空比
 *  @param  无
 *  @retval 无
 */
void PWM_SetCompare3(uint16_t Compare){
    TIM_SetCompare3(PWM_TIM, Compare);
}

/**
 *  @brief  设置通道 4占空比
 *  @param  无
 *  @retval 无
 */
void PWM_SetCompare4(uint16_t Compare){
    TIM_SetCompare4(PWM_TIM, Compare);
}
