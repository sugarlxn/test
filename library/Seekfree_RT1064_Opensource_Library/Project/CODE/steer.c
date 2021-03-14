#include "headfile.h"
#include "steer.h"



//舵机正中值需要测定

int16 MidSteering = 714;   //舵机正中PWM值(经过调试待定)
int16 SteerCtrl = 714;  //舵机控制占空比
int16 SteerLastCtrl = 714; //舵机控制上一次占空比
int16 Steererror = 0;//舵机控制误差



//舵机左满偏值和右满偏值需要测定(在舵机安装到小车的情况下，调试舵机可摆动范围)
int16 MinSteering = 639,MaxSteering = 789;   //舵机保护左满偏/舵机右满偏(用于满偏保护)

/*******************************************************************************
 *  @brief       Steer_Ctrl函数
 *  @note       舵机控制函数
 *  @data       2020-3-7 
 ******************************************************************************/
void Steer_Ctrl()   
{
    static uint8 number;
    if(number==0)  diangan_last_e=diangan_e;
    number++;
    if(number == 5)
    {
        diangan_ec = diangan_e - diangan_last_e;
        number = 0;
    }
    if(Steer_P_diangan < 0)   Steer_P_diangan = -Steer_P_diangan;
    Steererror = (int16)(Steer_P_diangan*diangan_e     //P*（E（k）-E（k-1））
                        + Steer_D_diangan*diangan_ec);   //D*（E（k）-2E（k-1）+E（k-2））
    SteerLastCtrl = SteerCtrl;
    SteerCtrl = MidSteering + (Steererror / 50);   //误差转化为PWM
    if(SteerCtrl<=MinSteering)   SteerCtrl = MinSteering;   //左满偏/右满偏保护
    if(SteerCtrl>=MaxSteering)   SteerCtrl = MaxSteering;
}







