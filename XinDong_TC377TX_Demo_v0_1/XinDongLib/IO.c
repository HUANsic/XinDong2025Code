#include "IO.h"

#include "Interrupts.h"
#include <IfxGtm_PinMap.h>
#include <IfxGtm_Tim_In.h>

IfxGtm_Tim_In reedDriver;

void Reed_Init(void) {
	/*
	 * 	Here I'm using TIM because:
	 * 		(1) ERU doesn't support filtering
	 * 		(2) There are limited (8) ERU outputs, I want to reserve them for future use
	 */
	IfxGtm_Tim_In_Config config;

	IfxGtm_Tim_In_initConfig(&config, &MODULE_GTM);
	config.timIndex = IfxGtm_TIM0_2_P15_8_IN.tim;
	config.channelIndex = IfxGtm_TIM0_2_P15_8_IN.channel;
	config.isrProvider = IfxSrc_Tos_cpu0;
	config.isrPriority = IO_REED_PRIORITY;
	config.capture.irqOnNewVal = TRUE;		// interrupt on falling edge!!!
	config.capture.activeEdge = IfxGtm_Tim_In_ActiveEdge_falling;
	config.filter.inputPin = &IfxGtm_TIM0_2_P15_8_IN;
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
