//key
#include "headfile.h"
#include "key.h"

#define key1press 1
#define key2press 1
#define key3press 1
#define key4press 1

//mode=1,֧��������mode=0����֧��������
//keyflag �����ɿ���־
//KEY �͵�ƽ��Ч
//���ذ���״̬keypress=1

uint8 key_scan(uint8 mode)
{
	static uint8 keyflag=1;
	
	if(mode)
	{
		keyflag=1;//֧������
	}
	
	if(keyflag && (KEY1==0 || KEY2==0 || KEY3==0 || KEY4==0))
	{
		systick_delay_ms(10);//����
		
		keyflag=0;
		
		if(KEY1==0)
		{
			return key1press;
		}
		else if(KEY2==0)
		{
			return key2press;
			
		}
		else if(KEY3==0)
		{
			return key3press;

		}
		else if(KEY4==0)
		{
			return key4press;
			
		}

	}
	
	else if(KEY1==1 && KEY2==1 && KEY3==1 && KEY4==1)
	{
		keyflag=0;
		
	}
	
	return 0;//�ް�������
	
	
}

