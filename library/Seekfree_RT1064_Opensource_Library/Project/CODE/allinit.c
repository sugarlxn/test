#include "headfile.h"
#include "allinit.h"




void allinit(void)
{
	
	//��������ʼ��
	gpio_init(BEEP, GPO, 0, GPIO_PIN_CONFIG);//��ʼ��

	
	//������ʼ��
	gpio_init(KEY1,GPI,0,GPIO_PIN_CONFIG);//��ʼ��
      gpio_init(KEY2,GPI,0,GPIO_PIN_CONFIG);
      gpio_init(KEY3,GPI,0,GPIO_PIN_CONFIG);
      gpio_init(KEY4,GPI,0,GPIO_PIN_CONFIG);
	
	
	//���뿪�س�ʼ��
	gpio_init(BM1,GPI,0,GPIO_PIN_CONFIG);//��ʼ��
      gpio_init(BM2,GPI,0,GPIO_PIN_CONFIG);
	
	
	//OLED��ʼ��
	oled_init();
	
	//�����ʼ��
      pwm_init(Motor_go_L, 13*1000, 0*TIMES*10);   //13kHz
      pwm_init(Motor_go_R, 13*1000, 0*TIMES*10);  //ռ�ձ�Ϊ0�����ֹͣ������mos�ܴ��ڽ�ֹ״̬
      pwm_init(Motor_return_L, 13*1000, 0*TIMES*10);
      pwm_init(Motor_return_R, 13*1000, 0*TIMES*10);
	
	//�����ʼ��
	pwm_init(STEER, 50, MidSteering*TIMES);   //50Hz
	
	
	//ģ�͵�г�ʼ��
	adc_init(ADC_1,INPUT1,ADC_8BIT);
      adc_init(ADC_1,INPUT2,ADC_8BIT);
      adc_init(ADC_1,INPUT3,ADC_8BIT);
      adc_init(ADC_1,INPUT4,ADC_8BIT);
      adc_init(ADC_1,INPUT5,ADC_8BIT);
      adc_init(ADC_1,INPUT6,ADC_8BIT);
      adc_init(ADC_1,INPUT7,ADC_8BIT);
	
	
	//���Ƶ�г�ʼ��
	adc_init(ADC_2,SteerADC1,ADC_12BIT);//���Ƶ�У�ADC�ӿ�
      adc_init(ADC_2,SteerADC2,ADC_12BIT);
      adc_init(ADC_2,SteerADC3,ADC_12BIT);
      adc_init(ADC_2,SteerADC4,ADC_12BIT);
	
	
	//��������ʼ��
	qtimer_quad_init(QTIMER_1,SPEEDA1,SPEEDB1);
      qtimer_quad_init(QTIMER_1,SPEEDA2,SPEEDB2);
	
	  
	
}

