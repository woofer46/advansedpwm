#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include <stm32f4xx_syscfg.h>


int main(void)
{
	SystemInit();
	SysTick_Config(SystemCoreClock/1000);


    while(1)
    {
    	// Инициализация настроек для двигателя 2
    	//-------------------------------------------------------------------------------
    	//-------------------------------------------------------------------------------
    	// Верхний ключ  Hin1.1 Hin1.2 Hin1.3
    	//-------------------------------------------------------------------------------
    	//Настройка Таймера 1 для трехфазного ШИМ
    	TIM_TimeBaseInitTypeDef TIM_Time_Test_user1;
    	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);//
    	TIM_Time_Test_user1.TIM_Prescaler = 0;//
    	TIM_Time_Test_user1.TIM_CounterMode = TIM_CounterMode_Up;//
    	TIM_Time_Test_user1.TIM_Period=2000;//умножить на 2 потому что 32 бита
    	TIM_Time_Test_user1.TIM_ClockDivision = TIM_CKD_DIV1;//
    	TIM_Time_Test_user1.TIM_RepetitionCounter = 0;//
    	TIM_TimeBaseInit(TIM1, &TIM_Time_Test_user1);
    	//-------------------------------------------------------------------------------
    	// Порты выхода ШИМ Hin1.1 Hin1.2 Hin1.3
    	GPIO_InitTypeDef GPIO_InitPWM3;//
    	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//
    	GPIO_InitPWM3.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_10;
    	GPIO_InitPWM3.GPIO_Mode = GPIO_Mode_AF; //
    	GPIO_InitPWM3.GPIO_OType = GPIO_OType_PP;//
    	GPIO_InitPWM3.GPIO_Speed = GPIO_Speed_100MHz;//
    	GPIO_InitPWM3.GPIO_PuPd = GPIO_PuPd_NOPULL;//
    	GPIO_Init(GPIOA, &GPIO_InitPWM3);//

    	GPIO_InitTypeDef GPIO_InitPWM4;//
    	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//
    	GPIO_InitPWM4.GPIO_Pin = GPIO_Pin_11;
    	GPIO_InitPWM4.GPIO_Mode = GPIO_Mode_AF; //
    	GPIO_InitPWM4.GPIO_OType = GPIO_OType_PP;//
    	GPIO_InitPWM4.GPIO_Speed = GPIO_Speed_100MHz;//
    	GPIO_InitPWM4.GPIO_PuPd = GPIO_PuPd_NOPULL;//
    	GPIO_Init(GPIOE, &GPIO_InitPWM4);//

    	GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1); // открыть порты шима
    	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);
    	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_TIM1);
    	//-------------------------------------------------------------------------------
    	// Настройка ШИМ
    	TIM_OCInitTypeDef Hard_PWM_ini3;
    	Hard_PWM_ini3.TIM_OCMode=TIM_OCMode_PWM2;//
    	Hard_PWM_ini3.TIM_OutputState=TIM_OutputState_Enable;//  ВКЛ/выкл
    	//Hard_PWM_ini2.TIM_OutputNState = TIM_OutputNState_Disable;//
        Hard_PWM_ini3.TIM_Pulse=400;// длинна пульса (пятая часть от периода)//
    	Hard_PWM_ini3.TIM_OCPolarity=TIM_OCPolarity_High;//
    	//Hard_PWM_ini2.TIM_OCNPolarity = TIM_OCNPolarity_Low;//
    	Hard_PWM_ini3.TIM_OCIdleState = TIM_OCIdleState_Set;//
    	//Hard_PWM_ini2.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//
    	TIM_OC1Init(TIM1, &Hard_PWM_ini3);
    	TIM_OC2Init(TIM1, &Hard_PWM_ini3);
    	TIM_OC3Init(TIM1, &Hard_PWM_ini3);
    	TIM_Cmd(TIM1, ENABLE);
    	TIM_CtrlPWMOutputs(TIM1, ENABLE);
    	TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);
    	TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable);
    	TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Enable);
    	//-------------------------------------------------------------------------------
    	//-------------------------------------------------------------------------------

    	// Инициализация настроек для двигателя 1
    	//-------------------------------------------------------------------------------
    	//-------------------------------------------------------------------------------
    	// Верхний ключ  Hin1.1 Hin1.2 Hin1.3
    	//-------------------------------------------------------------------------------
    	// Настройка Таймера 8 для трехфазного ШИМ
    	TIM_TimeBaseInitTypeDef TIM_Time_Test_user;
    	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);//
    	TIM_Time_Test_user.TIM_Prescaler = 0;//
    	TIM_Time_Test_user.TIM_CounterMode = TIM_CounterMode_Up;//
    	TIM_Time_Test_user.TIM_Period=2000;//умножить на 2 потому что 32 бита
    	TIM_Time_Test_user.TIM_ClockDivision = TIM_CKD_DIV1;//
    	TIM_Time_Test_user.TIM_RepetitionCounter = 0;//
    	TIM_TimeBaseInit(TIM8, &TIM_Time_Test_user);
    	//-------------------------------------------------------------------------------
    	// Порты выхода ШИМ Hin1.1 Hin1.2 Hin1.3
    	GPIO_InitTypeDef GPIO_InitPWM2;//
    	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//
    	GPIO_InitPWM2.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 ;
    	GPIO_InitPWM2.GPIO_Mode = GPIO_Mode_AF; //
    	GPIO_InitPWM2.GPIO_OType = GPIO_OType_PP;//
    	GPIO_InitPWM2.GPIO_Speed = GPIO_Speed_100MHz;//
    	GPIO_InitPWM2.GPIO_PuPd = GPIO_PuPd_NOPULL;//
    	GPIO_Init(GPIOC, &GPIO_InitPWM2);//

    	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM8); // открыть порты шима
    	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM8);
    	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM8);
    	//-------------------------------------------------------------------------------
    	// Настройка ШИМ
    	TIM_OCInitTypeDef Hard_PWM_ini2;
    	Hard_PWM_ini2.TIM_OCMode=TIM_OCMode_PWM2;//
    	Hard_PWM_ini2.TIM_OutputState=TIM_OutputState_Enable;//  ВКЛ/выкл
    	//Hard_PWM_ini2.TIM_OutputNState = TIM_OutputNState_Disable;//
    	Hard_PWM_ini2.TIM_Pulse=400;// длинна пульса (пятая часть от периода)//
    	Hard_PWM_ini2.TIM_OCPolarity=TIM_OCPolarity_High;//
    	//Hard_PWM_ini2.TIM_OCNPolarity = TIM_OCNPolarity_Low;//
    	Hard_PWM_ini2.TIM_OCIdleState = TIM_OCIdleState_Set;//
    	//Hard_PWM_ini2.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//
    	TIM_OC1Init(TIM8, &Hard_PWM_ini2);
    	TIM_OC2Init(TIM8, &Hard_PWM_ini2);
    	TIM_OC3Init(TIM8, &Hard_PWM_ini2);
    	TIM_Cmd(TIM8, ENABLE);
    	TIM_CtrlPWMOutputs(TIM8, ENABLE);
    	TIM_CCxCmd(TIM8, TIM_Channel_1, TIM_CCx_Enable);
    	TIM_CCxCmd(TIM8, TIM_Channel_2, TIM_CCx_Enable);
    	TIM_CCxCmd(TIM8, TIM_Channel_3, TIM_CCx_Enable);
    	//-------------------------------------------------------------------------------
    	//-------------------------------------------------------------------------------
    }
}
