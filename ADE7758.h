/*
 * ADE7758.h
 *
 *  Created on: 2017年7月19日
 *      Author: zhujingjie
 */

/*
 * Copyright (c) 2017, Janet ZHU.
 * All rights reserved.
 */

#ifndef ADE7758_H_
#define ADE7758_H_

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include  "LCD.h"
#include "fsl_common.h"
#include "fsl_port.h"

//在pin_mux.c中开启端口使能，初始化端口
#define CS_0   GPIO_WritePinOutput(GPIOB, 18U, 0)//CS
#define CS_1   GPIO_WritePinOutput(GPIOB, 18U, 1)
#define DIN_0   GPIO_WritePinOutput(GPIOB, 2U, 0)//DIN
#define DIN_1  GPIO_WritePinOutput(GPIOB, 2U, 1)
#define CLK_0  GPIO_WritePinOutput(GPIOB, 3U, 0)//CLK
#define CLK_1  GPIO_WritePinOutput(GPIOB, 3U, 1)

#define DOUT    GPIO_ReadPinInput(GPIOB,1U)  //DOUT

#define 	    Addr_AWATTHR	0x01  //A相有功电能
#define 	    Addr_BWATTHR	0x02  //B相
#define 	    Addr_CWATTHR	0x03  //C相
#define	        Addr_AVARHR		0x04  //A相无功电能
#define	        Addr_BVARHR		0x05  //B相
#define  	    Addr_CVARHR		0x06  //C相
#define  	    Addr_AVAHR	    0x07  //A相视在电能
#define  	    Addr_BVAHR		0x08  //B相
#define  	    Addr_CVAHR		0x09  //C相
#define  	    Addr_AIRMS		0x0a  //A相电流有效值
#define  	    Addr_BIRMS		0x0b  //B相
#define  	    Addr_CIRMS		0x0c  //C相
#define  	    Addr_AVRMS		0x0d  //A相电压有效值
#define  	    Addr_BVRMS		0x0e  //B相
#define  	    Addr_CVRMS		0x0f  //C相
#define         Addr_FREQ		0x10
#define         Addr_TEMP		0x11  //片内温度
#define         Addr_WFORM		0x12  //波形寄存器   ，与WAVMODE相关
#define         Addr_OPMODE		0x13  //运行模式控制寄存器   都设定为0x00即可
#define         Addr_MMODE		0x14  //测量模式控制寄存器   只选择A B C三相
#define         Addr_WAVMODE    0x15  //波形模式选择寄存器
#define         Addr_COMPMODE	0x16  //计算方式             //设置输出脉冲累计的是单相还是三相
#define         Addr_LCYCMODE	0x17
#define         Addr_MASK		0x18
#define         Addr_STATUS		0x19
#define         Addr_RSTATUS	0x1a
#define         Addr_ZXTOUT		0x1b
#define         Addr_LINCYC		0x1c
#define         Addr_SAGCYC		0x1d
#define         Addr_SAGLVL		0x1e
#define         Addr_VPINTLVL	0x1f
#define         Addr_IPINTLVL	0x20
#define         Addr_VPEAK		0x21
#define         Addr_IPEAK		0x22
#define         Addr_GAIN		0x23
#define         Addr_AVRMSGAIN	0x24 //A相电压增益    线电压：两相之间    =1.732*相电压
#define         Addr_BVRMSGAIN	0x25 //B相电压增益    相电压：相  地  之间
#define         Addr_CVRMSGAIN	0x26 //C相电压增益
#define         Addr_AIGAIN		0x27 //A线电流增益    在星形接法中线电流=相电流
#define         Addr_BIGAIN		0x28 //B线电流增益    在三角形接法中线电流=1.730*相电流
#define         Addr_CIGAIN		0x29 //C线电流增益
#define         Addr_AWG		0x2a //A相有功功率增益寄存器
#define         Addr_BWG		0x2b //B相
#define         Addr_CWG		0x2c //C相
#define         Addr_AVARG		0x2d //A相无功功率增益寄存器
#define         Addr_BVARG		0x2e //B相
#define         Addr_CVARG		0x2f //C相
#define         Addr_AVAG		0x30  //A相视在功率增益寄存器
#define         Addr_BVAG		0x31  //B相
#define         Addr_CVAG		0x32  //C相
#define         Addr_AVRMSOS	0x33  //A相电压偏移量的补偿寄存器
#define         Addr_BVRMSOS	0x34  //B相
#define         Addr_CVRMSOS	0x35  //C相
#define         Addr_AIRMSOS	0x36  //A相电流偏移量的补偿寄存器
#define         Addr_BIRMSOS	0x37  //B相
#define         Addr_CIRMSOS	0x38  //C相
#define         Addr_AWATTOS	0x39  //A相有功功率偏移量的补偿寄存器
#define         Addr_BWATTOS	0x3a  //B相
#define         Addr_CWATTOS	0x3b  //C相
#define         Addr_AVAROS		0x3c  //A相无功功率偏移量的补偿寄存器
#define         Addr_BVAROS		0x3d  //B相
#define         Addr_CVAROS		0x3e  //C相
#define         Addr_APHCAL		0x3f  //A相相位寄存器
#define         Addr_BPHCAL		0x40  //B相相位寄存器
#define         Addr_CPHCAL		0x41  //C相相位寄存器
#define         Addr_WDIV		0x42  //有功电能寄存器除法位
#define         Addr_VARDIV		0x43  //无功电能寄存器除法位
#define         Addr_VADIV		0x44  //视在电能寄存器除法位
#define         Addr_APCFNUM	0x45
#define         Addr_APCFDEN	0x46
#define         Addr_VARCFNUM	0x47
#define         Addr_VARCFDEN	0x48

