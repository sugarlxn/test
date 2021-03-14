#ifndef __smartcarpin_h
#define __smartcarpin_h

#include "headfile.h"

//������
#define BEEP D3

//���
#define STEER D26  //��ʱ�Ҳ��������PWMͨ����PWMͨ��

//���
/*
һ���������PWMͨ��������PWMͨ������ͬʱ��ռ�ձȣ���תͨ����ռ�ձȣ���תͨ��ռ�ձ�Ϊ0������ת����֮��Ȼ
Motor_go_L(������ת)---Motor_return_L(���Ʒ�ת);(����)��Motor_go_R---Motor_return_R;(����)
*/
#define Motor_go_L PWM1_MODULE0_CHA_D12
#define Motor_go_R PWM1_MODULE3_CHB_D1
#define Motor_return_L PWM1_MODULE3_CHA_D0
#define Motor_return_R PWM2_MODULE3_CHA_D2

//������
#define SPEEDA1 D13//��ʱ��ͨ��
#define SPEEDB1 D14
#define SPEEDA2 D15
#define SPEEDB2 D16


//ģ�͵��
#define INPUT1 C28//adc ͨ��(��ʱ�Ҳ���)
#define INPUT2 C26
#define INPUT3 C24
#define INPUT4 C22
#define INPUT5 C20
#define INPUT6 B28
#define INPUT7 B11
#define INPUT8 B10
#define INPUT9 B9
#define INPUT10 C31


//����ģ����ֵADC
#define SteerADC1 ADC2_CH9_B20
#define SteerADC2 ADC2_CH13_B24
#define SteerADC3 ADC2_CH14_B25
#define SteerADC4 ADC2_CH15_B26


//����ģ��
//����
#define KEY1 B23
#define KEY2 B22
#define KEY3 B25
#define KEY4 B24

//���뿪��
#define BM1 B27
#define BM2 B26


//OLED
#define  OLED_SCL_PIN	B20
#define  OLED_SDA_PIN	B21
#define  OLED_RST_PIN	B18
#define  OLED_DC_PIN	B19
#define  OLED_CS_PIN	B16


/*
D0     OLED_SCL_PIN   �궨��
D1     OLED_SDA_PIN   �궨��            
RES    OLED_RST_PIN   �궨��    
DC     OLED_DC_PIN    �궨��
CS     OLED_CS_PIN    �궨��

*/


//����
#define BLUE_TXD B31
#define BLUE_RXD B30







#endif

