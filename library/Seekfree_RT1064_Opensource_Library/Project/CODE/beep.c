//beep
#include "headfile.h"
#include "beep.h"

//蜂鸣器1秒
void beep_1(void)
{
	
	//外设驱动，首先延时300ms
      systick_delay_ms(300);
	
	gpio_set(BEEP, 1);
	systick_delay_ms(1000);//延时1000ms
	gpio_set(BEEP, 0);
	
	

}

//蜂鸣器3秒
void beep_3(void)
{
	//外设驱动，首先延时300ms
      systick_delay_ms(300);
	
	gpio_set(BEEP, 1);
	systick_delay_ms(3000);//延时3000ms
	gpio_set(BEEP, 0);
		
	
}