#define         Addr_CHKSUM		0x7e
#define         Addr_VERSION	0x7f



unsigned int p_v[3]={100,100,199};
unsigned long int A_V=220,B_V=0x33U,C_V=219;

unsigned char show1 =0x1CU;
unsigned char show2 =0x78U;
unsigned char current_unbalance = 100;
unsigned char voltage_unbalance = 100;

//模拟三相不平衡度
unsigned char current_unbalanceSimulate[256] = {
		0x00,0x03,0x06,0x09,0x0c,0x0f,0x12,0x15,0x19,0x1c,0x1f,0x22,0x25,0x28,0x2b,0x2e,
		0x31,0x34,0x38,0x3b,0x3e,0x41,0x44,0x47,0x4a,0x4d,0x50,0x53,0x56,0x59,0x5c,0x5f,
		0x61,0x64,0x67,0x6a,0x6d,0x70,0x73,0x75,0x78,0x7b,0x7e,0x80,0x83,0x86,0x88,0x8b,
		0x8e,0x90,0x93,0x95,0x98,0x9a,0x9d,0x9f,0xa2,0xa4,0xa7,0xa9,0xab,0xae,0xb0,0xb2,
		0xb4,0xb7,0xb9,0xbb,0xbd,0xbf,0xc1,0xc3,0xc5,0xc7,0xc9,0xcb,0xcd,0xcf,0xd1,0xd3,
		0xd4,0xd6,0xd8,0xd9,0xdb,0xdd,0xde,0xe0,0xe1,0xe3,0xe4,0xe5,0xe7,0xe8,0xe9,0xeb,
		0xec,0xed,0xee,0xef,0xf0,0xf2,0xf3,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xf9,0xfa,
		0xfb,0xfb,0xfc,0xfc,0xfd,0xfd,0xfe,0xfe,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xfe,0xfe,0xfd,0xfd,0xfc,0xfc,0xfb,
		0xfb,0xfa,0xf9,0xf9,0xf8,0xf7,0xf6,0xf5,0xf5,0xf4,0xf3,0xf2,0xf1,0xf0,0xee,0xed,
		0xec,0xeb,0xea,0xe8,0xe7,0xe6,0xe4,0xe3,0xe1,0xe0,0xde,0xdd,0xdb,0xda,0xd8,0xd6,
		0xd5,0xd3,0xd1,0xcf,0xcd,0xcb,0xc9,0xc8,0xc6,0xc4,0xc2,0xbf,0xbd,0xbb,0xb9,0xb7,
		0xb5,0xb3,0xb0,0xae,0xac,0xa9,0xa7,0xa5,0xa2,0xa0,0x9d,0x9b,0x98,0x96,0x93,0x91,
		0x8e,0x8b,0x89,0x86,0x83,0x81,0x7e,0x7b,0x78,0x76,0x73,0x70,0x6d,0x6a,0x68,0x65,
		0x62,0x5f,0x5c,0x59,0x56,0x53,0x50,0x4d,0x4a,0x47,0x44,0x41,0x3e,0x3b,0x38,0x35,
		0x32,0x2f,0x2c,0x29,0x25,0x22,0x1f,0x1c,0x19,0x16,0x13,0x10,0x0c,0x09,0x06,0x03
};

