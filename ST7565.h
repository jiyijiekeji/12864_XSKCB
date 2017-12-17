#include<reg51.h>
#include<intrins.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

sbit Lcd_RS=P2^6;
sbit Lcd_RD=P2^5;
sbit Lcd_RW=P2^7;
sbit Lcd_CS=P3^2;
sbit Lcd_REST=P3^3;

void WriteCmd(uchar cmd);
void WriteData(uchar dat);
void LcdInit();
void LcdClearScreen();

void WriteCmd(uchar cmd)
{
	Lcd_CS=0;
	Lcd_RD=1;
	Lcd_RS=0;
	Lcd_RW=0;
	_nop_();
	_nop_();
	P0=cmd;
	_nop_();
	_nop_();
	Lcd_RW=1;
}
void WriteData(uchar dat)
{
	Lcd_CS=0;
	Lcd_RD=1;
	Lcd_RS=1;
	Lcd_RW=0;
	_nop_();
	_nop_();
	P0=dat;
	_nop_();
	_nop_();
	Lcd_RW=1;
}
void LcdInit()
{
	uchar i;
	Lcd_REST=0;
	for(i=0;i<100;i++);
   	Lcd_CS=0;
	Lcd_REST=1;
	for(i=0;i<100;i++);
	WriteCmd(0xE2);
	for(i=0;i<100;i++);
	WriteCmd(0xA1);
	WriteCmd(0xC8);
	WriteCmd(0xA6);
	WriteCmd(0xA4);
	WriteCmd(0xA2);
	WriteCmd(0xF8);
	WriteCmd(0x01);
	WriteCmd(0x81);
	WriteCmd(0x23);
	WriteCmd(0x25);
	WriteCmd(0x2F);
	for(i=0;i<100;i++);
	WriteCmd(0x40);
	WriteCmd(0xAF);
	for(i=0;i<100;i++);
}

void LcdClearScreen()
{
	uchar i,jj;
	for(i=0;i<8;i++)
	{
		WriteCmd(0xb0+i);
		WriteCmd(0x10);
		WriteCmd(0x04);
		for(jj=0;jj<128;jj++)
		{
			WriteData(0x00);
		}
	}
}
