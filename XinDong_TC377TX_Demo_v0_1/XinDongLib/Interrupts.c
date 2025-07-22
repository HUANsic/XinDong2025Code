#include "Interrupts.h"

#include "IfxGtm_Tim_In.h"
#include "IfxCpu_Irq.h"

// those must be defined before the enum is parsed in IfxSrc_cfg.h
/*
 typedef enum {
 IfxSrc_Tos_cpu0 = 0,  // CPU0 interrupt service provider, which handles the interrupt service request.
 IfxSrc_Tos_dma  = 1,  // DMA interrupt service provider, which handles the interrupt service request.
 IfxSrc_Tos_cpu1 = 2,  // CPU1 interrupt service provider, which handles the interrupt service request.
 IfxSrc_Tos_cpu2 = 3   // CPU2 interrupt service provider, which handles the interrupt service request.
 } IfxSrc_Tos;
 */
#ifndef	IfxSrc_Tos_cpu0
#define	IfxSrc_Tos_cpu0		0
#endif
#ifndef	IfxSrc_Tos_dma
#define IfxSrc_Tos_dma		1
#endif
#ifndef IfxSrc_Tos_cpu1
#define IfxSrc_Tos_cpu1		2
#endif
#ifndef IfxSrc_Tos_cpu2
#define IfxSrc_Tos_cpu2		3
#endif

IfxGtm_Tim_In timDriver_10ms, timDriver_100ms, timDriver_1s, timDriver_pid;
IfxGtm_Tim_In timDriver_user0, timDriver_user1, timDriver_user2, timDriver_user3;

// encoder overflow
IFX_INTERRUPT(ENCODER_OVERFLOW_ISR, ENCODER_OVERFLOW_TOS, ENCODER_OVERFLOW_PRIORITY) {
	Encoder_Overflow_ISR();
}

IFX_INTERRUPT(TIME_PERIODIC_ISR, TIME_PERIODIC_TOS, TIME_PERIODIC_PRIORITY) {
	Time_Periodic_ISR();
}

IFX_INTERRUPT(EXTI_REED_ISR, IO_REED_TOS, IO_REED_PRIORITY) {
	IO_Reed_ISR();
}

IFX_INTERRUPT(SERIAL_TX_ISR, SERIAL_TOS, SERIAL_TX_PRIORITY) {
	Serial_Tx_ISR();
}

IFX_INTERRUPT(SERIAL_RX_ISR, SERIAL_TOS, SERIAL_RX_PRIORITY) {
	Serial_Rx_ISR();
}

IFX_INTERRUPT(SERIAL_ERR_ISR, SERIAL_TOS, SERIAL_ERR_PRIORITY) {
	Serial_Err_ISR();
}

IFX_INTERRUPT(BLE_TX_ISR, BLE_TOS, BLE_TX_PRIORITY) {
	BLE_Tx_ISR();
}

IFX_INTERRUPT(BLE_RX_ISR, BLE_TOS, BLE_RX_PRIORITY) {
	BLE_Rx_ISR();
}

IFX_INTERRUPT(BLE_ERR_ISR, BLE_TOS, BLE_ERR_PRIORITY) {
	BLE_Err_ISR();
}

IFX_INTERRUPT(ULTRASONIC_PULSEIN_ISR, ULTRASONIC_PULSEIN_TOS, ULTRASONIC_PULSEIN_PRIORITY) {
	Ultrasonic_PulseIn_ISR();
}

IFX_INTERRUPT(EXTI_PCLK_ISR, CAMERA_PCLK_TOS, CAMERA_PCLK_PRIORITY) {
	IO_Pclk_ISR();
}

IFX_INTERRUPT(EXTI_VSYNC_ISR, CAMERA_VSYNC_TOS, CAMERA_VSYNC_PRIORITY) {
	IO_Vsync_ISR();
}

IFX_INTERRUPT(EXTI_HSYNC_ISR, CAMERA_HSYNC_TOS, CAMERA_HSYNC_PRIORITY) {
	IO_Hsync_ISR();
}

IFX_INTERRUPT(SWINT_1S_PERIODIC_ISR, SWINT_1S_PERIODIC_TOS, SWINT_1S_PERIODIC_PRIORITY) {
	IfxGtm_Tim_In_update(&timDriver_1s);
	Periodic_1s_ISR();
}

