#ifndef __STEER_H
#define __STEER_H

#include "headfile.h"
#include "steer.h"


extern int16 MidSteering;   //�������PWMֵ
extern int16 SteerCtrl,SteerLastCtrl;   //���ռ�ձ�
extern int16 Steererror;
extern int16 MaxSteering,MinSteering;   //�����������ƫ/�������ƫ

void Steer_Ctrl();   //���ת��PID����








#endif

