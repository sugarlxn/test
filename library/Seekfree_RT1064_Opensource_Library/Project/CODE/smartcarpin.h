#ifndef __smartcarpin_h
#define __smartcarpin_h

#include "headfile.h"

//蜂鸣器
#define BEEP D3

//舵机
#define STEER D26  //暂时找不到舵机的PWM通道，PWM通道

//电机
/*
一个电机两个PWM通道，两个PWM通道不能同时有占空比，正转通道有占空比，反转通道占空比为0，则正转；反之亦然
Motor_go_L(控制正转)---Motor_return_L(控制反转);(左轮)；Motor_go_R---Motor_return_R;(右轮)
*/
#define Motor_go_L PWM1_MODULE0_CHA_D12
#define Motor_go_R PWM1_MODULE3_CHB_D1
#define Motor_return_L PWM1_MODULE3_CHA_D0
#define Motor_return_R PWM2_MODULE3_CHA_D2

//编码器
#define SPEEDA1 D13//定时器通道
#define SPEEDB1 D14
#define SPEEDA2 D15
#define SPEEDB2 D16


//模型电感
#define INPUT1 C28//adc 通道(暂时找不到)
#define INPUT2 C26
#define INPUT3 C24
#define INPUT4 C22
#define INPUT5 C20
#define INPUT6 B28
#define INPUT7 B11
#define INPUT8 B10
#define INPUT9 B9
#define INPUT10 C31


//控制模块电感值ADC
#define SteerADC1 ADC2_CH9_B20
#define SteerADC2 ADC2_CH13_B24
#define SteerADC3 ADC2_CH14_B25
#define SteerADC4 ADC2_CH15_B26


//交互模块
//按键
#define KEY1 B23
#define KEY2 B22
#define KEY3 B25
#define KEY4 B24

//拨码开关
#define BM1 B27
#define BM2 B26


//OLED
#define  OLED_SCL_PIN	B20
#define  OLED_SDA_PIN	B21
#define  OLED_RST_PIN	B18
#define  OLED_DC_PIN	B19
#define  OLED_CS_PIN	B16


/*
D0     OLED_SCL_PIN   宏定义
D1     OLED_SDA_PIN   宏定义            
RES    OLED_RST_PIN   宏定义    
DC     OLED_DC_PIN    宏定义
CS     OLED_CS_PIN    宏定义

*/


//蓝牙
#define BLUE_TXD B31
#define BLUE_RXD B30







#endif

