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

    /* Affects PORTC_PCR4 register *///输入
    port_pin_config_t config;
    config.pullSelect = kPORT_PullUp;
    config.mux = kPORT_MuxAsGpio;
    PORT_SetPinConfig(PORTC, 4U, &config); //PTC4设置为上拉

   // port_pin_config_t config1;
    //    config1.pullSelect = kPORT_PullDisable;
     //   config1.mux = kPORT_MuxAsGpio;

    /* LED PIN_MUX Configuration */   	//输出
     PORT_SetPinMux(PORTC, 1U, kPORT_MuxAsGpio);
     PORT_SetPinMux(PORTA, 19U, kPORT_MuxAsGpio);
     PORT_SetPinMux(PORTB, 0U, kPORT_MuxAsGpio);

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
}
