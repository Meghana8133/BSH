#include <reg51.h>
#define Baud_rate 0xFA



void main(void);
void SerialInitialize(void);
void SendByteSerially(unsigned char ascii);
unsigned char ReceiveByteSerially(void);

void main(void)
{
    unsigned char serialdata;
    SerialInitialize();

    for(;;)
    {
        //serialdata = ReceiveByteSerially();
			SendByteSerially('H');
			SendByteSerially('E');
			SendByteSerially('L');
			SendByteSerially('L');
			SendByteSerially('O');
			SendByteSerially(' ');
			SendByteSerially('M');
			SendByteSerially('E');
			SendByteSerially('G');
			SendByteSerially('H');
			SendByteSerially('A');
			SendByteSerially('N');
			SendByteSerially('A');
			SendByteSerially(' ');
			SendByteSerially(' ');
    }

}



void SerialInitialize(void)
{
    TMOD = (( TMOD & 0x0F) | 0x20);
    SCON = 0x50;
    TH1 = Baud_rate;
    TR1 = 1;
}

void SendByteSerially(unsigned char serialdata)
{
    SBUF = serialdata;
    while(TI == 0);
    TI = 0;
   
}


unsigned char ReceiveByteSerially(void)
{
    while(RI == 0);
    RI=0;
    return SBUF;

}
