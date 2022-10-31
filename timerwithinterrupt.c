#include <REG52.h>

#define TIMER0_VALUE_25msec 0xA5FF
#define TIMER0_H (TIMER0_VALUE_25msec &0xA5FF)
#define TIMER0_L (TIMER0_VALUE_25msec &0xA5FF)



int i;
sbit led0 = P1^0;

void timer0_interrupt() interrupt 1
{
	TH0=TIMER0_H;
	TL0=TIMER0_L;
	if(i==100)
	{
		led0=~led0;
		i=0;
	}
	else 
		i++;
}

void main()
{
  TMOD=0x01;
	TH0=TIMER0_H;
	TL0=TIMER0_L;
	TH0=0xA5;
	TL0=0xFF;
	EA=1;
	ET0=1;
 	TR0=1;
  while(1);
}


