#include "IO.h"

#include "Interrupts.h"
#include <IfxGtm_PinMap.h>
#include <IfxGtm_Tim_In.h>

IfxGtm_Tim_In reedDriver;

//	reference code: TC264_XinDong_Demo_v51/Src/Utilities.c

void Reed_Init(void) {
	/*
	 * 	Here I'm using TIM because:
	 * 		(1) ERU doesn't support filtering
	 * 		(2) There are limited (8) ERU outputs, I want to reserve them for future use
	 */
	IfxGtm_Tim_In_Config config;

	IfxGtm_Tim_In_initConfig(&config, &MODULE_GTM);
	config.timIndex = REED_TIM_PIN.tim;
	config.channelIndex = REED_TIM_PIN.channel;
	config.isrProvider = IfxSrc_Tos_cpu0;
	config.isrPriority = IO_REED_PRIORITY;
	config.capture.irqOnNewVal = TRUE;		// interrupt on falling edge!!!
	config.capture.activeEdge = IfxGtm_Tim_In_ActiveEdge_falling;
	config.filter.inputPin = &REED_TIM_PIN;
	config.filter.risingEdgeMode = IfxGtm_Tim_In_ConfigFilterMode_individualDeglitchTimeHold;
	config.filter.fallingEdgeMode = IfxGtm_Tim_In_ConfigFilterMode_individualDeglitchTimeHold;
	config.filter.risingEdgeFilterTime = 0.003;		// de-glitch for 3ms
	config.filter.fallingEdgeFilterTime = 0.003;
	config.mode = IfxGtm_Tim_Mode_inputEvent;

	IfxGtm_Tim_In_init(&reedDriver, &config);
}

__weak__ void Reed_Triggered(void) {
	;		// defined in USER file
}
//----------------------------------------------------------------LED--------------------------------------------------------
void IO_LED_1_init(void)
{
    IfxPort_setPinMode(IO_LED1_PORT, IO_LED1_PIN, IfxPort_Mode_outputPushPullGeneral);
}

void IO_LED_1_on(void)
{
    IfxPort_setPinHigh(IO_LED1_PORT, IO_LED1_PIN);
}

void IO_LED_1_off(void)
{
    IfxPort_setPinLow(IO_LED1_PORT, IO_LED1_PIN);
}

void IO_LED_1_toggle(void)
{
    IfxPort_togglePin(IO_LED1_PORT, IO_LED1_PIN);
}

void IO_LED_2_init(void)
{
    IfxPort_setPinMode(IO_LED2_PORT, IO_LED2_PIN, IfxPort_Mode_outputPushPullGeneral);
}

void IO_LED_2_on(void)
{
    IfxPort_setPinHigh(IO_LED2_PORT, IO_LED2_PIN);
}

void IO_LED_2_off(void)
{
    IfxPort_setPinLow(IO_LED2_PORT, IO_LED2_PIN);
}

void IO_LED_2_toggle(void)
{
    IfxPort_togglePin(IO_LED2_PORT, IO_LED2_PIN);
}

void IO_LED_3_init(void)
{
    IfxPort_setPinMode(IO_LED3_PORT, IO_LED3_PIN, IfxPort_Mode_outputPushPullGeneral);
}

void IO_LED_3_on(void)
{
    IfxPort_setPinHigh(IO_LED3_PORT, IO_LED3_PIN);
}

void IO_LED_3_off(void)
{
    IfxPort_setPinLow(IO_LED3_PORT, IO_LED3_PIN);
}

void IO_LED_3_toggle(void)
{
    IfxPort_togglePin(IO_LED3_PORT, IO_LED3_PIN);
}

void IO_LED_4_init(void)
{
    IfxPort_setPinMode(IO_LED4_PORT, IO_LED4_PIN, IfxPort_Mode_outputPushPullGeneral);
}

void IO_LED_4_on(void)
{
    IfxPort_setPinHigh(IO_LED4_PORT, IO_LED4_PIN);
}

void IO_LED_4_off(void)
{
    IfxPort_setPinLow(IO_LED4_PORT, IO_LED4_PIN);
}

void IO_LED_4_toggle(void)
{
    IfxPort_togglePin(IO_LED4_PORT, IO_LED4_PIN);
}

//----------------------------------------------------------------SWITCH-------------------------------------------------------

void IO_SW1_1_init(void)
{
    IfxPort_setPinMode(&MODULE_P20, 11, IfxPort_Mode_inputPullUp);
}

boolean IO_SW1_1_read(void)
{
    return IfxPort_getPinState(&MODULE_P20, 11);
}

void IO_SW1_2_init(void)
{
    IfxPort_setPinMode(&MODULE_P20, 11, IfxPort_Mode_inputPullUp);
}

boolean IO_SW1_2_read(void)
{
    return IfxPort_getPinState(&MODULE_P20, 11);
}

void IO_SW1_3_init(void)
{
    IfxPort_setPinMode(&MODULE_P20, 11, IfxPort_Mode_inputPullUp);
}

boolean IO_SW1_3_read(void)
{
    return IfxPort_getPinState(&MODULE_P20, 11);
}

void IO_SW1_4_init(void)
{
    IfxPort_setPinMode(&MODULE_P20, 11, IfxPort_Mode_inputPullUp);
}

boolean IO_SW1_4_read(void)
{
    return IfxPort_getPinState(&MODULE_P20, 11);
}


void IO_Reed_ISR() {
	IfxGtm_Tim_In_update(&reedDriver);
	if (reedDriver.newData) {
		Reed_Triggered();
	}
}
