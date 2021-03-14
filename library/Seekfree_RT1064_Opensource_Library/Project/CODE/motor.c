#include "headfile.h"
#include "motor.h"



//----------------------------------------------------------------------
//��Ҫȷ�����ת�����ռ�ձȺ���Сռ�ձ�
//����ʵ����Ҫ��д��ͬԪ���ٶ�λ
//ȷ����������ʱ�����ֵ�ĸ���
//----------------------------------------------------------------------
uint16 Motor_Ctrl_Left = 0,Motor_Ctrl_Right = 0;   //������ֺ�����PWM
uint16 Motor_Last_Left = 0,Motor_Last_Right = 0;   
int16 Motor_error_Left = 0,Motor_error_Right =0;   
uint16 MaxMotoring = 500,MinMotoring = 0;   //����������������PWMռ�ձ����ֵ��500
float diff_confficient2 = 8;   //�����ת��ʱ��ϵ��
uint16 speed_want = 0;   //��������ٶȵ������м�ֵ

//extern float eFuzzy[2]; 
//extern float ecFuzzy[2]; 
float speed_e = 0;  //�����������fe��ɾ���ֵ����ֵ��speed_fe
float speed_ec = 0; //�����������fec��ɾ���ֵ����ֵ��speed_fec
float speed_Fuzzy[7] = {0};
int16 speed_want_error = 0; //Ԥ�⽫Ҫ�ﵽ���ٶȵ�ƫ����٣�
uint8 speed_pe = 0;
uint8 speed_pec = 0;
float speed_eRule[7] = {0,20,40,70,90}; //������speed_fe���ķ�Χ                                                      
float speed_ec_Rule[7] = {20,16,13,6,0};  //���в��ٵķ�Χ�����ԽС������ԽС�����⣩
float speed_Rule[7] = {59,61,63,65,67}; //���Ԥ���ٶȣ�speed_forecast���ķ�Χ �����Խ���ٶ�ԽС�����⣬Ҫ��ȷ��ռ�ձȶ�Ӧ����ֵ��

int speed_rule[8][8] =    //Pֵģ�������
{  //ec 0 1 2 3 4   // e
      {4,4,4,3,2,5},//0          
      {4,3,3,2,1,5},//1       
      {4,3,2,1,0,5},//2     
      {3,2,1,1,0,5},//3         
      {2,1,0,0,0,5},//4           
      {5,5,5,5,5,5} //
};
int16 motor = 200;
uint16 steer = 0;
//uint8 speed_left = 0;
//uint8 speed_right = 0;

/*******************************************************************************
 *  @brief      Motor_Ctrl����
 *  @note       ������ƺ���
 *  @data       2020-3-8  
 ******************************************************************************/
void Motor_Ctrl()
{
    Motor_error_Left = (int16)(Motor_P*speed_e_left                            //P*��E��k��-E��k-1����
                             + Motor_I*speed_ec_left                           //I*��E��k��-E��k-1����
                             + Motor_D*(speed_ec_left - speed_last_ec_left));   //D*��E��k��-2E��k-1��+E��k-2����
    Motor_error_Right = (int16)(Motor_P*speed_e_right                               //P*��E��k��-E��k-1����
                              + Motor_I*speed_ec_right                              //I*��E��k��-E��k-1���� 
                              + Motor_D*(speed_ec_right - speed_last_ec_right));   //D*��E��k��-2E��k-1��+E��k-2����
    Motor_Last_Left = Motor_Ctrl_Left;   //�ϴε�����
    Motor_Last_Right = Motor_Ctrl_Right;
    Motor_Ctrl_Left = Motor_Ctrl_Left +  Motor_error_Left;   //PID��õı��ε�����
    Motor_Ctrl_Right = Motor_Ctrl_Right +  Motor_error_Right;
    if(Motor_Ctrl_Left>=MaxMotoring)   Motor_Ctrl_Left = MaxMotoring;   //������PWM�޷�
    if(Motor_Ctrl_Right>=MaxMotoring)   Motor_Ctrl_Right = MaxMotoring;
    if(Motor_Ctrl_Left<=MinMotoring)   Motor_Ctrl_Left = MinMotoring;   //�����СPWM�޷�
    if(Motor_Ctrl_Right<=MinMotoring)   Motor_Ctrl_Right = MinMotoring;
}

/*******************************************************************************
 *  @brief      speed_fuzzy_mem_cal_forecast����
 *  @note       speed_want�����ȼ��㺯��
 *  @data       2020-4-18
 ******************************************************************************/
