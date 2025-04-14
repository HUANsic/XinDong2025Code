#include "Interrupts.h"

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

IFX_INTERRUPT(SERIAL_TX_ISR, SERIAL_TX_TOS, SERIAL_TX_PRIORITY) {
	Serial_Tx_ISR();
}

IFX_INTERRUPT(SERIAL_RX_ISR, SERIAL_RX_TOS, SERIAL_RX_PRIORITY) {
	Serial_Rx_ISR();
}

IFX_INTERRUPT(SERIAL_ERR_ISR, SERIAL_ERR_TOS, SERIAL_ERR_PRIORITY) {
	Serial_Err_ISR();
}

IFX_INTERRUPT(BLE_TX_ISR, BLE_TX_TOS, BLE_TX_PRIORITY) {
	BLE_Tx_ISR();
}

IFX_INTERRUPT(BLE_RX_ISR, BLE_RX_TOS, BLE_RX_PRIORITY) {
	BLE_Rx_ISR();
}

IFX_INTERRUPT(BLE_ERR_ISR, BLE_ERR_TOS, BLE_ERR_PRIORITY) {
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

// and they must be undefined to avoid conflicts
#undef	IfxSrc_Tos_cpu0
#undef	IfxSrc_Tos_dma
#undef IfxSrc_Tos_cpu1
#undef IfxSrc_Tos_cpu2

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