IFX_INTERRUPT(SWINT_100MS_PERIODIC_ISR, SWINT_100MS_PERIODIC_TOS, SWINT_100MS_PERIODIC_PRIORITY) {
	IfxGtm_Tim_In_update(&timDriver_100ms);
	Periodic_100ms_ISR();
}

IFX_INTERRUPT(SWINT_10MS_PERIODIC_ISR, SWINT_10MS_PERIODIC_TOS, SWINT_10MS_PERIODIC_PRIORITY) {
	IfxGtm_Tim_In_update(&timDriver_10ms);
	Periodic_10ms_ISR();
}

IFX_INTERRUPT(SWINT_PID_PERIODIC_ISR, SWINT_PID_PERIODIC_TOS, SWINT_PID_PERIODIC_PRIORITY) {
	IfxGtm_Tim_In_update(&timDriver_pid);
	Periodic_PID_ISR();
}

IFX_INTERRUPT(SWINT_USER0_ISR, SWINT_USER0_TOS, SWINT_USER0_PRIORITY) {
	IfxGtm_Tim_In_update(&timDriver_user0);
	SWINT_User0_ISR();
}

IFX_INTERRUPT(SWINT_USER1_ISR, SWINT_USER1_TOS, SWINT_USER1_PRIORITY) {
	IfxGtm_Tim_In_update(&timDriver_user1);
	SWINT_User1_ISR();
}

IFX_INTERRUPT(SWINT_USER2_ISR, SWINT_USER2_TOS, SWINT_USER2_PRIORITY) {
	IfxGtm_Tim_In_update(&timDriver_user2);
	SWINT_User2_ISR();
}

IFX_INTERRUPT(SWINT_USER3_ISR, SWINT_USER3_TOS, SWINT_USER3_PRIORITY) {
	IfxGtm_Tim_In_update(&timDriver_user3);
	SWINT_User3_ISR();
}

// and they must be undefined to avoid conflicts
#undef	IfxSrc_Tos_cpu0
#undef	IfxSrc_Tos_dma
#undef	IfxSrc_Tos_cpu1
#undef	IfxSrc_Tos_cpu2

void Interrupts_Init(void) {
	IfxGtm_Tim_In_Config config;

	IfxGtm_Tim_In_initConfig(&config, &MODULE_GTM);

	config.timIndex = IfxGtm_Tim_2;
	config.channelIndex = IfxGtm_Tim_Ch_0;
	config.isrProvider = SWINT_10MS_PERIODIC_TOS;
	config.isrPriority = SWINT_10MS_PERIODIC_PRIORITY;
	IfxGtm_Tim_In_init(&timDriver_10ms, &config);

	config.timIndex = IfxGtm_Tim_2;
	config.channelIndex = IfxGtm_Tim_Ch_1;
	config.isrProvider = SWINT_100MS_PERIODIC_TOS;
	config.isrPriority = SWINT_100MS_PERIODIC_PRIORITY;
	IfxGtm_Tim_In_init(&timDriver_100ms, &config);

	config.timIndex = IfxGtm_Tim_2;
	config.channelIndex = IfxGtm_Tim_Ch_2;
	config.isrProvider = SWINT_1S_PERIODIC_TOS;
	config.isrPriority = SWINT_1S_PERIODIC_PRIORITY;
	IfxGtm_Tim_In_init(&timDriver_1s, &config);

	config.timIndex = IfxGtm_Tim_2;
	config.channelIndex = IfxGtm_Tim_Ch_3;
	config.isrProvider = SWINT_PID_PERIODIC_TOS;
	config.isrPriority = SWINT_PID_PERIODIC_PRIORITY;
	IfxGtm_Tim_In_init(&timDriver_pid, &config);

	config.timIndex = IfxGtm_Tim_2;
	config.channelIndex = IfxGtm_Tim_Ch_4;
	config.isrProvider = SWINT_USER0_TOS;
	config.isrPriority = SWINT_USER0_PRIORITY;
	IfxGtm_Tim_In_init(&timDriver_user0, &config);

	config.timIndex = IfxGtm_Tim_2;
	config.channelIndex = IfxGtm_Tim_Ch_5;
	config.isrProvider = SWINT_USER1_TOS;
	config.isrPriority = SWINT_USER1_PRIORITY;
	IfxGtm_Tim_In_init(&timDriver_user1, &config);

	config.timIndex = IfxGtm_Tim_2;
	config.channelIndex = IfxGtm_Tim_Ch_6;
	config.isrProvider = SWINT_USER2_TOS;
	config.isrPriority = SWINT_USER2_PRIORITY;
	IfxGtm_Tim_In_init(&timDriver_user2, &config);

	config.timIndex = IfxGtm_Tim_2;
	config.channelIndex = IfxGtm_Tim_Ch_7;
	config.isrProvider = SWINT_USER3_TOS;
	config.isrPriority = SWINT_USER3_PRIORITY;
	IfxGtm_Tim_In_init(&timDriver_user3, &config);

	IfxGtm_Tim_Ch_setChannelNotification(timDriver_10ms.channel, 1, 0, 0, 0);
	IfxGtm_Tim_Ch_setChannelNotification(timDriver_1s.channel, 1, 0, 0, 0);
	IfxGtm_Tim_Ch_setChannelNotification(timDriver_100ms.channel, 1, 0, 0, 0);
	IfxGtm_Tim_Ch_setChannelNotification(timDriver_pid.channel, 1, 0, 0, 0);
	IfxGtm_Tim_Ch_setChannelNotification(timDriver_user0.channel, 1, 0, 0, 0);
	IfxGtm_Tim_Ch_setChannelNotification(timDriver_user1.channel, 1, 0, 0, 0);
	IfxGtm_Tim_Ch_setChannelNotification(timDriver_user2.channel, 1, 0, 0, 0);
	IfxGtm_Tim_Ch_setChannelNotification(timDriver_user3.channel, 1, 0, 0, 0);
}

