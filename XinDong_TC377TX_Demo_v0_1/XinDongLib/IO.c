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

void IO_Reed_ISR() {
	IfxGtm_Tim_In_update(&reedDriver);
	if (reedDriver.newData) {
		Reed_Triggered();
	}
}
