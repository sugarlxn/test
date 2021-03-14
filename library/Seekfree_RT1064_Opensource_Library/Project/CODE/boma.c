#include "headfile.h"
#include "boma.h"


//BM:on=1;BM:off=0;

//·µ»Ø0x00,0x01,0x10,0x11;



uint8 bm_scan(void)
{
	uint8 bm1flag;
	uint8 bm2flag;
	
	static uint8 status=0x00;
	
	
	bm1flag=gpio_get(BM1);
	bm2flag=gpio_get(BM2);
	

	if(bm2flag==0 && bm1flag==1)
	{
		status=0x01;
	}
	else if(bm2flag==1 && bm1flag==0)
	{	
		status=0x10;
		
	}
	else if(bm2flag==1 && bm1flag==1)
	{
		status=0x11;
		
	}
	
	return status;
	
}

