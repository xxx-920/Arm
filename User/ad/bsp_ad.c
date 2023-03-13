# include "./ad/bsp_ad.h"

/**
 *  @brief  ADC GPIO 配置
 *  @param  无
 *  @retval 无
 */
static void ADC_GPIO_Config(void){

    RCC_APB2PeriphClockCmd(ADCx_IN1_GPIO_CLK, ENABLE);   ///开启时钟树

    /*ADC 通道1 GPIO初始化*/
    GPIO_InitTypeDef    GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = ADCx_IN1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(ADCx_IN1_PORT, &GPIO_InitStructure);

    /*ADC 通道2 GPIO初始化*/
    GPIO_InitStructure.GPIO_Pin = ADCx_IN2_PIN;
    GPIO_Init(ADCx_IN2_PORT, &GPIO_InitStructure);

    /*ADC 通道3 GPIO初始化*/
    GPIO_InitStructure.GPIO_Pin = ADCx_IN3_PIN;
    GPIO_Init(ADCx_IN3_PORT, &GPIO_InitStructure);

    /*ADC 通道4 GPIO初始化*/
    GPIO_InitStructure.GPIO_Pin = ADCx_IN4_PIN;
    GPIO_Init(ADCx_IN4_PORT, &GPIO_InitStructure);
}

static void ADC_Mode_Config(void){

    /*开启ADC 时钟*/
    ADCx_APBxClock_FUN(ADCx_CLK, ENABLE);

    ADC_InitTypeDef     ADC_InitStructure;
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;      //配置独立模式
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  //配置右对齐
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;     //配置外部触发为没有
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;     //禁止连续模式
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;           //关闭扫描模式
    ADC_InitStructure.ADC_NbrOfChannel = 1;                 //选择用到的通道数目为1
    ADC_Init(ADCx, &ADC_InitStructure);

    /*使能ADC*/
    ADC_Cmd(ADCx, ENABLE);

    /*ADC 校准*/
    ADC_ResetCalibration(ADCx);     //复位校准
    while(ADC_GetResetCalibrationStatus(ADCx) == SET);      //等待复位校准成功
    ADC_StartCalibration(ADCx);     //开始校准
    while(ADC_GetCalibrationStatus(ADCx) == SET);           //等待校准完成
}

/**
 *  @brief  ADC 初始化
 *  @param  无
 *  @retval 无
 */
void ADCx_Init(void){

    ADC_GPIO_Config();
    ADC_Mode_Config();
}

/**
 *  @brief  获取ADC结果
 *  @param  无
 *  @retval 无
 */
uint16_t ADC_GetValue(uint8_t ADC_Channel){

    ADC_RegularChannelConfig(ADCx, ADC_Channel, 1, ADC_SampleTime_55Cycles5);       //填充通道
    ADC_SoftwareStartConvCmd(ADCx, ENABLE);     //软件触发转化
    while(ADC_GetFlagStatus(ADCx, ADC_FLAG_EOC) == RESET);      //获取标志位

    return ADC_GetConversionValue(ADCx);
}
