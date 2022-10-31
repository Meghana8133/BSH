#include <REG52.h>

#define TIMER0_VALUE_25msec 0xA5FF
//#define TIMER1_VALUE_3sec 0xA5FF
#define TIMER0_H (TIMER0_VALUE_25msec &0xA5FF)
#define TIMER0_L (TIMER0_VALUE_25msec &0xA5FF)
//#define TIMER0_H (TIMER1_VALUE_3sec &0xA5FF)
//#define TIMER0_L (TIMER1_VALUE_3sec &0xA5FF)

int i;
sbit led0 = P1^0;

void timer0_interrupt() interrupt 1
{
	TH0=0xFF;
	TL0=0xFF;
	led0=~led0;
}




void main()
{
  TMOD=0x05;
	TH0=0xFF;
	TL0=0xFF;
	EA=1;
	ET0=1;
 	TR0=1;
  while(1);
	
		
}