void delay(unsigned int t1) //延时
{   unsigned int i,j;
    for(i=0;i<t1;i++);
    {
    	for(j=0;j<200;j++);
    }
}
void write_byte(unsigned char indata)
{
  unsigned char x,c;
    x=indata;
    CLK_0;//P2OUT &=~CLK;   //P2.1
    for(c=0;c<8;c++)
      {
       if(x & 0x80) {DIN_1;}
             else {DIN_0;}
    CLK_1;            //下降沿写数据
    CLK_0;
    x<<=1;
        }
}
unsigned char read_byte()
{
 unsigned char data=0;
 //CS_0; 在read8中有
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=128;}  //上升沿读数据
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=64;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=32;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=16;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=8;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=4;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=2;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=1;}
 //CS_1;
 return (data);
}

void write8_ADE7758(unsigned char addr,unsigned char data)
{
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	//addr=addr|0x80;
	addr+=0x80;      //向寄存器中写时，要将地址值加上0x80
	write_byte(addr);//先写入地址
	delay(5);
	write_byte(data);//再写入数据
	CLK_0;
    CS_1;
}

void write16_ADE7758(unsigned char addr,unsigned int data)
{
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	addr=addr|0x80;     //向寄存器中写时，要将地址值加上0x80
	write_byte(addr);//先写入地址
	delay(5);
	write_byte(data/256);//再写入数据高八位
	delay(5);
	write_byte(data%256);//再写入数据低八位
	CLK_0;
	CS_1;
}
void write24_ADE7758(unsigned char addr,unsigned long int data)
{
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	addr=addr|0x80;     //向寄存器中写时，要将地址值加上0x80
	write_byte(addr);//先写入地址
	delay(5);
	write_byte(data/65536);//再写入数据高八位
	delay(5);
	write_byte((data%65536)/256);//再写入数据中八位
	delay(5);
	write_byte((data%65536)%256);//再写入数据低八位
	CLK_0;
	CS_1;
}
//***************************************************************
unsigned char read8_ADE7758(unsigned char addr)
{
	unsigned char data;
	CLK_0;
	CS_0;
	addr=addr&0x7F;//读取地址首位为0
	write_byte(addr);//先写入地址
	delay(5);
	data=read_byte();//读出数据
	CLK_0;
	CS_1;
	return(data);
}

