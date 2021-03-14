#ifndef __STEER_H
#define __STEER_H

#include "headfile.h"
#include "steer.h"


extern int16 MidSteering;   //舵机正中PWM值
extern int16 SteerCtrl,SteerLastCtrl;   //舵机占空比
extern int16 Steererror;
extern int16 MaxSteering,MinSteering;   //舵机保护左满偏/舵机右满偏

void Steer_Ctrl();   //舵机转角PID控制








#endif

