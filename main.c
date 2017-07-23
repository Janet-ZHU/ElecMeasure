/**
 * This is template for main module created by New Kinetis SDK 2.x Project Wizard. Enjoy!
 **/

#include "fsl_debug_console.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_common.h"
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include  "ADE7758.h"
#include  "LCD.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
//#define BOARD_LED_GPIO BOARD_LED_RED_GPIO
//#define BOARD_LED_GPIO_PIN BOARD_LED_RED_GPIO_PIN
#define BOARD_LED_GPIO BOARD_LED_GREEN_GPIO
#define BOARD_LED_GPIO_PIN BOARD_LED_GREEN_GPIO_PIN

#define BOARD_SW_GPIO BOARD_SW3_GPIO
#define BOARD_SW_PORT BOARD_SW3_PORT
#define BOARD_SW_GPIO_PIN BOARD_SW3_GPIO_PIN
#define BOARD_SW_IRQ BOARD_SW3_IRQ
#define BOARD_SW_IRQ_HANDLER BOARD_SW3_IRQ_HANDLER
#define BOARD_SW_NAME BOARD_SW3_NAME

unsigned int i=0;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Whether the SW button is pressed */
volatile bool g_ButtonPress = false;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Interrupt service fuction of switch.
 *
 * This function toggles the LED
 */
void BOARD_SW_IRQ_HANDLER(void)
{
    /* Clear external interrupt flag. */
    GPIO_ClearPinsInterruptFlags(BOARD_SW_GPIO, 1U << BOARD_SW_GPIO_PIN);//1右移四位0x10
    /* Change state of button. */
    g_ButtonPress = true;
    /* Toggle LED. */
    GPIO_TogglePinsOutput(BOARD_LED_GPIO, 1U << BOARD_LED_GPIO_PIN);
   // GPIO_TogglePinsOutput(BOARD_LED3_GPIO, 1U << BOARD_LED3_GPIO_PIN);
    GPIO_WritePinOutput(GPIOB, 0U, 0);

}

/*!
 * @brief Main function
 */
int main(void)
{
    //配置结构体 设置输入，输出（输入/输出，输出1或者0），当在输入状态下，输出没有效果
	/* Define the init structure for the input or output pin */
    gpio_pin_config_t sw_config   =   { kGPIO_DigitalInput,  0, };
    gpio_pin_config_t led_config  =   { kGPIO_DigitalOutput, 0, };
    gpio_pin_config_t led3_config =   { kGPIO_DigitalOutput, 1, };

    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Print a note to terminal. */
    PRINTF("\r\n GPIO Driver example\r\n");
    PRINTF("\r\n Press %s to turn on/off a LED \r\n", BOARD_SW_NAME);

    /* Init input switch GPIO. */
    PORT_SetPinInterruptConfig(BOARD_SW_PORT, BOARD_SW_GPIO_PIN, kPORT_InterruptFallingEdge);
    EnableIRQ(BOARD_SW_IRQ);
    GPIO_PinInit(BOARD_SW_GPIO, BOARD_SW_GPIO_PIN, &sw_config);

    /* Init output LED GPIO. */
    GPIO_PinInit(BOARD_LED_GPIO, BOARD_LED_GPIO_PIN, &led_config);
    GPIO_PinInit(BOARD_LED3_GPIO, BOARD_LED3_GPIO_PIN, &led3_config);
    ADE7758_Init();

    while (1)
    {
    	for( i = 0; i <= 255; i = i + 4 )
    	{
    		current_unbalanceSimulate[i] = current_unbalanceSimulate[i] - i/3;
    		show_curve(current_unbalanceSimulate[i]);
    	}

    	//show_curve(current_unbalance);
       if (g_ButtonPress)
        {
			   /*show1=read8_ADE7758(0x16);//0X1C
				show2=read8_ADE7758(0x17);//0X78
				PRINTF(" %02X", show1); PRINTF(" %02X", show2);

				       PUTCHAR(0xff);PUTCHAR(0xff); PUTCHAR(0xff);
				       PRINTF("t7.txt=\"211.7V\"");
				       PUTCHAR(0xff);PUTCHAR(0xff); PUTCHAR(0xff);

				       PRINTF("t8.txt=");
				       PUTCHAR(0x22);
				       PRINTF(" %02X", show1);
				       PUTCHAR(0x22);
				       PUTCHAR(0xff);PUTCHAR(0xff); PUTCHAR(0xff);

					   PRINTF("t9.txt=");
					   PUTCHAR(0x22);
					   PRINTF(" %02d", show2);
					   PUTCHAR(0x22);
					   PUTCHAR(0xff);PUTCHAR(0xff); PUTCHAR(0xff);*/
    	    V_RMS();
        	PRINTF("\r\n");
            g_ButtonPress = false;
        }
    }
}
