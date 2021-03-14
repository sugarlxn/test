#include "headfile.h"
#include "steer.h"



//�������ֵ��Ҫ�ⶨ

int16 MidSteering = 714;   //�������PWMֵ(�������Դ���)
int16 SteerCtrl = 714;  //�������ռ�ձ�
int16 SteerLastCtrl = 714; //���������һ��ռ�ձ�
int16 Steererror = 0;//����������



//�������ƫֵ������ƫֵ��Ҫ�ⶨ(�ڶ����װ��С��������£����Զ���ɰڶ���Χ)
int16 MinSteering = 639,MaxSteering = 789;   //�����������ƫ/�������ƫ(������ƫ����)

/*******************************************************************************
 *  @brief       Steer_Ctrl����
 *  @note       ������ƺ���
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
    Steererror = (int16)(Steer_P_diangan*diangan_e     //P*��E��k��-E��k-1����
                        + Steer_D_diangan*diangan_ec);   //D*��E��k��-2E��k-1��+E��k-2����
    SteerLastCtrl = SteerCtrl;
    SteerCtrl = MidSteering + (Steererror / 50);   //���ת��ΪPWM
    if(SteerCtrl<=MinSteering)   SteerCtrl = MinSteering;   //����ƫ/����ƫ����
    if(SteerCtrl>=MaxSteering)   SteerCtrl = MaxSteering;
}







