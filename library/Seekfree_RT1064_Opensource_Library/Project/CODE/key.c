//key
#include "headfile.h"
#include "key.h"

#define key1press 1
#define key2press 1
#define key3press 1
#define key4press 1

//mode=1,支持连按；mode=0，不支持连按；
//keyflag 按键松开标志
//KEY 低电平有效
//返回按键状态keypress=1

uint8 key_scan(uint8 mode)
{
	static uint8 keyflag=1;
	
	if(mode)
	{
		keyflag=1;//支持连按
	}
	
	if(keyflag && (KEY1==0 || KEY2==0 || KEY3==0 || KEY4==0))
	{
		systick_delay_ms(10);//消抖
		
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
	
	return 0;//无按键按下
	
	
}

