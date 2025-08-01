/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"

#include "XinDongLib/XinDong_Config.h"
#include "XinDongLib/Interrupts.h"
#include "XinDongLib/Intercore.h"
#include "XinDongLib/Time.h"
#include "XinDongLib/IO.h"

#include "XinDongLib/Time.h"
#include "XinDongLib/IO.h"

IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;

void core0_main(void) {
    IfxCpu_enableInterrupts();
	/* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
	 * Enable the watchdogs and service them periodically if it is required
	 */
	IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
	IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

	/* Wait for CPU sync event */
	IfxCpu_emitEvent(&g_cpuSyncEvent);
	IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

	// initialize timer
	Time_Start();
	Interrupts_Init();

	// initialize LEDs and DIP switches, and the input for detecting battery balancing connector
	IO_Init();

	// if battery balancing connector not connected

	// then set one of the LED and wait until it is connected

	// allow initialization of other cores
	Intercore_AllowInitialize();

	// initialize other modules

	// wait for other cores to finish initialization
	Intercore_CPU0_Ready();

	while (Intercore_ReadyToGo() == 0)
		;

	while (1) {
		// some code to indicate that the core is not dead
		IO_LED_Toggle(1);
		Time_Delay_us(100000);
	}
}

/* list out all ISR for CPU0 */