void speed_fuzzy_mem_cal_forecast(void)//�����ȼ���
{
    speed_e = diangan_e;
    speed_ec = diangan_ec;
    
    if(speed_e < speed_eRule[0])
    {
        eFuzzy[0] = 1.0;
        speed_pe = 0;
    }
    else if(speed_e < speed_eRule[1])   //�����eλ������[x��y]�������e����x��������Ϊ��y-e��/��y-x��
    {
        eFuzzy[0] = (speed_eRule[1] - speed_e)/(speed_eRule[1] - speed_eRule[0]);
        speed_pe = 0;
    }
    else if(speed_e < speed_eRule[2])
    {
        eFuzzy[0] = (speed_eRule[2] - speed_e)/(speed_eRule[2] - speed_eRule[1]);
        speed_pe = 1;
    }
    else if(speed_e < speed_eRule[3])
    {
        eFuzzy[0] = (speed_eRule[3] - speed_e)/(speed_eRule[3] - speed_eRule[2]);
        speed_pe = 2;
    }
    else if(speed_e < speed_eRule[4])
    {
        eFuzzy[0] = (speed_eRule[4] - speed_e)/(speed_eRule[4] - speed_eRule[3]);
        speed_pe = 3;
    }
    else
    {
        eFuzzy[0] = 1.0;
        speed_pe = 4;
    }
    eFuzzy[1] = 1.0-eFuzzy[0];   //������������������������ǰ������ģ���Ӽ���������֮��Ϊ1

    if(speed_ec < speed_ec_Rule[0])
    {
        ecFuzzy[0] = 1.0;
        speed_pec = 0;
    }
    else if(speed_ec < speed_ec_Rule[1])
    {
        ecFuzzy[0] = (speed_ec_Rule[1] - speed_ec)/(speed_ec_Rule[1] - speed_ec_Rule[0]);
        speed_pec = 0;
    }
    else if(speed_ec < speed_ec_Rule[2])
    {
        ecFuzzy[0] = (speed_ec_Rule[2] - speed_ec)/(speed_ec_Rule[2] - speed_ec_Rule[1]);
        speed_pec = 1;
    }
    else if(speed_ec < speed_ec_Rule[3])
    {
        ecFuzzy[0] = (speed_ec_Rule[3] - speed_ec)/(speed_ec_Rule[3] - speed_ec_Rule[2]);
        speed_pec = 2;
    }
    else if(speed_ec < speed_ec_Rule[4])
    {
        ecFuzzy[0] = (speed_ec_Rule[4] - speed_ec)/(speed_ec_Rule[4] - speed_ec_Rule[3]);
        speed_pec = 3;
    }
    else
    {
        ecFuzzy[0] = 1.0;
        speed_pec = 4;
    }
    ecFuzzy[1] = 1.0-ecFuzzy[0];
}    

/*******************************************************************************
 *  @brief      speed_fuzzy_query_forecast����
 *  @note       ��ѯģ��������������ĸ�ռ��
                
 *  @warning    18/3/14 ����ο�binary-star��  v4.0
 ******************************************************************************/
void speed_fuzzy_query_forecast(void)//��ѯģ�������
{
    uint8 i,num = 0;
    for(i=0;i<7;i++)   //��������Ա��ۼ�
    {
        speed_Fuzzy[i] = 0;
    }
    /*��ѯKpģ�������*/
    num = speed_rule[speed_pe][speed_pec];
    speed_Fuzzy[num] += eFuzzy[0] * ecFuzzy[0];

    num = speed_rule[speed_pe+1][speed_pec];
    speed_Fuzzy[num] += eFuzzy[1] * ecFuzzy[0];
}

/*******************************************************************************
 *  @brief      speed_fuzzy_solve_forecast����
 *  @note       ���ķ���ģ��
                
 *  @warning    18/3/14 ����ο�binary-star�� v4.0
 ******************************************************************************/
void speed_fuzzy_solve_forecast(void)//��ģ���õ�pdֵ
{
    uint8 i;
    speed_want = 0; //���P��Dֵ�Ա��ۼ�
    speed_want_error = 0;
    /*������ķ���ģ��*/
    for(i = 0;i < 7; i++)
    {
        speed_want += (speed_Fuzzy[i] * speed_Rule[i]);
    }
}

/*******************************************************************************
 *  @brief      Speed_forecast����
 *  @note       ����ٶ��жϺ���
 *  @data       2020-4-14
 ******************************************************************************/
void Speed_forecast()
{
    if(diangan_e < 10 && diangan_e > -10)
    {
        speed_want_left = 65;
        speed_want_right = 65;
    }
    else if(diangan_e < -10 && diangan_e > -200)
    {
        speed_want_right = (uint16)(speed_want*100/(99-diff_confficient2*((SteerCtrl-714)/10)));
        speed_want_left = 2*speed_want-speed_want_right;
        if(speed_want_left>=40)   speed_want_left = 40;
        if(speed_want_right<=10)   speed_want_right = 10;
    }
    else if(diangan_e > 10 && diangan_e < 200)
    {
        speed_want_left = (uint16)(speed_want*100/(99-diff_confficient2*((714-SteerCtrl)/10)));
        speed_want_right = 2*speed_want-speed_want_left;
        if(speed_want_left>=40)   speed_want_left = 40;
        if(speed_want_right<=10)   speed_want_right = 10;
    }
}

/*******************************************************************************
 *  @brief      motor_l����
 *  @note       ��ʻ����
 *  @data       2020-6-14
 ******************************************************************************/
void motor_l()
{
    pwm_duty(DUOJI_Channel, SteerCtrl*TIMES);
    pwm_duty(Motor_Go_L, motor*TIMES*10);
    pwm_duty(Motor_Go_R, motor*TIMES*10); 
    if(uart_query(USART_8,&dat) == 1 && dat == 1)
    {
        motor = 0;
    }
    if((ADCNormal[0] < 0.05 && ADCNormal[1] < 0.05) && (ADCNormal[2] < 0.05 && ADCNormal[3] < 0.05))
    {
          pwm_duty(Motor_Go_L, 0*TIMES*10);
          pwm_duty(Motor_Go_R, 0*TIMES*10); 
    }
    if(stop_flag == 1)
    {
        motor = 0;
    }
    else if(diangan_e > 25)
    {
        motor = 270;
    }
    else if(diangan_e < -25)
    {
        motor = 270;
    }
    else if(diangan_e > 20)
    {
      
        motor = 320;
        
    }
    else if(diangan_e < -20)
    {
        motor = 320;
    }
    else if(diangan_e < 15)
    {
        motor = motor_speed;
        
    }
    else if(diangan_e > -15)
    {
        motor = motor_speed;
    }
    else
    {
        motor = 0;
    }
}

/*******************************************************************************
 *  @brief      Stop_car()����
 *  @note       ֹͣ����
 *  @data       2021-2-12(lxn_123)
 ******************************************************************************/

void Stop_car(void)
{
  stop_flag=1;
  motor=0;
}