void SWINT_Trigger_10ms(void) {
	timDriver_10ms.channel->IRQ.FORCINT.U = 0x0001;		// force trigger
}

void SWINT_Trigger_100ms(void) {
	timDriver_100ms.channel->IRQ.FORCINT.U = 0x0001;		// force trigger
}

void SWINT_Trigger_1s(void) {
	timDriver_1s.channel->IRQ.FORCINT.U = 0x0001;			// force trigger
}

void SWINT_Trigger_pid(void) {
	timDriver_pid.channel->IRQ.FORCINT.U = 0x0001;		// force trigger
}

void SWINT_Trigger_user0(void) {
	timDriver_user0.channel->IRQ.FORCINT.U = 0x0001;		// force trigger
}

void SWINT_Trigger_user1(void) {
	timDriver_user1.channel->IRQ.FORCINT.U = 0x0001;		// force trigger
}

void SWINT_Trigger_user2(void) {
	timDriver_user2.channel->IRQ.FORCINT.U = 0x0001;		// force trigger
}

void SWINT_Trigger_user3(void) {
	timDriver_user3.channel->IRQ.FORCINT.U = 0x0001;		// force trigger
}

__weak__ void Encoder_Overflow_ISR(void) {
	;		// should be defined in Encoder.c
}

__weak__ void Time_Periodic_ISR(void) {
	;		// defined in Time.c
}

__weak__ void IO_Reed_ISR(void) {
	;		// defined in IO.c
}

__weak__ void Serial_Tx_ISR(void) {
	;		// defined in Serial.c
}

__weak__ void Serial_Rx_ISR(void) {
	;		// defined in Serial.c
}

__weak__ void Serial_Err_ISR(void) {
	;		// defined in Serial.c
}

__weak__ void BLE_Tx_ISR(void) {
	;		// defined in Bluetooth.c
}

__weak__ void BLE_Rx_ISR(void) {
	;		// defined in Bluetooth.c
}

__weak__ void BLE_Err_ISR(void) {
	;		// defined in Bluetooth.c
}

__weak__ void Ultrasonic_PulseIn_ISR(void) {
	;		// defined in Ultrasonic.c
}

__weak__ void IO_Pclk_ISR(void) {
	;		// defined in Camera.c if using software flow control
}

__weak__ void IO_Vsync_ISR(void) {
	;		// defined in Camera.c if using software flow control
}

__weak__ void IO_Hsync_ISR(void) {
	;		// defined in Camera.c if using software flow control
}

__weak__ void Periodic_1s_ISR(void) {
	;
}

__weak__ void Periodic_100ms_ISR(void) {
	;
}

__weak__ void Periodic_10ms_ISR(void) {
	;
}

__weak__ void Periodic_PID_ISR(void) {
	;
}

__weak__ void SWINT_User0_ISR(void) {
	;
}

__weak__ void SWINT_User1_ISR(void) {
	;
}

__weak__ void SWINT_User2_ISR(void) {
	;
}

__weak__ void SWINT_User3_ISR(void) {
	;
}