unsigned int read16_ADE7758(unsigned char addr)
{
	unsigned char data1,data2;
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	write_byte(addr);//先写入地址
	delay(5);
	data1=read_byte();//读出高八位
	delay(5);
	data2=read_byte();//读出低八位
	CLK_0;
	CS_1;
	return(data1*256+data2);
}
unsigned long int read24_ADE7758(unsigned char addr)
{
	unsigned char data1,data2,data3;
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	write_byte(addr);//先写入地址
	delay(5);
	data1=read_byte();//读出高八位
	delay(5);
	data2=read_byte();//读出中八位
	delay(5);
	data3=read_byte();//读出低八位
	CLK_0;
	CS_1;
	return((unsigned long int)(data1*65536+data2*256+data3));
}

void ADE7758_Init()
{
    /* Initialize LPUART0 pins below */
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortB);

    port_pin_config_t config;
    config.pullSelect = kPORT_PullUp;
    config.mux = kPORT_MuxAsGpio;
    PORT_SetPinConfig(PORTC, 4U, &config); //PTC4设置为上拉

   //设置上拉
    PORT_SetPinConfig(PORTB, 18U, &config); //PTC19   //由于杜邦线的接口不匹配，造成接触不良，使得调试遇阻
    PORT_SetPinConfig(PORTB, 2U, &config); //PTC16   //由此得到一个教训，以后必须选用合适的接插口进行设计
    PORT_SetPinConfig(PORTB, 3U,  &config); //PTC3    //必须买合格的产品
    PORT_SetPinConfig(PORTB, 1U,  &config); //PTC2  //最后发现应当是9V电池电量不足。。。

    //设为I/O
     PORT_SetPinMux(PORTB, 18U, kPORT_MuxAsGpio); //CS
     PORT_SetPinMux(PORTB, 2U, kPORT_MuxAsGpio); //DOUT SO --  MI
     PORT_SetPinMux(PORTB, 3U, kPORT_MuxAsGpio);  //CLK
     PORT_SetPinMux(PORTB, 1U, kPORT_MuxAsGpio);  //DIN  SI --  MO



	 /* Define the init structure for the ADE7758 controller's OUT and IN pin (for MCU) */
	    gpio_pin_config_t ADE7758_config_OUT =  { kGPIO_DigitalOutput, 1, };
	    gpio_pin_config_t ADE7758_config_IN =   { kGPIO_DigitalInput,  0, };

	 /* Init output ADE7758 GPIO. */
	    GPIO_PinInit(GPIOB, 18U, &ADE7758_config_OUT);
	    GPIO_PinInit(GPIOB, 2U,  &ADE7758_config_OUT);
	    GPIO_PinInit(GPIOB, 3U,  &ADE7758_config_OUT);
	    GPIO_PinInit(GPIOB, 1U,  &ADE7758_config_IN);

	  //write8_ADE7758(Addr_OPMODE,0x40);//器件复位
	  //Software Chip Reset. A data transfer to the ADE7758 should not take place for at least 166 μs after a software reset.
       write8_ADE7758(Addr_OPMODE,0x00);//使能输出脉冲
       write24_ADE7758(Addr_MASK,0x000007);//置位低三位  将标志写入中断寄存器 ,允许能量寄存器容量超出一半时产生中断
}
//************************************************ **************************
void  V_RMS()          //三相四线  相电压
{

   A_V=read24_ADE7758(Addr_AVRMS);
   B_V=read8_ADE7758(Addr_COMPMODE);
   C_V=read8_ADE7758(Addr_LCYCMODE);
   p_v[0]=(unsigned int)(0.5*A_V*1000/279701);//0.5V   50HZ 对应的是1678210
   //p_v[1]=B_V; p_v[2]=C_V;
  // p_v[1]=(unsigned int)(0.5*B_V*1000/1678210);
  // p_v[2]=(unsigned int)(0.5*C_V*1000/1678210);
   show_figure4(p_v[0]);
   //voltage_unbalance = max(p_v[1], p_v[2],p_v[3]) - min(p_v[1], p_v[2],p_v[3])/max(p_v[1], p_v[2],p_v[3]) ;
   //show_curve(voltage_unbalance);
}

#endif /* ADE7758_H_*/

