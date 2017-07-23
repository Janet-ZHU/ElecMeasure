/* Copyright (c) 2015, Freescale Semiconductor, Inc.*/

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/*******************************************************************************
 * Code
 ******************************************************************************/

void BOARD_InitPins(void)
{
    /* Initialize LPUART0 pins below */
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortC);
    CLOCK_EnableClock(kCLOCK_PortA);
    CLOCK_EnableClock(kCLOCK_PortB);

    port_pin_config_t config0;
    config0.pullSelect = kPORT_PullUp;
    config0.mux = kPORT_MuxAlt4;
    PORT_SetPinConfig(PORTC, 6U, &config0);
    PORT_SetPinConfig(PORTC, 7U, &config0);

    /* Affects PORTC_PCR4 register *///����
    port_pin_config_t config;
    config.pullSelect = kPORT_PullUp;
    config.mux = kPORT_MuxAsGpio;
    PORT_SetPinConfig(PORTC, 4U, &config); //PTC4����Ϊ����

   // port_pin_config_t config1;
    //    config1.pullSelect = kPORT_PullDisable;
     //   config1.mux = kPORT_MuxAsGpio;

    /* LED PIN_MUX Configuration */   	//���
     PORT_SetPinMux(PORTC, 1U, kPORT_MuxAsGpio);
     PORT_SetPinMux(PORTA, 19U, kPORT_MuxAsGpio);
     PORT_SetPinMux(PORTB, 0U, kPORT_MuxAsGpio);

   //��������
    PORT_SetPinConfig(PORTB, 18U, &config); //PTC19   //���ڶŰ��ߵĽӿڲ�ƥ�䣬��ɽӴ�������ʹ�õ�������
    PORT_SetPinConfig(PORTB, 2U, &config); //PTC16   //�ɴ˵õ�һ����ѵ���Ժ����ѡ�ú��ʵĽӲ�ڽ������
    PORT_SetPinConfig(PORTB, 3U,  &config); //PTC3    //������ϸ�Ĳ�Ʒ
    PORT_SetPinConfig(PORTB, 1U,  &config); //PTC2  //�����Ӧ����9V��ص������㡣����

    //��ΪI/O
     PORT_SetPinMux(PORTB, 18U, kPORT_MuxAsGpio); //CS
     PORT_SetPinMux(PORTB, 2U, kPORT_MuxAsGpio); //DOUT SO --  MI
     PORT_SetPinMux(PORTB, 3U, kPORT_MuxAsGpio);  //CLK
     PORT_SetPinMux(PORTB, 1U, kPORT_MuxAsGpio);  //DIN  SI --  MO
}
