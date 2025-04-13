#include "Interrupts.h"

// encoder overflow
IFX_INTERRUPT(ENCODER_OVERFLOW_ISR, 0, ENCODER_OVERFLOW_PRIORITY) {
	Encoder_Overflow_ISR();
}

IFX_INTERRUPT(TIME_PERIODIC_ISR, 0, TIME_PERIODIC_PRIORITY) {
	Time_Periodic_ISR();
}

IFX_INTERRUPT(EXTI_REED_ISR, 0, IO_REED_PRIORITY) {
	IO_Reed_ISR();
}

IFX_INTERRUPT(SERIAL_TX_ISR, 0, SERIAL_TX_PRIORITY) {
	Serial_Tx_ISR();
}

IFX_INTERRUPT(SERIAL_RX_ISR, 0, SERIAL_RX_PRIORITY) {
	Serial_Rx_ISR();
}

IFX_INTERRUPT(SERIAL_ERR_ISR, 0, SERIAL_ERR_PRIORITY) {
	Serial_Err_ISR();
}

IFX_INTERRUPT(BLE_TX_ISR, 0, BLE_TX_PRIORITY) {
	BLE_Tx_ISR();
}

IFX_INTERRUPT(BLE_RX_ISR, 0, BLE_RX_PRIORITY) {
	BLE_Rx_ISR();
}

IFX_INTERRUPT(BLE_ERR_ISR, 0, BLE_ERR_PRIORITY) {
	BLE_Err_ISR();
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
