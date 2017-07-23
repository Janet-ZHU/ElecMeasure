/*
 * LCD.h
 *
 *  Created on: 2017��7��21��
 *      Author: zhujingjie
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#include "fsl_debug_console.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_common.h"

//���ڲ���printf����
unsigned char string1[] = {"Avoltage:220.1V\r\n"};//����2���ֽ� ��ĸ�� /n �������1���ֽ� A���ѹ��220.1V\r\n ��ռ17���ֽ� 0~8 9~13 9 10 11 .13
unsigned char string2[] = {"Bvoltage:220.3V\r\n"};
unsigned char string3[] = {"Cvoltage:219.8V\r\n"};
unsigned char string4[] = {"Acurrent:10.11A\r\n"};//����2���ֽ� ��ĸ�� /n �������1���ֽ� A���ѹ��220.1V\r\n ��ռ17���ֽ� 0~8 9~13 9 10 .12  13
unsigned char string5[] = {"Bcurrent:10.22A\r\n"};
unsigned char string6[] = {"Ccurrent:10.33A\r\n"};
unsigned int v1=2211,v2=2222,v3=2133;
unsigned int i1=1111,i2=1122,i3=1133;

//v1Ϊ��õ����ݣ�ת��Ϊ�ַ������� ���ڴ���


void show_figure4(unsigned int x )
{
	unsigned int a[4] = { 0 };

	a[0] = x%10+0x30;
	a[1] = x/10%10+0x30;
	a[2] = x/100%10+0x30;
	a[3] = x/1000+0x30;   //ǧλ

	PUTCHAR(0xff);PUTCHAR(0xff); PUTCHAR(0xff);

	PRINTF("t7.txt=");
	PUTCHAR(0x22);
	PUTCHAR(a[3]);PUTCHAR(a[2]);PUTCHAR(a[1]);PUTCHAR('.');PUTCHAR(a[0]);PUTCHAR('V');
	PUTCHAR(0x22);

	PUTCHAR(0xff);PUTCHAR(0xff); PUTCHAR(0xff);

}

void show_curve(unsigned char x )
{
	unsigned int a[3] = { 0 };
	a[0] = x%10+0x30;
	a[1] = x/10%10+0x30;
	a[2] = x/100+0x30;


	PUTCHAR(0xff);PUTCHAR(0xff); PUTCHAR(0xff);

	PRINTF("add 1,0,");
	PUTCHAR(a[2]);PUTCHAR(a[1]);PUTCHAR(a[0]);

	PUTCHAR(0xff);PUTCHAR(0xff); PUTCHAR(0xff);

}

#endif /* LCD_LCD_H_ */
