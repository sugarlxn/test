#include "headfile.h"
#include "allinit.h"




void allinit(void)
{
	
	//蜂鸣器初始化
	gpio_init(BEEP, GPO, 0, GPIO_PIN_CONFIG);//初始化

	
	//按键初始化
	gpio_init(KEY1,GPI,0,GPIO_PIN_CONFIG);//初始化
      gpio_init(KEY2,GPI,0,GPIO_PIN_CONFIG);
      gpio_init(KEY3,GPI,0,GPIO_PIN_CONFIG);
      gpio_init(KEY4,GPI,0,GPIO_PIN_CONFIG);
	
	
	//拨码开关初始化
	gpio_init(BM1,GPI,0,GPIO_PIN_CONFIG);//初始化
      gpio_init(BM2,GPI,0,GPIO_PIN_CONFIG);
	
	
	//OLED初始化
	oled_init();
	
	//电机初始化
      pwm_init(Motor_go_L, 13*1000, 0*TIMES*10);   //13kHz
      pwm_init(Motor_go_R, 13*1000, 0*TIMES*10);  //占空比为0，电机停止，所有mos管处于截止状态
      pwm_init(Motor_return_L, 13*1000, 0*TIMES*10);
      pwm_init(Motor_return_R, 13*1000, 0*TIMES*10);
	
	//舵机初始化
	pwm_init(STEER, 50, MidSteering*TIMES);   //50Hz
	
	
	//模型电感初始化
	adc_init(ADC_1,INPUT1,ADC_8BIT);
      adc_init(ADC_1,INPUT2,ADC_8BIT);
      adc_init(ADC_1,INPUT3,ADC_8BIT);
      adc_init(ADC_1,INPUT4,ADC_8BIT);
      adc_init(ADC_1,INPUT5,ADC_8BIT);
      adc_init(ADC_1,INPUT6,ADC_8BIT);
      adc_init(ADC_1,INPUT7,ADC_8BIT);
	
	
	//控制电感初始化
	adc_init(ADC_2,SteerADC1,ADC_12BIT);//控制电感，ADC接口
      adc_init(ADC_2,SteerADC2,ADC_12BIT);
      adc_init(ADC_2,SteerADC3,ADC_12BIT);
      adc_init(ADC_2,SteerADC4,ADC_12BIT);
	
	
	//编码器初始化
	qtimer_quad_init(QTIMER_1,SPEEDA1,SPEEDB1);
      qtimer_quad_init(QTIMER_1,SPEEDA2,SPEEDB2);
	
	  
	
}

