#include "Bluetooth.h"
#include "IfxAsclin_Asc.h"

IfxAsclin_Asc uartHandle_ble;

void BLE_Tx_ISR(void) {
	IfxAsclin_Asc_isrTransmit(&uartHandle_ble);
}

void BLE_Rx_ISR(void) {
	uint8 buff;
	sint16 count = 1;
	IfxAsclin_Asc_isrReceive(&uartHandle_ble);
	IfxAsclin_Asc_read(&uartHandle_ble, &buff, &count, 100);
	BLE_Received(buff);
}

void BLE_Err_ISR(void) {
	IfxAsclin_Asc_isrError(&uartHandle_ble);
}

__weak__ void BLE_Received(uint8 buff) {
	(void) buff;
}
