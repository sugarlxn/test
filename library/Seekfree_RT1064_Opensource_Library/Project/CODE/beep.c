//beep
#include "headfile.h"
#include "beep.h"

//������1��
void beep_1(void)
{
	
	//����������������ʱ300ms
      systick_delay_ms(300);
	
	gpio_set(BEEP, 1);
	systick_delay_ms(1000);//��ʱ1000ms
	gpio_set(BEEP, 0);
	
	

}

//������3��
void beep_3(void)
{
	//����������������ʱ300ms
      systick_delay_ms(300);
	
	gpio_set(BEEP, 1);
	systick_delay_ms(3000);//��ʱ3000ms
	gpio_set(BEEP, 0);
		
	
}
